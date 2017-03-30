'''
https://www.hackerrank.com/challenges/absolute-permutation
Absolute_Permutation.py
HacckerrankPy
'''

'''
Solution. Fully accepted

ex. testcase 0: 2 1 (N,K)
Looping:
j=1
for l=1 to 2
l=1
perm[1]=1+1=2
perm[2]=1

j=3 exit
print 2 1

ex. 4 2 (N,K)
j=1
for l=1 to 3
l=1
perm[1]=1+2=3
perm[3]=1

l=2
perm[2]=2+2=4
perm[4]=2

j=5 exit

print 3 4 1 2
'''

T=int(input())

for i in range(T):
    N, K = map(int,input().strip().split())
    
    if (K==0):     #if no permute print the list
        print (" ".join(map(str, range(1,N+1)))) #ex. testcase 0: 3 0
        continue
    
    if(N%K!=0 and (N/K)%2!=0 and (N-K)%K!=0):  # (N%K!=0 and (N/K)%2!=0) same as (N%2*K!=0)
        print (-1) #ex. testcase 0: 3 2 
        continue   #if no valid permute, no same abs diff result 
 
    perm=[0]       #create the two list perm and visited using 1-based indexing
    visited=[1] 
    for n in range(1,N+1):
        perm.append(0)
        visited.append(0)

    j=1
    while(j<N+1):
        for l in range(j,j+K):
            perm[l]=l+K
            perm[l+K]=l
            visited[l]=visited[l+K]=1
        j+=2*K
        
    res=list(filter(lambda x: x==0,visited)) #check there is no any unvisited positions

    if not res:   #if empty list thus all positions visited x==1
        print (" ".join(str(ans) for ans in perm if ans!=0)) #ex. testcase 0: 2 1

