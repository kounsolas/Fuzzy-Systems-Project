%% Split - Preprocess Data

function [trnData,chkData,tstData] = train_test_split(data,preproc)

    idx=randperm(size(data,1)); %random indexes
    
    %split into Train/Test/Validation = 60/20/20
    trnIdx=idx(1:round(length(idx)*0.6));
    chkIdx=idx(round(length(idx)*0.6)+1:round(length(idx)*0.8));
    tstIdx=idx(round(length(idx)*0.8)+1:end);
    
    %get only the data and not the last column which is the labels
    trnX=data(trnIdx,1:end-1);
    chkX=data(chkIdx,1:end-1);
    tstX=data(tstIdx,1:end-1);

    switch preproc
        case 1                      %Normalization to unit hypercube
            %kanonikopoiisi min-max sto [0,1]
            xmin=min(trnX,[],1);
            xmax=max(trnX,[],1);

            trnX=(trnX-repmat(xmin,[length(trnX) 1]))./(repmat(xmax,[length(trnX) 1])-repmat(xmin,[length(trnX) 1]));
            chkX=(chkX-repmat(xmin,[length(chkX) 1]))./(repmat(xmax,[length(chkX) 1])-repmat(xmin,[length(chkX) 1]));
            tstX=(tstX-repmat(xmin,[length(tstX) 1]))./(repmat(xmax,[length(tstX) 1])-repmat(xmin,[length(tstX) 1]));
       
        case 2                      %Standardization to zero mean - unit variance
            %kanonikopoiisi me mesi timi 0 kai diaspora 1
            % Standardization using TRAIN stats
            mu = mean(trnX,1);
            sig = std(trnX,0,1);
            sig(sig==0) = 1;   % avoid division by zero
            trnX = (trnX - mu) ./ sig;
            chkX = (chkX - mu) ./ sig;
            tstX = (tstX - mu) ./ sig;

        otherwise
            disp('Not appropriate choice.')
    end

    %kollaei piso ta labels. [features, class]
    trnData=[trnX data(trnIdx,end)];
    chkData=[chkX data(chkIdx,end)];
    tstData=[tstX data(tstIdx,end)];

end