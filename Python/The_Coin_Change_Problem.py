'''
https://www.hackerrank.com/challenges/coin-change
The_Coin_Change_Problem.py
HacckerrankPy
'''

'''
Solution. Fully accepted

ex. testcase 0:
4 3
1 2 3

WaysToN Array Implementation (testcase 0)
WaysToN[0]=1    N=0 so not include any coin.You return 1 as solution to make the change below when you have set of coins given

i=0
j=CoinSet[0]=1  table[1]+=table[1-1]=table[0]=1
j=2             table[2]+=table[2-1]=table[1]=1
j=3             table[3]+=table[3-1]=table[2]=1
j=4             table[4]+=table[4-1]=table[3]=1 - (1,1,1,1) - one way to make four using CoinSet[null],CoinSet[0]

i=1
j=CoinSet[1]=2  table[2]+=table[2-2]=table[0]=2
j=3             table[3]+=table[3-2]=table[1]=2
j=4             table[4]+=table[4-2]=table[2]=3 - (1,1,2),(2,2) - three ways now to make four using CoinSet[null],CoinSet[0],CoinSet[1]

i=2
i=CoinSet[2]=3  table[3]+=table[3-3]=table[0]=3
j=4             table[4]+=table[4-3]=table[1]=4 - (1,3) - four ways now to make four using CoinSet[null],CoinSet[0],CoinSet[1],CoinSet[2]

http://www.geeksforgeeks.org/dynamic-programming-set-7-coin-change/
'''
    
N, M = map(int,input().strip().split())

CoinSet=[int(i) for i in input().strip().split()]

WaysToN=[0]*(N+1)

WaysToN[0]=1

'''
for i in range(0,M):
    for j in range(CoinSet[i],N+1):
        WaysToN[j]+=WaysToN[j-CoinSet[i]]

for coin in CoinSet:  
    for j in range(coin,N+1):  
        WaysToN[j]+=WaysToN[j-coin]         
'''
for i,coin in enumerate(CoinSet):   #Coins Set 
    for j in range(CoinSet[i],N+1): #Coins change range to supply
        WaysToN[j]+=WaysToN[j-CoinSet[i]]  #ways you can make j(consider it as the N).Carry array result and accumulate     
        
print(WaysToN[N])

