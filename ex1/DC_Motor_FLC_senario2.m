clc;
close all;
clearvars;

TL = 0;
Ke_initial = 1;
a_initial = 0.2;
Kd_initial = a_initial*Ke_initial;
K_initial = 8.75;
Ts = 0.01;
T_total = 30;
t = 0:Ts:T_total;

fis = readfis('fis.fis');

t_point = [0 10 20 30];
r_point = [0 150 150 0];
r2 = interp1(t_point,r_point,t,'linear');
r_max = 150;
normalization = 1/r_max;
r = timeseries(r2,t);


Ke_ft = 1;
a_ft =2;
Kd_ft = a_ft*Ke_ft;
K_ft = 60;

initial = true;

if initial
    Ke = Ke_initial;
    a = a_initial;
    Kd = Kd_initial;
    K = K_initial;
else
    Ke = Ke_ft;
    a = a_ft;
    Kd = Kd_ft;
    K = K_ft;
end

%% PLots
figure();
plot(omega_s1);
grid on;
xlabel("Time(s)");
ylabel("rad/sec");
title("Έξοδος του συστήματος (ω)");
legend("Σήμα Αναφοράς (r)","Εξοδος (ω)");

%Προυπόθεση (2) - max 5% υπερύψωση για βηματική είσοδο
max_omega = max(r)*1.05;

figure();
subplot(3,1,1);
plot(omega_s1);
grid on;
hold on;
yline(max_omega,"black","μέγιστη θετική υπερύψωση (5%)","LineStyle","--","LineWidth",2);
title("Εξοδος (ω) του συστήματος - Προυπόθεση 2");
ylabel("rad/sec");
legend("Σήμα Αναφοράς","Έξοδος του συστήματος")

%Προυπόθεση 4 - Χρόνος ανόδου <= 160ms
%figure(2)
subplot(3,1,2);
plot(omega_s1); 
grid on; 
hold on;

xlim([0 0.2]);              
xline(0.16,'--',LineWidth=2);           
yline(r.Data(17)*0.9,'--',LineWidth=2);           
title('Χρόνος Ανόδου - Προυπόθεση 4'); 
xlabel('Time (s)'); 
ylabel(' ω (rad/s)');
legend('r(t)','ω','90%Yss σε t=160 ms','Location','best');

%Προυπόθεση 5 - Va(t)<=200V για κάθε t>0
%figure(3);
subplot(3,1,3);
plot(Va_s1);
grid on;
ylabel("Va(V)")
title("Va - Προυπόθεση 5")
yline(200,'r',"200V",LineStyle="--",LineWidth=2)