A=[1,0;0,1]
Q=zeros(2);
R=zeros(2);
for j=1:2
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
