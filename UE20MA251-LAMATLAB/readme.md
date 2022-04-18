> Note : No semicolon means print


## 1 - Eigenvalues and Eigenvectors (Inbuilt)


**Preface :**

The `eig` function in matlab can be used to get Eigenvalues and Eigenvectors.

**Questions :**

Find the Eigenvalues and Eigenvectors for the following matrices : 

1. A=[3,1;0,3]

**Code :**
```js
A=[3,1;0,3];
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
```

**Screenshots :**

![1_1](./1_1.png)



2. A=[1,2,3;4,5,6;0,0,0]

**Code :**
```js
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
```

**Screenshots :**

![1_1](./1_2.png)


3. A=[1,1,3;1,5,1;3,1,1]

**Code :**
```js
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
```

**Screenshots :**

![1_1](./1_3.png) 


## 2 - Projection matrices and least squared method (Inbuilt)

**Preface :**

- projection can be found using `lsqr` function in matlab
- Projection matrices can be found using : a*transpose(a)/transpose(a)*a 
- `lsqr` is also used for finding least square 

**Questions :**

1. Find projection of b on A given, A=[1,0;0,1;1,1], b=[1,3,4]

**Code :**
```js
A=[1,0;0,1;1,1];
b=[1;3;4];
lsqr(A,b)
```

**Screenshots :**

![1_1](./2_1.png) 

2. find the projection a given,A=[1,0,0;0,1,0;0,0,1]

**code :**
```js
A=[1,0,0;0,1,0;0,0,1];
(A*transpose(A))/(transpose(A)*A)
```

**screenshots :**

![1_1](./2_2.png) 

3. find the least square fit for the following equations : 
  X+2Y=3
  3X+2Y=5
  X+Y=2.09

**code :**
```js
A=[1,2;3,2;1,1];
b=[3;5;2.09];
lsqr(A,b)
```

**screenshots :**

![1_1](./2_3.png) 


## 3 - QR Factorisation (Inbuilt)

**Preface :**

- Any matrix can be factorised into Q and R using `qr` function in matlab 

**Questions :**

Find the QR factors for the following : 

1. A=[1,-1,4;1,4,-2;1,4,2;1,-1,0]

**Code :**
```js
A=[1,-1,4;1,4,-2;1,4,2;1,-1,0];
[Q,R]=qr(A);
Q
R
```

**Screenshots :**

![1_1](./3_1.png) 

2. A=[3,2,4;2,0,2;4,2,3]

**code :**
```js
A=[1,0,0;0,1,0;0,0,1];
[Q,R]=qr(A);
Q
R
```

**screenshots :**

![1_1](./3_2.png) 

2. A=[1,0;0,1]

**code :**
```js
A=[1,0;0,1]
[Q,R]=qr(A);
Q
R
```

**screenshots :**

![1_1](./3_3.png) 


## 4 - QR Factorisation Using Gram-Schmidt process (Not Inbuilt)

**Preface :**

- here we factorise the matrices without using the qr command

**Questions :**

Find the QR factors for the following : 

1. A=[1,-1,4;1,4,-2;1,4,2;1,-1,0]

**Code :**
```js
A=[1,-1,4;1,4,-2;1,4,2;1,-1,0]
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
```

**Screenshots :**

![1_1](./3_1.png) 

2. A=[3,2,4;2,0,2;4,2,3]

**code :**
```js
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
```

**screenshots :**

![1_1](./4_2.png) 

2. A=[1,0;0,1]

**code :**
```js
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
```

**screenshots :**

![1_1](./4_3.png) 

# Gauss Jordan method of finding inverses (Not inbuilt)





