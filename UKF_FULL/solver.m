zGuess = [0.002; 0.001; 1];
z = fsolve(@myFunction, zGuess);
disp(z)
