import random

def createMatrix(_n):
    X=[]
    for i in range(_n):
        aux=[]
        for j in range(_n):
            aux.append(random.uniform(0, 0.2))
        X.append(aux)
    return X

def createIdentity(_n):
    X=[]
    for i in range(_n):
        aux=[]
        for j in range(_n):
            if i==j:
                aux.append(1)
            else:
                aux.append(0)
        X.append(aux)
    return X               

def multiplyMatrix(A,B):
    X=[]
    for i in range(len(A)):
        aux=[]
        for j in range(len(B[0])):  
            aux_=0
            for k in range(len(A[0])):    
                aux_+=A[i][k]*B[k][j]
            aux.append(aux_)
        X.append(aux)
    return X


n=10
A=createMatrix(n)
Id=createIdentity(n)
for i in range(20000):
    A=multiplyMatrix(createMatrix(n),A)

print(A)