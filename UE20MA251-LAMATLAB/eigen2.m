A=[1,2,3;4,5,6;0,0,0];
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

