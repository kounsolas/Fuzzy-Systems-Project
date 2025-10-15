function kappa = cohenKappa(C)
    N = sum(C(:));
    po = trace(C) / N;                            % observed agreement
    pe = sum(sum(C,1) .* sum(C,2)') / N^2;        % expected agreement
    kappa = (po - pe) / (1 - pe);
end
