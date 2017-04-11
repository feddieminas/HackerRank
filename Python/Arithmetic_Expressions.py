'''
https://www.hackerrank.com/challenges/arithmetic-expressions
Arithmetic_Expressions.py
HacckerrankPy
'''

'''
Solution. Fully accepted

brute force algo :
Used while loops to compute all possible positions and a list to keep valid solutions

ex. testcase 0:
Input:
3
22 79 21

recursion(22,1)
calcs = 22%101 = 22
recursion(22*79,2) 
calcs = 22*79%101 = 1738%101 = 21 
recursion(21*21,3) n --> recursion(21+21,3) n --> recursion(21-21,3) y --> -21
recursion(22*79,2) y --> *79
recursion(22,1) --> *79-21
arr[0] --> 22

Output:
22*79-21
'''

import sys
sys.setrecursionlimit(20000)

arr=seq=[]

def recursion(calcs,nextcalc):
    calcs%=101
    if (nextcalc==len(arr)): 
        return "good" if calcs==0 else None
    global seq
    while(recursion(calcs*arr[nextcalc],nextcalc+1)==None):
        while(recursion(calcs+arr[nextcalc],nextcalc+1)==None):
            while(recursion(calcs-arr[nextcalc],nextcalc+1)==None):
                return None
            else:
                seq=seq+["-"+str(arr[nextcalc])]
                return seq
        else:
            seq=seq+["+"+str(arr[nextcalc])]
            return seq
    else:
        seq=seq+["*"+str(arr[nextcalc])]
        return seq
    return None

if __name__ == '__main__':
    N=int(input())
    
    arr=list(map(int,input().strip().split()))
    
    recursion(arr[0],1)
    
    seq.append(arr[0])
    
    print("".join(str(ans) for ans in reversed(seq)))