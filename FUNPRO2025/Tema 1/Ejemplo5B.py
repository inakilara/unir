import numpy as np

def createMatrix(_n):
    X=np.random.uniform(low=0, high=0.2, size=(_n,_n))
    return X

def createIdentity(_n):
    X=np.identity(_n)
    return X               

def multiplyMatrix(A,B):
    X=np.matmul(A, B)
    return X


n=10
A=createMatrix(n)
Id=createIdentity(n)
for i in range(20000):
    A=multiplyMatrix(createMatrix(n),A)

print(A)