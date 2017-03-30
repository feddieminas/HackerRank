'''
https://www.hackerrank.com/challenges/string-similarity?h_r=internal-search

String_Similarity.py
HacckerrankPy
'''

'''
Solution. Fully accepted

Z-algorithm

if(i<=r)
while looping through i, if i reaches r(rightbound) means that at least x times from the start of the loopstr related to
prev loop, a suffix string equality exists. Moves your compared pointer for the while loop below  
for ex. loopstr=aaabaab --> if clause returns true at i=2 and i=5 since same aa suffix has been found


while(i+z[i]<n and strcomparator(loopStr[z[i]],loopStr[i+z[i]]))
while loop compare if char equality exists one next of the other.
For ex. for i=1 --> loopStr[0]==loopStr[1]. if it exists z[i] increases then check for loopStr[1]==loopStr[2]


if(i+z[i]-1>r)
show the further towards end of the loopstr left and right bounds that equal to each other.
for ex. loopstr=aaabaab --> if clause returns true at i=1(l=1,r=2) and i=4(l=4,r=5)
First time i clause returns true, you practically have your min counter r-l. 


References :
Hackerrank excellent topics explained
Codeforces has a very good and short explanation of the algorithm as well as its application
http://codeforces.com/blog/entry/3107 
'''

def stringSimilarity(loopStr, strcomparator):
    n=len(loopStr)
    z=[int(0) for i in range(n)]
    l=r=0
    for i in range(1,n):
        if(i<=r):
            z[i]=min(r-i+1,z[i-l])
        while((i+z[i])<n and strcomparator(loopStr[z[i]],loopStr[i+z[i]])):
            z[i]+=1
        if(i+z[i]-1>r):
            l=i
            r=i+z[i]-1      
    return sum(z)+n

if __name__ == '__main__': 
    t=int(input())
    for i in range(0,t):
        loopStr= ''.join(map(str,input().strip().split()))
        print(stringSimilarity(loopStr,lambda x, y: x==y))