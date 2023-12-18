

Ts = 1;
a1 = 2.771;
a2 = -0.71;
a3 = -1.005;

% F(1) = a1 + (Ts - 2* x(2) * x(3))/(Ts + 2*x(2)* x(3));
% 
% F(2) = a2 - (x(1) * Ts + x(2)* Ts + 2 * x(1) *x(2) *x(3))/(Ts + 2*x(2)* x(3)); 
% 
% F(3) = a3 - (x(1)* Ts + x(2)* Ts - 2 * x(1) *x(2) *x(3))/(Ts + 2*x(2)* x(3));


F = @(x) [a1 + (Ts - 2* x(2) * x(3))/(Ts + 2*x(2)* x(3));

         a2 - (x(1) * Ts + x(2)* Ts + 2 * x(1) *x(2) *x(3))/(Ts + 2*x(2)* x(3));

         a3 - (x(1)* Ts + x(2)* Ts - 2 * x(1) *x(2) *x(3))/(Ts + 2*x(2)* x(3))
         
         ];


x0 = [0.02;0.01;1000];

options = optimoptions('fsolve','Display','iter');

[r0,rp,cp] = fsolve(F,x0,options)