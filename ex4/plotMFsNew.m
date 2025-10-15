function plotMFsNew(fis, numInputs)
% Σχεδιάζει τα membership functions για κάθε είσοδο σε subplots
    t = tiledlayout(ceil(numInputs/2), 2, 'Padding','compact','TileSpacing','compact');
    for i = 1:numInputs
        nexttile; 
        hold on
        [x, y] = plotmf(fis,'input', i);   % still valid στο νέο API
        plot(x, y, 'LineWidth', 1.5);
        grid on
        title(sprintf('Input %d: %s', i, fis.Inputs(i).Name))
        xlabel('x'); ylabel('\mu')
    end
    title(t, 'Input Membership Functions');
    
end