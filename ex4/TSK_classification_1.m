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
    % Μετατροπή όλων των output MFs σε 'constant'
    %!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    nOutMF = numel(fis.Outputs(1).MembershipFunctions);
    C = mean(Ytr);

    for k = 1:nOutMF
        fis.Outputs(1).MembershipFunctions(k).Type = "constant";
        fis.Outputs(1).MembershipFunctions(k).Parameters = C;
    end
    %!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    [trn_fis,trn_error,~,val_fis,val_error] = anfis(trnData,fis,[200 0 0.005 0.7 1.05],[],valData);
    
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
    Accuracy(i) = sum(diag(C)) / sum(C(:));
    fprintf("++++++++++++++++++++++++++++++++++++++++++\n")
    fprintf("Accuracy: %f\n",Accuracy(i))
    %Producer's (Recall) and User's (Precision) per class:
    Recall(i,:) = diag(C) ./ sum(C,2);     % per true class (rows)
    fprintf("+++++++++++++++++++++++++++++++++++++++++++\n")
    fprintf("Recall : %f\n",Recall(i,:))
    Precision(i,:) = diag(C) ./ sum(C,1)';    % per predicted class (cols)
    fprintf("++++++++++++++++++++++++++++++++++++++++\n")
    fprintf("Precision: %f\n",Precision(i,:))
    kappa(i) = cohenKappa(C);
    fprintf("+++++++++++++++++++++++++++++++++++\n")
    fprintf("Kappa: %f\n",kappa(i))
end

%% Print the results 
fprintf("===========================For Model 1, radius: %f==============================\n",radius_small)
fprintf("Accuracy: %f\n",Accuracy(1))
fprintf("Recall: %f\n",Recall(1,:))
fprintf("Precision: %f\n",Precision(1,:))
fprintf("Kappa: %f",kappa(1))

fprintf("\n\n===========================For Model 2, radius: %f=================================\n",radius_big)
fprintf("Accuracy: %f\n",Accuracy(2))
fprintf("Recall: %f\n",Recall(2,:))
fprintf("Precision: %f\n",Precision(2,:))
fprintf("Kappa: %f",kappa(2))

%% Class dependent models
% for l=1:2
%     [c1,sig1]=subclust(trnData(trnData(:,end)==1,:),radius(l));
%     [c2,sig2]=subclust(trnData(trnData(:,end)==2,:),radius(l));
%     % The number of rules
%     num_rules=size(c1,1)+size(c2,1);
% 
%     % Build FIS From Scratch
%     fis=newfis('TSK_FIS','sugeno');
% 
%     % Add Input-Output Variables
%     names_in={'in1','in2','in3'};
%     for i=1:size(trnData,2)-1
%         fis=addvar(fis,'input',names_in{i},[0 1]);
%     end
%     fis=addvar(fis,'output','out1',[1 2]);
% 
%     %Add Input Membership Functions
%     for i=1:size(trnData,2)-1
%         for j=1:size(c1,1)
%             name = sprintf('sth%d', j);
%             fis=addmf(fis,'input',i,name,'gaussmf',[sig1(i) c1(j,i)]);
%         end
%         for j=1:size(c2,1)
%              name = sprintf('sth2%d', j);
%             fis=addmf(fis,'input',i,name,'gaussmf',[sig2(i) c2(j,i)]);
%         end
%     end
% 
%     %Add Output Membership Functions
%     params=[ones(1,size(c1,1)) 2*ones(1,size(c2,1))];%[zeros(1,size(c1,1)) ones(1,size(c2,1))];
%     for i=1:num_rules
%         name = sprintf('out%d',i);
%         fis=addmf(fis,'output',1,name,'constant',params(i));
%     end
% 
%     %Add FIS Rule Base
%     ruleList=zeros(num_rules,size(trnData,2));
%     for i=1:size(ruleList,1)
%         ruleList(i,:)=i;
%     end
%     ruleList=[ruleList ones(num_rules,2)];
%     fis=addrule(fis,ruleList);
% 
%     %% Training 
%     [trnFis,trnError,~,valFis,valError]=anfis(trnData,fis,[100 0 0.01 0.9 1.1],[],chkData);
% 
%     %% Evaluate the TSK models
%     Y = round(evalfis(tstData(:,1:end-1),valFis));
% 
%     %% Plot the fuzzy sets after training
%     figure;
%     sgtitle(sprintf('TSK membership functions after training \nNumber of TSK model: %d', (l+2)));
% 
%     [x,mf] = plotmf(trnFis,'input',1);
%     subplot(3,3,1);
%     plot(x,mf);
%     xlabel('Membership Functions for Input 1');
% 
%     [x,mf] = plotmf(trnFis,'input',2);
%     subplot(3,3,2);
%     plot(x,mf);
%     xlabel('Membership Functions for Input 2');
% 
%     [x,mf] = plotmf(trnFis,'input',3);
%     subplot(3,3,3);
%     plot(x,mf);
%     xlabel('Membership Functions for Input 3');
% 
%     %% Plot the learning curves - Training error and Validation error 
%     figure;
%     plot([trnError valError],'LineWidth',2); grid on;
%     xlabel('# of Iterations'); 
%     ylabel('Error');
%     legend('Training Error','Validation Error');
%     title('TSK model 1: Learning Curves');
% 
%     %% Calculate the evaluation parameters for each TSK model   
%     % Error matrix
%     classes = unique(data(:, end));
%     errorMatrix = zeros(length(classes));
% 
%     for j = 1:length(tstData)
%         x = find(classes == Y(j));
%         y = find(classes == data(j, end));
%         errorMatrix(x, y) = errorMatrix(x, y) + 1;
%     end
% 
%     % Overall Accuracy 
%     OA = trace(errorMatrix)/length(tstData);
% 
%     % Producer's Accuracy
%     x_jc = sum(errorMatrix);
% 
%     for k = 1:length(x_jc)
%        PA(k) =  errorMatrix(k,k)/x_jc(k);
%     end
% 
%     % User's Accuracy
%      x_ir = sum(errorMatrix,2);
% 
%     for k = 1:length(x_ir)
%        UA(k) =  errorMatrix(k,k)/x_ir(k);
%     end
% 
%     % K parameter
%     sum_of_prods = 0;
%     for k = 1:length(PA)
%        sum_of_prods = sum_of_prods + PA(k)*UA(k); 
%     end
%     k = (length(tstData) * trace(errorMatrix) - sum_of_prods) / (length(tstData)^2 - sum_of_prods);
% 
%     %% Print the evaluations parameters for each TSK model
%     fprintf('\n=========================================================\n');
%     fprintf('TSK model %d', (l+2));
%     % Print the Error Matrix that is calculated for each TSK model 
%     fprintf('\n\nError Matrix:\n');
%     fprintf('%d\t%d\t\n', errorMatrix);
% 
%     % Print the OA, UA, K parameters
%     fprintf('\nOverall Accuracy(OA): %.2f', OA);
%     fprintf('\nProducer Accuracy(PA): %.2f', PA);
%     fprintf('\nUser Accuracy(UA): %.2f', UA);
%     fprintf('\nK parameter: %.2f', k);
% 
%     fprintf('\n=========================================================\n'); 
% 
%  %% End of for loop   
% end
% 
% 
