'''
https://www.hackerrank.com/challenges/longest-increasing-subsequent
The_Longest_Increasing_Subsequence.py
HacckerrankPy
'''

'''
Solution. Fully accepted

a)
ex. 
Input: arr {0,8,4,12,2,10}

A[0] = 0. Case 1. tail[0]=A[0], length=1
0.
-----------------------------------------------------------------------------
A[1] = 8. Case 2. (8>0) --> tail[1]=A[1], length=2
0.
0, 8.
-----------------------------------------------------------------------------
A[2] = 4. Case 3. (8>4) --> tail[1]=A[2] (tail[1]: left=0 and right=1)
0.
0, 4.
0, 8. Discarded
-----------------------------------------------------------------------------
A[3] = 12. Case 2. (12>4) --> tail[2]=A[3], length=3
0.
0, 4.
0, 4, 12.
-----------------------------------------------------------------------------
A[4] = 2. Case 3. (12>2) --> tail[1]=A[4] (tail[1]: left=0 and right=1)
0.
0, 2.
0, 4. Discarded.
0, 4, 12.
-----------------------------------------------------------------------------
A[5] = 10. Case 3. (12>10) --> tail[2]=A[5] (tail[2]: left=1 and right=2)
0.
0, 2.
0, 2, 10.
0, 4, 12. Discarded.

Output:
LIS = 3 = {0, 2, 10} 

Link: http://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/

b)
alternatively as aswinvaio (similar approach to video posted in challenge)
'''

def LIS(arr):
    tail=[0]*len(arr)
    tail[0]=arr[0]
    
    def BSCeilInd(f):
        def inner(*args):
            left,right,arrval = f(*args)
            while(right-left>1):
                mid=left+int((right-left)/2)
                if(tail[mid]>=arrval):
                    right=mid
                else:
                    left=mid
            return right
        return inner

    length=1
    for i in range(1,len(arr)):
        if(arr[i]<tail[0]): #Case 1 (to the left min update)
            tail[0]=arr[i]
        elif(arr[i]>tail[length-1]): #Case 2 (to the right append and length++)
            tail[length]=arr[i]
            length+=1
        else:               #Case 3 (ceil mid update when tail[length-1]>arr[i])          
            @BSCeilInd
            def myinputs(left,right,arrval):
                return left,right,arrval
                
            getCI=myinputs(-1,length-1,arr[i])
            tail[getCI]=arr[i]
            
    return length


N=int(input())
arr=[]
for i in range(N):
    arr.append(int(input()))
    
if not arr: 
    print("0")
else:
    print(LIS(arr))