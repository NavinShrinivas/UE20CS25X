A=[3,2,4;2,0,2;4,2,3]
Q=zeros(3);
R=zeros(3);
for j=1:3
v=A(:,j);
for i=1:j-1
R(i,j)=Q(:,i)'*A(:,j);
v=v-R(i,j)*Q(:,i);
end
R(j,j)=norm(v);
Q(:,j)=v/R(j,j);
end
v
R
Q
