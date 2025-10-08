function [frequency] = get_frequency(Y)
    num_of_classes = length(unique(Y));
    frequency = NaN(num_of_classes,1);
    for class=1:num_of_classes
        frequency(class) = length(find(Y==class))/length(Y);
    end
end