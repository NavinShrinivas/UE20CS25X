A=[1,1,3;1,5,1;3,1,1];
eig(A)
% for verifying results : trace(A) = sum(eig(A)) and prod(eig(A)) = det(A)
trace(A)
sum(eig(A))
% 
prod(eig(A))
det(A)
% eig return eigen vectors as well 
[V,D]=eig(A);
V

