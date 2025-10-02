% ΠΡΑΓΜΑΤΑ ΠΟΥ ΠΡΕΠΕΙ ΝΑ ΦΤΙΑΞΩ
%1. ΠΑΙΡΝΩ WARNING ΣΤΟ SIMULINK ΟΤΑΝ ΤΡΕΧΩ FT GAINS
%2. ΝΑ ΔΩ ΤΙ ΘΕΛΕΙ ΝΑ ΤΟΥ ΠΑΡΟΥΣΙΑΣΩ ΓΙΑ ΤΟ ΣΕΝΑΡΙΟ 3

clc;
close all;

Ke_initial = 1;
a_initial = 0.2;
Kd_initial = a_initial*Ke_initial;
K_initial = 8.75;

Ke_ft = 1;
a_ft =2;
Kd_ft = a_ft*Ke_ft;
K_ft = 60;

Ke = Ke_ft;
a = a_ft;
Kd = Kd_ft;
K = K_ft;

Ts = 0.01;
T_total = 30;
t = 0:Ts:T_total;
r3 = 150;
r3 = timeseries(r3,t);

Tl = ones(size(t));
Tl(t >= 10 & t < 20) = 0.5;
Tl = timeseries(Tl,t);

plot(omega_s3)