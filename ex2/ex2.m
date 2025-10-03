clc;
close all;

u = 0.05;
Ts = 0.02;
xd = 10;
yd = 3.2;
x = 4.1;
y = 0.3;
theta1 = 0;
theta2 = -45;
theta3 = -90;

img = imread('stepwall_exact.png');
bw = ~imbinarize(im2gray(img));
map = binaryOccupancyMap(bw,100);

car_FLC = readfis('ex2_fis');
theta = deg2rad(theta1);

path = []; 
while true

    epsxy = 1e-6;  % πολύ μικρό περιθώριο
    x = min(max(x, map.XWorldLimits(1)+epsxy), map.XWorldLimits(2)-epsxy);
    y = min(max(y, map.YWorldLimits(1)+epsxy), map.YWorldLimits(2)-epsxy);

    % αισθητήρες
    [Vd,Hd,theta_err_deg] = senseAndAngle(x,y,theta,map,xd,yd);

    % κανονικοποίηση
    Vd_norm = min(1, Vd/1.0);
    Hd_norm = min(1, Hd/1.0);

    % FLC
    dtheta_deg = evalfis(car_FLC, [Vd_norm, Hd_norm, theta_err_deg]);

    % ενημέρωση
    theta = wrapToPi(theta + deg2rad(dtheta_deg));
    x = x + u*Ts*cos(theta);
    y = y + u*Ts*sin(theta);

    epsxy = 1e-6;  % πολύ μικρό περιθώριο
    x = min(max(x, map.XWorldLimits(1)+epsxy), map.XWorldLimits(2)-epsxy);
    y = min(max(y, map.YWorldLimits(1)+epsxy), map.YWorldLimits(2)-epsxy);

    % αποθήκευση
    path = [path; x y theta];

    % --- Κριτήρια stop ---
    atGoal = hypot(xd - x, yd - y) <= 0.15;
    hitObs = min([Vd, Hd]) <= 0.25;
    if atGoal || hitObs
        fprintf('STOP: %s\n', ternary(atGoal,'Goal reached','Collision'));
        break;
    end
end

% --- Plot ---
%% 

figure; 
show(map); 
hold on; 
grid on; 
axis equal
plot(path(:,1), path(:,2), 'b-', 'LineWidth', 2)
plot(xd, yd, 'rx', 'MarkerSize',12,'LineWidth',2)
xlabel('X (m)'), ylabel('Y (m)')
legend('Map','Trajectory','Goal')




