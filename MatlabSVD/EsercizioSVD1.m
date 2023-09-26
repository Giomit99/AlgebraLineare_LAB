% Esercizio 1

% Matricola: 2293006
d1= 0;
d0= 6;

m = 10*(d1+1)+d0;
A = [m,3];

for i=1:m
    for j=1:3
       if (j == 1)
           A(i,j) = 1;
       else
           A(i,j) = i/m;
       end
    end
end

A(:,3)= A(:,3).^2;

[U1,S1,V1] = svd(A);
Vect = diag(S1);
disp(Vect);
[U2,S2,V2] = svd(A');
Vect = diag(S2);
disp(Vect);

disp("Autovalori di AA' e poi di A'A");
Vect = eig(A*A.');
disp(Vect);
Vect = eig(A.'*A);
disp(Vect);

disp("Immagine di A, confrontadola con U");
Im1 = orth(A);
disp(Im1);
disp(U1);
disp("Kern di A, confrontandolo con V'");
Ker1 = null(A);
disp(Ker1);
disp(V1');
disp("Immagine di A', confrontadola con U");
Im2 = orth(A');
disp(Im2);
disp(U2);
disp("Kern di A', confrontandolo con V'");
Ker2 = null(A');
disp(Ker2);
disp(V2');
