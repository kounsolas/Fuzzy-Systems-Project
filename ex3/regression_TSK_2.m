clc;
clearvars;
close all;

data = readmatrix('superconduct.csv');
preproc = 1; % 1-> kanonikopoisi sto [0,1], 2->normalization me mu=0 kai var=1
% trnData for training
% valData for validation - avoid overtraining/overfitting
% chkdata for performance ckecking of the final model
[trnData,chkData,valData] = train_test_split(data,preproc);

Xtr = trnData(:,1:end-1);   
Ytr = trnData(:,end);
Xval  = valData(:,1:end-1);   
Yval  = valData(:,end); 
Xchk = chkData(:,1:end-1);
Ychk = chkData(:,end);

num_features = [5 10 15 20]';
radius = [0.3 0.4 0.5, 0.6]';
num_of_folds = 5;
c = cvpartition(size(trnData,1),"KFold",5);

parameters_val_error = NaN(size(num_features,1), size(radius,1));

for i=1:size(num_features,1)
    %feature selection
    k_features = num_features(i);
    fprintf("Number of features: %d\n",k_features);

    for j=1:size(radius,1)
        r_radius = radius(j);
        fprintf("\tRadius: %.2f\n",r_radius);

        for fold=1:num_of_folds
            fprintf("\t\tFold: %d\n",fold);
            % training and validation fold data
            fold_trData = trnData(c.training(fold)==1,:);
            fold_valData = trnData(c.test(fold)==1,:);

            %feature selection only on fold_trData
            [ranked, ~] = relieff(fold_trData(:,1:end-1), fold_trData(:,end), 10);
            index_features_selected = ranked(1:k_features);
            cols = [index_features_selected size(trnData,2)]; %add the last column which is the target
            
            trData_fold_fs = fold_trData(:,cols);
            valData_fold_fs = fold_valData(:,cols);

            %fis with fold data
            options = genfisOptions('SubtractiveClustering','ClusterInfluenceRange',r_radius);
            fis = genfis(trData_fold_fs(:,1:end-1),trData_fold_fs(:,end),options);
            fis_rules_fold(fold) = numel(fis.Rules);

            %train fis
            [trn_fis, trn_error,~, val_fis, val_error] = anfis(trData_fold_fs,fis,[10 0 0.01 0.9 1.1],[],valData_fold_fs);

            %evaluate the hyperparameters with the min mean val_error
            fold_val_error(fold) = mean(val_error);
        end
        fprintf("Storing fis rules for %d features and %.2f radius\n",k_features,r_radius)
        fis_rules(i,j) = mean(fis_rules_fold);
        fprintf("Storing mean val error for %d features and %.2f radius\n",k_features,r_radius)
        parameters_val_error(i,j) = mean(fold_val_error);
    end
end

%% Plots
figure('Name','Error Curve | Fis Rules');
scatter(fis_rules(:),parameters_val_error(:),'LineWidth',2);
grid on
xlabel("Number of Fis Rules");
ylabel("Error")
title("Error Curve | Fis Rules");

figure('Name','Error Curve | Number of Features');
plot(num_features,mean(parameters_val_error,2))
grid on
xlabel("Number of features");
ylabel("Error");
title('Error Curve | Number of Features');

figure('Name','Hyperparameters Scatter plot');
scatter3(num_features,radius,parameters_val_error)

%% Part 3 - Train the TSK model with the optimal hyperparameters
clc;
for i=1:size(parameters_val_error,1)
    number_of_features = num_features(i);
    for j=1:size(parameters_val_error,2)
        r = radius(j);
        error = parameters_val_error(i,j);
        fprintf("# features: %d\t\tRadius: %.3f\t\tValidation Error: %.4f\n",number_of_features,r,error)
    end
end

min_err = min(min(parameters_val_error));
[best_row,best_col] = find(parameters_val_error == min_err);
best_number_features = num_features(best_row);
best_radius = radius(best_col);
fprintf("\nOptimal # features: %d\nOptimal Radius: %.3f\n",best_number_features,best_radius);


%feature selection only on fold_trData
[ranked, ~] = relieff(Xtr, Ytr, 10);
index_features_selected = ranked(1:best_number_features);
cols = [index_features_selected size(trnData,2)]; %add the last column which is the target

trnData_fs = trnData(:,cols);
valData_fs = valData(:,cols);

%fis with fold data
options = genfisOptions('SubtractiveClustering','ClusterInfluenceRange',best_radius);
fis = genfis(trnData_fs(:,1:end-1),trnData_fs(:,end),options);

%train fis
[trn_fis, trn_error,~, val_fis, val_error] = anfis(trnData_fs,fis,[10 0 0.01 0.9 1.1],[],valData_fs);

%% Plot the Prediction vs Actual Values
Ypred = evalfis(val_fis,Xchk(:,index_features_selected));  % Is this correct ?
figure('Name','Predictions Vs Actual Values')
stem(Ypred,'Marker','none')
hold on;
grid on;
stem(Ychk,'Marker','none')
title('Prediction vs Actual Values ');
legend('Predictions','Actual Values',Location='best');

%% Plot the Training vs Validation Error
figure('Name','Training/Validation Error')
plot(trn_error,LineWidth=2);
grid on;
hold on;
plot(val_error,LineWidth=2);
xlabel('Epochs');
ylabel('Error');
legend('Training Error','Validation Error',location='best');
title('Training/Validation Error');

%% Plot some fuzzy 
figure('Name',"Input Membership Functions AFTER TRAINING");
plotMFsNew(trn_fis,6);

%% RMSE,NMSE,NDEI,R2
RMSE = @(yhat,y) sqrt(mean((yhat - y).^2));
rmse = RMSE(Ypred,Ychk);
NMSE =@(yhat,y) sum((y - yhat).^2)./sum((y - mean(y)).^2);
nmse = NMSE(Ypred,Ychk);
NDEI = @(yhat,y) sqrt(NMSE(yhat,y));
ndei = NDEI(Ypred,Ychk);
R2 = @(yhat,y) 1-sum((yhat-y).^2)/sum((y-mean(y)).^2);
r2 = R2(Ypred,Ychk);

fprintf('\nRMSE: %.4f\nNMSE: %.4f\nNDEI: %.4f\nR2: %.4f\n',rmse,nmse,ndei,r2);










