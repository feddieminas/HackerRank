'''
https://www.hackerrank.com/domains/python/numpy
Numpy.py
HacckerrankPy

Python 2
'''

import numpy

def Arrays(): #1
    #1)
    print numpy.array(raw_input().strip().split(' '),float) [::-1]
    #2)
    #print numpy.array(list(reversed(raw_input().strip().split(' '))), float)
    #3)
    #print numpy.fromstring(raw_input(), sep=' ') [::-1]

def Shape_and_Reshape(): #2
    my_array=numpy.array(map(int,raw_input().strip().split(' ')), dtype = 'int') # [1,2,3,4,5,6,7,8,9]
    #print my_array.shape #(9,) 9 rows and 0 columns
    print numpy.reshape(my_array,(3,3))
    #[[1,2,3]
    #[4,5,6]
    #[7,8,9]]

def Transpose_and_Flatten(): #3
    N, M = map(int,raw_input().strip().split(' ')) #your dimension 2, 2
    my_array=numpy.array([raw_input().strip().split(' ') for _ in range(N)],int) # first line 1 2 and second line 3 4
    print numpy.transpose(my_array)
    print my_array.flatten()

def Concatenate(): #4
    N, M, P = map(int, raw_input().strip().split(' '))
    arr1 = numpy.array([raw_input().strip().split() for _ in range(N)], int)
    arr2 = numpy.array([raw_input().strip().split() for _ in range(M)], int)
    arr=numpy.concatenate((arr1,arr2), axis = 0)
    print numpy.reshape(arr,(N+M,P))

def Zeros_and_Ones(): #5
    dim = map(int, raw_input().strip().split(' '))
    print numpy.zeros(dim, dtype=numpy.int), "\n", numpy.ones(dim, dtype=numpy.int)

def Eye_and_Identity(): #6
    N, M = map(int, raw_input().strip().split(' '))
    #print numpy.identity(N) #works for testcase 0 as dimension N and M is equal
    print numpy.eye(N,M, k=0)
    #print numpy.eye(*map(int,raw_input().strip().split(' ')))

def Array_Mathematics(): #7
    N, M= map(int, raw_input().strip().split(' '))
    A=[]
    B=[]
    for _ in range(0, N):
        A.append(map(int, raw_input().strip().split(' ')))
    for _ in range(0, N):
        B.append(map(int, raw_input().strip().split(' ')))
    A=numpy.array(A)
    B=numpy.array(B)
    print numpy.add(A,B)
    print numpy.subtract(A,B)
    print numpy.multiply(A,B)
    print numpy.divide(A,B)
    print numpy.mod(A,B)
    print numpy.power(A,B)

def Floor_Ceil_and_Rint(): #8
    arr = numpy.array(map(float, raw_input().strip().split(' ')))
    print numpy.floor(arr)
    print numpy.ceil(arr)
    print numpy.rint(arr)

def Sum_and_Prod(): #9
    N, M = map(int, raw_input().strip().split(' '))
    arr=[]
    for _ in range(0, N):
        arr.append(map(int, raw_input().strip().split(' ')))
    arr = numpy.array(arr)
    print numpy.prod(numpy.array(numpy.sum(arr,axis=0)), axis=0) # ([1,2],[3.4]) -> sum and array [4,6] -> prod 24

def Min_and_Max(): #10
    N, M= map(int, raw_input().strip().split(' '))
    #1)
    arr = numpy.zeros(shape=(N,M))
    for i in range(N):
        arr[i,:] = numpy.array(map(int, raw_input().split(" ")))   
    #print arr
    print int(numpy.max(numpy.min(arr, axis=1), axis=0))     
    #2)
    #arr=[]
    #for _ in range(0,N):
        #arr.append(map(int, raw_input().strip().split(' ')))
    #print numpy.max(numpy.array(numpy.min(numpy.array(arr), axis=1)), axis=0) #numpy.min [2,3,1,0] --> array [2,3,1,0] --> numpy.max 3

def Mean_Var_and_Std(): #11
    N, M= map(int, raw_input().strip().split(' '))
    arr=[]
    for _ in range(0, N):
        arr.append(map(int, raw_input().strip().split(' ')))
    narr=numpy.array(arr, dtype=float)
    print numpy.mean(narr,axis=1)
    print numpy.var(narr, axis=0)
    print numpy.std(narr, axis=None)

def Dot_and_Cross(): #12
    N = int(raw_input().strip())
    A = numpy.array([raw_input().split() for _ in range(N)], int)
    B = numpy.array([raw_input().split() for _ in range(N)], int)
    '''
    [[1,2],[3,4]]
    [[1,2],[3,4]]
    7=1*1+2*3
    10=1*2+2*4
    15=3*1+4*3
    22=3*2+4*4
    '''
    print numpy.dot(A,B)

def Inner_and_Outer(): #13
    A = map(int, raw_input().strip().split(' '))
    B = map(int, raw_input().strip().split(' '))
    print numpy.inner(A, B)       #3 (0*2+1*3)
    '''
    inner
    [[1,2],[3,4]]
    [[1,2],[3,4]]

    5=1*1+2*2
    11=1*3+2*4
    11=3*1+4*2
    22=3*3+4*4

    outer
    [0 1] [2]
          [3]
    0=0*2
    0=0*3
    2=1*2
    3=1*3
    '''
    print numpy.outer(A, B)       #matrix (0*2 0*3 1*2 1*3)

def Polynomials(): #14
    #polynomial ex. p[0]*x**(N-1) + p[1]*x**(N-2) + p[N-1]
    p = map(float, raw_input().strip().split(' ')) #coeffarr and N is len of p
    x = float(raw_input().strip())
    print numpy.polyval(p, x) #1.1*0**2 + 2*0**1 + 3 --> total =3

def Linear_Algebra(): #15
    x = int(raw_input().strip())
    arr = numpy.array([raw_input().strip().split() for i in range(x)], float)
    print numpy.linalg.det(arr) #a b c d = a*d - b*c determinant of matrix

if __name__ == '__main__':

    testcases={1:Arrays, 2:Shape_and_Reshape, 3:Transpose_and_Flatten, 4:Concatenate, 5:Zeros_and_Ones,
              6:Eye_and_Identity, 7:Array_Mathematics, 8:Floor_Ceil_and_Rint, 9:Sum_and_Prod,10:Min_and_Max,
              11:Mean_Var_and_Std, 12:Dot_and_Cross, 13:Inner_and_Outer, 14:Polynomials, 15:Linear_Algebra}

    #choose testcase
    op=1
    
    testcases[op]()