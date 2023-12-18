function F=myFunction(u)
  R0 = u(1);
  Rp = u(2);
  Cp = u(3);

Ts = 1;
a1 = 2.771;
a2 = -0.71;
a3 = -1.005;

F(1) = a1 + (Ts - 2*Rp *Cp)/(Ts + 2*Rp* Cp);

F(2) = a2 - (R0* Ts + Rp* Ts + 2 * R0 *Rp *Cp)/(Ts + 2*Rp* Cp); 

F(3) = a3 - (R0* Ts + Rp* Ts - 2 * R0 *Rp *Cp)/(Ts + 2*Rp* Cp);

end