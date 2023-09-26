%Esercizio 3 
 
 A=[1 -1 2;
    -2 0 5;
    6 -3 6];

V1=[1;
    1;
    1];

V2=[3;
    10;
    4];

disp("Metodo delle potenze");
disp("Primo test con  (1, 1, 1)'");
[y, lambda1, it_num ] = power_method ( 3, A, V1, 1000, 1e-10)

disp("Seondo test con (3, 10, 4)'");
[y, lambda2, it_num ] = power_method ( 3, A, V2, 1000, 1e-10)

disp("Metodo delle potenze inverso");
disp("Primo test con p=4");
[sigma1,iter]=power_method_inverse(A, 1e-10 ,10000 ,V1, 4, 3);
disp(sigma1);
disp(iter);

disp("Primo test con p=4.5");
[sigma2,iter]=power_method_inverse(A, 1e-10 ,10000 ,V2, 4.5, 3);
disp(sigma2);
disp(iter);
