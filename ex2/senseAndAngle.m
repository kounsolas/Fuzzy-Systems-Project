function [Vd,Hd,theta_err] = senseAndAngle(x,y,theta,map,xd,yd)
    %theta is in radians

    % γωνίες για "αισθητήρες": εμπρός & πλάγια
    angles = [0, pi/2, -pi/2];   
    rmax   = 10; 

    % rayIntersection επιστρέφει αποστάσεις
    dists = rayIntersection(map, [x,y,theta], angles, rmax);

    % εμπρός απόσταση (0 rad)
    Hd = dists(1);    

    % πλάγια απόσταση (παίρνουμε το μικρότερο από τα 90° και -90°)
    Vd = min(dists(2:3));

    % heading error προς τον στόχο
    goal_angle = atan2(yd - y, xd - x);
    theta_err  = rad2deg(wrapToPi(goal_angle - theta));
end
