%% Split - Preprocess Data

function [trnData,valData,chkData] = train_test_split(data,preproc,fq_tol)
    
    cnt=0;
    while true
        cnt = cnt + 1;
        if mod(cnt,100) == 0
            clc;
            fprintf("Fixing class frequencies across all sets ...\n");
        end
        
        idx=randperm(size(data,1)); %random indexes
        
        %split into Train/Test/Validation = 60/20/20
        trnIdx=idx(1:round(length(idx)*0.6));
        valIdx=idx(round(length(idx)*0.6)+1:round(length(idx)*0.8));
        chkIdx=idx(round(length(idx)*0.8)+1:end);
        
        %get only the data and not the last column which is the labels
        trnX=data(trnIdx,1:end-1);
        valX=data(valIdx,1:end-1);
        chkX=data(chkIdx,1:end-1);
    
        %get the frequencies of each class for all the sets
        fq = get_frequency(data(:,end));
        fq_tr = get_frequency(data(trnIdx,end));
        fq_val = get_frequency(data(valIdx,end));
        fq_chk = get_frequency(data(chkIdx,end));
        if abs(fq(1) - fq_tr(1)) > fq_tol || abs(fq(2) - fq_tr(2)) > fq_tol
            continue
        end
        if abs(fq(1) - fq_val(1)) > fq_tol || abs(fq(2) - fq_val(2)) > fq_tol
                continue
        end
        if abs(fq(1) - fq_chk(1)) > fq_tol || abs(fq(2) - fq_chk(2)) > fq_tol
                continue
        end
        break;
    end
  

    switch preproc
        case 1                      %Normalization to unit hypercube
            %kanonikopoiisi min-max sto [0,1]
            xmin=min(trnX,[],1);
            xmax=max(trnX,[],1);

            trnX=(trnX-repmat(xmin,[length(trnX) 1]))./(repmat(xmax,[length(trnX) 1])-repmat(xmin,[length(trnX) 1]));
            valX=(valX-repmat(xmin,[length(valX) 1]))./(repmat(xmax,[length(valX) 1])-repmat(xmin,[length(valX) 1]));
            chkX=(chkX-repmat(xmin,[length(chkX) 1]))./(repmat(xmax,[length(chkX) 1])-repmat(xmin,[length(chkX) 1]));
       
        case 2                      %Standardization to zero mean - unit variance
            %kanonikopoiisi me mesi timi 0 kai diaspora 1
            % Standardization using TRAIN stats
            mu = mean(trnX,1);
            sig = std(trnX,0,1);
            sig(sig==0) = 1;   % avoid division by zero
            trnX = (trnX - mu) ./ sig;
            valX = (valX - mu) ./ sig;
            chkX = (chkX - mu) ./ sig;

        otherwise
            disp('Not appropriate choice.')
    end

    %kollaei piso ta labels. [features, class]
    trnData=[trnX data(trnIdx,end)];
    valData=[valX data(valIdx,end)];
    chkData=[chkX data(chkIdx,end)];

end