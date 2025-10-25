clc;
clearvars;
close all;
%%rng(0)

data = load('haberman.data');
X = data(:,1:end-1);
Y = data(:,end);
preproc = 1;
fq_tol = 0.01;
[trnData,valData,chkData]=train_test_split(data,preproc,fq_tol);

Xtr = trnData(:,1:end-1);
Ytr = trnData(:,end);
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
fprintf("---------CHECKING DATA DATA---------------\n")
frequency = get_frequency(Ychk);
fprintf('Class 1 frequency: %f\n',frequency(1));
fprintf('Class 2 frequency: %f\n',frequency(2));
%% SC Class Indepentent
radius_small = 0.22;
options(1) = genfisOptions('SubtractiveClustering', 'ClusterInfluenceRange', radius_small);
radius_big = 0.7;
options(2) = genfisOptions('SubtractiveClustering', 'ClusterInfluenceRange', radius_big);

for i=1:2
    fis = genfis(Xtr,Ytr,options(i));
    nOutMF = numel(fis.Outputs(1).MembershipFunctions);
    C = mean(Ytr);

    for k = 1:nOutMF
        fis.Outputs(1).MembershipFunctions(k).Type = "constant";
        fis.Outputs(1).MembershipFunctions(k).Parameters = C;
    end
    [trn_fis,trn_error,~,val_fis,val_error] = anfis(trnData,fis,[200 0 0.005 0.7 1.05],[0 0 0 0],valData);
    
    Ypred = evalfis(val_fis,Xchk);
    Ypred = max(1, min(2, round(Ypred)));

    text = sprintf('Fuzzy Sets After Training Model %d',i);
    figure('Name',text);
    plotMFsNew(trn_fis,size(Xtr,2));

    text = sprintf('Training Error Vs Validation Error for Model %d',i);
    figure('Name',text);
    plot([trn_error val_error],LineWidth=2);
    grid on;
    xlabel('Epochs');
    ylabel('Error');
    title(text);
    legend('Training Error','Validation Error',location='best');

    %confusion matrix
    [C,labels] = confusionmat(Ychk, Ypred);   % raw counts
    if i==1
        c1 = C;
    else
        c2 = C;
    end
    Accuracy(i) = sum(diag(C)) / sum(C(:));
    %Producer's (Recall) and User's (Precision) per class:
    Recall(i,:) = diag(C) ./ sum(C,2);     % per true class (rows)
    Precision(i,:) = diag(C) ./ sum(C,1)';    % per predicted class (cols)
    kappa(i) = cohenKappa(C);

end

%% Print the results 
fprintf("===========================For Model 1, radius: %.2f==============================\n",radius_small)
fprintf('Error Matrix\n')
fprintf('%d\t%d\t\n', c1);
fprintf("Accuracy: %f\n",Accuracy(1))
fprintf("Recall: %f\n",Recall(1,:))
fprintf("Precision: %f\n",Precision(1,:))
fprintf("Kappa: %f",kappa(1))

fprintf("\n\n===========================For Model 2, radius: %.2f=================================\n",radius_big)
fprintf('Error Matrix\n')
fprintf('%d\t%d\t\n', c2);
fprintf("Accuracy: %f\n",Accuracy(2))
fprintf("Recall: %f\n",Recall(2,:))
fprintf("Precision: %f\n",Precision(2,:))
fprintf("Kappa: %f\n\n",kappa(2))

