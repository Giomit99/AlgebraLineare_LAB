% Esercizio 2

A = [0 1 1 1 1 1 1 0 0 0 0;
     1 0 0 0 0 0 0 0 0 0 0;
     1 0 0 0 0 0 0 0 0 1 0;
     1 0 0 0 1 0 0 0 0 1 0;
     1 0 0 1 0 1 0 1 0 0 0;
     1 0 0 0 1 0 0 1 0 0 0;
     1 0 0 0 0 0 0 0 0 0 0;
     0 0 0 0 0 1 0 0 1 0 0;
     0 0 0 0 0 0 0 1 0 0 0;
     0 0 1 1 0 0 0 0 0 0 1;
     0 0 0 0 0 0 0 0 0 1 0];
 
 V = [6 1 2 3 4 3 1 2 1 3 1]; 
 D = diag(V);
 
 G = A*inv(D);
 E = eig(G);
 [V, C] = eig(G);
 
 disp(G);
 disp(E);
 disp(V);