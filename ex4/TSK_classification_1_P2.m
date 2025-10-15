clc;
clearvars;
close all;
%%rng(0)

data = load('haberman.data');
X = data(:,1:end-1);
Y = data(:,end);

% --- split (ό,τι έχεις ήδη) ---
preproc = 1;
fq_tol = 0.01;
[trnData,valData,chkData] = train_test_split(data,preproc,fq_tol);

Xtr  = trnData(:,1:end-1);
Ytr  = trnData(:,end);
Xval = valData(:,1:end-1);
Yval = valData(:,end);
Xchk = chkData(:,1:end-1);
Ychk = chkData(:,end);

%% class frequencies the same between each set
fprintf("---------INITIAL DATA---------------\n")
frequency = get_frequency(Y);
fprintf('Class 1 frequency: %f\n',frequency(1));
fprintf('Class 2 frequency: %f\n',frequency(2));
fprintf("---------TRAINING DATA---------------\n")
frequency = get_frequency(Ytr);
fprintf('Class 1 frequency: %f\n',frequency(1));
fprintf('Class 2 frequency: %f\n',frequency(2));
fprintf("---------VALIDATION DATA---------------\n")
frequency = get_frequency(Yval);
fprintf('Class 1 frequency: %f\n',frequency(1));
fprintf('Class 2 frequency: %f\n',frequency(2));
fprintf("---------CHECKING DATA---------------\n")
frequency = get_frequency(Ychk);
fprintf('Class 1 frequency: %f\n',frequency(1));
fprintf('Class 2 frequency: %f\n',frequency(2));

%% === SC Class-Independent (unsupervised clustering on X only) ===
% Κάνουμε subtractive clustering ΜΟΝΟ στα χαρακτηριστικά του training,
% μετά “βαφτίζουμε” κάθε κανόνα σε κλάση (1/2) με majority vote,
% εκπαιδεύουμε ANFIS (Sugeno-0) και αξιολογούμε σε chkData.

radiusVec = [0.30 0.70];   % διάλεξε δύο ακραίες ακτίνες → πολύ διαφορετικός #rules

for l = 1:numel(radiusVec)
    r = radiusVec(l);

    % 1) Unsupervised subtractive clustering στο Xtr
    [C, sigma] = subclust(Xtr, r);     % C: (#rules x p), sigma: 1 x p
    num_rules  = size(C,1);
    p          = size(Xtr,2);

    if num_rules < 1
        warning('Με r=%.3f δεν βρέθηκαν clusters. Δοκίμασε μικρότερη ακτίνα.', r);
        continue;
    end

    % 2) Χτίζουμε Sugeno-0 (constant output) FIS: 1 κανόνας ανά cluster
    fis = newfis(sprintf('TSK_SC_IND_r%.3f', r), 'sugeno');

    % Είσοδοι με min–max από το training (αν είσαι ήδη [0,1], βάλε [0 1])
    for i = 1:p
        rng_i = [min(Xtr(:,i)) max(Xtr(:,i))];
        if ~isfinite(rng_i(1)) || ~isfinite(rng_i(2)) || rng_i(1) == rng_i(2)
            rng_i = [min(X(:,i)) max(X(:,i))] + [-1 1]*eps; % fallback
        end
        fis = addvar(fis,'input',sprintf('in%d',i),rng_i);
    end
    fis = addvar(fis,'output','out1',[1 2]);  % κλάσεις 1 ή 2

    % Για ΚΑΘΕ είσοδο, ορίζουμε num_rules Gaussian MFs (ευθυγραμμισμένα ανά rule)
    for i = 1:p
        for j = 1:num_rules
            fis = addmf(fis,'input',i,sprintf('r%d',j),'gaussmf',[sigma(i) C(j,i)]);
        end
    end

    % 3) “Βάφτιση” κανόνων σε κλάση με majority vote από τα training samples
    % Firing strengths ανά rule
    Phi = ones(size(Xtr,1), num_rules);
    for j = 1:num_rules
        for i = 1:p
            Phi(:,j) = Phi(:,j) .* gaussmf(Xtr(:,i), [sigma(i) C(j,i)]);
        end
    end
    [~, assign] = max(Phi, [], 2);  % κάθε δείγμα → rule με μέγιστη firing

    % Μετράμε πλειοψηφική κλάση ανά rule (υποθέτουμε labels {1,2})
    counts = accumarray([assign, Ytr], 1, [num_rules, 2], @sum, 0);
    [~, majClass] = max(counts, [], 2);   % majClass(j) ∈ {1,2}

    % 4) Output MFs (constant = 1 ή 2) με την πλειοψηφική ετικέτα ανά rule
    for j = 1:num_rules
        fis = addmf(fis,'output',1,sprintf('out_rule_%d',j),'constant', majClass(j));
    end

    % 5) Κανόνες: για rule j, παίρνουμε το j-οστό MF σε ΚΑΘΕ είσοδο
    % Rule format: [in1 ... inP  out1  weight  AND/OR]
    ruleList = zeros(num_rules, p + 2 + 1);
    for j = 1:num_rules
        ruleList(j,1:p) = j;        % antecedents: MF #j σε κάθε είσοδο
        ruleList(j,p+1) = j;        % consequent: output MF #j (constant με majClass)
        ruleList(j,p+2) = 1;        % weight
        ruleList(j,p+3) = 1;        % AND
    end
    fis = addrule(fis, ruleList);

    % 6) Εκπαίδευση ANFIS (hybrid). Validation = chkData (όπως σε ζητούμενο).
    [trnFis,trnError,~,valFis,valError] = anfis([Xtr Ytr], fis, ...
        [100 0 0.01 0.9 1.1], [], chkData);

    % 7) Αξιολόγηση στο checking set
    Yhat = round(evalfis(Xchk, valFis));

    % Μετρικές από confusion matrix (rows=true, cols=pred)
    Cmat = confusionmat(Ychk, Yhat);
    OA   = trace(Cmat) / sum(Cmat(:));
    PA   = diag(Cmat) ./ sum(Cmat,2);          % recall (per true class)
    UA   = diag(Cmat) ./ sum(Cmat,1)';         % precision (per predicted class)
    N    = sum(Cmat(:));
    pe   = sum(sum(Cmat,1).*sum(Cmat,2)') / N^2; % expected agreement
    kappa = (OA - pe) / (1 - pe);

    % 8) Plots & reports
    text = sprintf('TSK class-independent (r=%.3f): Learning curves$$$$$$$$$$', r);
    figure('Name',text)
    plot([trnError valError],'LineWidth',2); 
    grid on;
    legend('Training','Validation'); 
    xlabel('# Iterations'); 
    ylabel('Error');
    title(sprintf('TSK class-independent (r=%.3f): Learning curves$$$$$$$$$$', r));

    % Χρησιμοποιώ τη δική σου συνάρτηση για MFs
    figure();
    plotMFsNew(valFis, p);

    fprintf('\n===== Class-Independent TSK (r=%.3f) =====\n', r);
    disp('Confusion matrix (rows=true, cols=pred):'); disp(Cmat);
    fprintf('Rules: %d\n', num_rules);
    fprintf('OA: %.3f | Kappa: %.3f\n', OA, kappa);
    fprintf('Recall (PA): '); fprintf('%.3f ', PA); fprintf('\n');
    fprintf('Prec   (UA): '); fprintf('%.3f ', UA); fprintf('\n');
end

