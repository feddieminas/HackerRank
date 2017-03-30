'''
https://www.hackerrank.com/challenges/pylons
Goodland_Electricity.py
HacckerrankPy
'''

'''
Solution. Fully accepted

ex. testcase 0:
6 2
0 1 1 1 1 0
'''

import sys
from functools import reduce

if __name__ == '__main__':
    n, k = map(int,input().strip().split(' '))

    arr=list(map(int,input().strip().split()))
    
    towerexists=reduce(lambda x,y: x+y, arr)

    if(towerexists<=0): #if no towers available(no supply)
        print(-1)
        sys.exit(0)
    elif(n<=k):         #if cities less or equal to dist, one tower need for all cities(less supply, more demand)
        print(1)
        sys.exit(0)
    elif(n>k):
        mintwrs=0
        twrptrng=k-1    #since <k reduce by 1. ex. testcase 0: arr[1] tower exists covers arr[0] and arr[2] (for k=2)
        twrptr=0
        twrpos=-1
        while(twrptrng<n):
            twrptr=twrptrng #tower pointer
            while(twrptr>twrpos and arr[twrptr]==0): #if no tower and tower pointer is higher to last stored(twrpos), go
                twrptr-=1                            #backwards towards twrpos to find city with a tower
            if(twrptr<=twrpos): #testcase 13: if tower ptr is out of sort descending rng with last stored tower pos, it cannot cover k rng
                mintwrs=-1  
                print(mintwrs)
                break
            mintwrs+=1    #dist covered by a tower
            twrpos=twrptr #store last tower position with dist covered
            twrptrng=twrptr+(2*k)-1 #next tower pointer according to <k rng 
            if(twrptrng<n): continue
            elif(twrptr+k-1>=n-1): twrptrng=n #if out of arr cities rng then return n to exit(no next loop)
            else: twrptrng=n-1
        else:
            print(mintwrs)