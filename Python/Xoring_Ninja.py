'''
https://www.hackerrank.com/contests/master/challenges/xoring-ninja?h_r=internal-search

Xoring_Ninja.py
HacckerrankPy
'''

'''
Solution. Fully accepted

Stackexchange 712487 article is an excellent guide for the subsets. Practically to find 
the number of subset combinations is matter of finding how many 1s are on each level position. 
This myOrs number you then multiply power 2 to the length-1 array. 
You then use modulo as the exercise states it.

set 1 2 3        set 1 2 3 4
1 01               1  001
2 10               2  010
3 11               3  011
myOrs :            4  100
3 11               myOrs:
                   7  111
'''

T=raw_input()
T=int(T)

while(T>0):
    N=raw_input()
    N=int(N)
    mylist=list(map(int,raw_input().strip().split()))
    
    if not mylist: continue
    
    myOrs=mylist[0]
    i=1
    while(i<N):
        myOrs=myOrs | mylist[i]
        i+=1
        
    MOD=10**9+7
    result=myOrs * 2 ** (N-1) % MOD 
    
    print (result)
    
    T=T-1