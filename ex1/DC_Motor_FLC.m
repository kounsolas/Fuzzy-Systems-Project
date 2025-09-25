%% Σενάριο 1
clc;
close all;
clearvars;

TL = 0;  
Ts = 0.01;
Ke_initial = 1;
a_initial = 0.2;
Kd_initial = a_initial*Ke_initial;
K_initial = 8.75;
T_total = 30;
t = 0:Ts:T_total;
r = 150*ones(size(t));          
r(t >= 10 & t < 20) = 100;   
r_max = 150;
normalization = 1/r_max;
r = timeseries(r,t);
%% 
