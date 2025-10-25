clc;
clearvars;
close all;
%%rng(0)

data = load('haberman.data');
X = data(:,1:end-1);
Y = data(:,end);

% --- split  ---
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

%%  CLASS-DEPENDENT TSK 
radiusVec = [0.22 0.70];  

for l = 1:numel(radiusVec)
    r = radiusVec(l);
    p = size(Xtr,2);

    % 1) Subtractive clustering ΞΕΧΩΡΙΣΤΑ ανά κλάση
    X1 = Xtr(Ytr==1,:);
    X2 = Xtr(Ytr==2,:);

    [C1, sigma1] = subclust(X1, r);   
    [C2, sigma2] = subclust(X2, r);   
    n1 = size(C1,1);
    n2 = size(C2,1);
    num_rules = n1 + n2;

    fis = newfis(sprintf('TSK_SC_DEP_r%.3f', r), 'sugeno');

    % Είσοδοι: min–max από training
    for i = 1:p
        rng_i = [min(Xtr(:,i)) max(Xtr(:,i))];
        if ~isfinite(rng_i(1)) || ~isfinite(rng_i(2)) || rng_i(1) == rng_i(2)
            rng_i = [min(X(:,i)) max(X(:,i))] + [-1 1]*eps; % fallback
        end
        fis = addvar(fis,'input',sprintf('in%d',i),rng_i);
    end
    fis = addvar(fis,'output','out1',[1 2]);  % κλάσεις 1 ή 2

    for i = 1:p
        % κλάση 1
        for j = 1:n1
            fis = addmf(fis,'input',i,sprintf('c1_r%d',j),'gaussmf',[sigma1(i) C1(j,i)]);
        end
        % κλάση 2
        for j = 1:n2
            fis = addmf(fis,'input',i,sprintf('c2_r%d',j),'gaussmf',[sigma2(i) C2(j,i)]);
        end
    end

    % 4) Output MFs (constant): πρώτα n1 με τιμή 1, μετά n2 με τιμή 2
    for j = 1:n1
        fis = addmf(fis,'output',1,sprintf('out_c1_%d',j),'constant', 1);
    end
    for j = 1:n2
        fis = addmf(fis,'output',1,sprintf('out_c2_%d',j),'constant', 2);
    end

    ruleList = zeros(num_rules, p + 2 + 1);
    for j = 1:num_rules
        ruleList(j,1:p) = j;            % antecedents: MF #j σε κάθε είσοδο
        ruleList(j,p+1) = j;            % consequent: output MF #j (1 για j<=n1, 2 αλλιώς)
        ruleList(j,p+2) = 1;            % weight
        ruleList(j,p+3) = 1;            % AND
    end
    fis = addrule(fis, ruleList);

    % 6) Εκπαίδευση ANFIS 
    [trnFis,trnError,~,valFis,valError] = anfis([Xtr Ytr], fis, [200 0 0.005 0.7 1.05], [0 0 0 0], valData);

    % 7) Αξιολόγηση στο checking set (στρογγυλοποίηση στο {1,2})
    Yhat = round(evalfis(Xchk, valFis));
    Yhat = max(1, min(2, Yhat)); 

    % 8) Μετρικές από confusion matrix (rows=true, cols=pred)
    Cmat = confusionmat(Ychk, Yhat);
    OA   = trace(Cmat) / sum(Cmat(:));
    PA   = diag(Cmat) ./ sum(Cmat,2);          % recall (per true class)
    UA   = diag(Cmat) ./ sum(Cmat,1)';         % precision (per predicted class)
    N    = sum(Cmat(:));
    pe   = sum(sum(Cmat,1).*sum(Cmat,2)') / N^2; % expected agreement
    kappa = (OA - pe) / (1 - pe);

    % 9) Plots & reports
    text = sprintf('TSK class-dependent (r=%.3f): Learning curves', r);
    figure('Name',text)
    plot([trnError valError],'LineWidth',2); 
    grid on;
    legend('Training','Validation','Location','best'); 
    xlabel('# Iterations'); 
    ylabel('Error');
    title(text);

    figure();
    plotMFsNew(valFis, p);
    title(sprintf('TSK class-dependent (r=%.3f): Membership functions', r));

    fprintf('\n===== Class-Dependent TSK (r=%.3f) =====\n', r);
    disp('Confusion matrix (rows=true, cols=pred):'); disp(Cmat);
    fprintf('Rules: %d (class1=%d, class2=%d)\n', num_rules, n1, n2);
    fprintf('OA: %.3f | Kappa: %.3f\n', OA, kappa);
    fprintf('Recall (PA): '); fprintf('%.3f ', PA); fprintf('\n');
    fprintf('Prec   (UA): '); fprintf('%.3f ', UA); fprintf('\n');
end
