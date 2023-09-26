%Esercizio 2 
n=0;

for i=1:4
    n = n+5;
    str = sprintf('Matrice di taglia nxn con n=%d', n);
    disp(str);
    [ii,jj] = ndgrid(1:n);
    out = (ii == jj) - (ii < jj);
    disp("Valori singolari e condizionamento in norma 2");
    [U,S,V] = svd(out);
    Vect = diag(out);
    disp(Vect);
    disp(cond(out,2));
    disp("Perturbazione in A(n,1) di -2^(2-n)");
    disp("Autovalori della matrice perturbata");
    out(n,1) = out(n,1)-2^(2-n);
    W = eig(out);
    disp(W);
    
end    