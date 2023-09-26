
% Esercizio 1 

% Matricola: 5013791
d1= 9;
d0= 1;

n = 10*(d1+1)+d0;

A = diag(ones(1, n-1), 1) + eye(n);
E = zeros(n, n);
E(n, 1) = 2^(-n);
B = A + E;

% Calcolo autovalori e autovettori
V_A = eig(A);
V_B = eig(B);

norm1 = norm(B-A)/norm(A);
norm2 = norm(V_B-V_A)/norm(V_A);

disp(V_A);
disp(V_B);
disp(norm1);
disp(norm2);

C = A.' * A;
D = B.' * B; 

V_C = eig(C);
V_D = eig(D);

norm1 = norm(D-C)/norm(C);
norm2 = norm(V_D-V_C)/norm(V_C);

disp(V_C);
disp(V_D);
disp(norm1);
disp(norm2);