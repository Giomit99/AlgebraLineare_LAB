%Esercizio 3 

% Matricola: 2293006
d1= 0;
d0= 6;

m = 10*(d1+1)+d0;
A = [m,3];
y = [m];
for i=1:m
    for j=1:3
       if (j == 1)
           A(i,j) = 1;
       else
           A(i,j) = i/m;
       end
    end
end

for j=1:m 
    y(j) = sin(j/m);
end

A(:,3)= A(:,3).^2;
y = y.';
disp(A);
disp(y);

disp("Risoluzione di Ac = y con SVD");
[U,S,V] = svd(A, 0);
c = V*((U'*y)./diag(S));
disp(c);

disp("Risoluzione di Ac = y con QR");
[Q, R] = qr(A);
c = R\Q.'*y;
disp(c);

disp("Risoluzione di Ac = y con A'Ac = A'y");
temp1 = A.'*A;
temp2 = A.'*y;
c = temp1\temp2;
disp(c);

disp("Risoluzione di Ac = y con c = A\y");
c = A\y;
disp(c);
