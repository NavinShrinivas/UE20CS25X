A=[3,2,4;2,0,2;4,2,3];
% Row Reduced Echelon Form
[R, pivot] = rref(A);
% Rank
rank = length(pivot);
% basis of the column space of A
columnsp = A(:,pivot)
% basis of the nullspace of A
nullsp = null(A, 'r')
% basis of the row space of A
rowsp = R(1:rank, :)'
% basis of the left nullspace of A
leftnullsp = null(A', 'r')
