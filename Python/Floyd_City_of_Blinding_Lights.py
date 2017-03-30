'''
https://www.hackerrank.com/challenges/floyd-city-of-blinding-lights
Floyd_City_of_Blinding_Lights.py
HacckerrankPy
'''

'''
Solution. Accepted. Terminated due to Timeout for 2 testcases with Floydminus1 func and 3 testcases with FloydINF. Though algo written properly.

FloydWarshall algorithm

Solutions used Index base 1 and -1 is considered as INF also (Floydminus1). When INF is used (FloydINF), value not higher than INT_MAX/2 is needed 

Link: http://www.geeksforgeeks.org/dynamic-programming-set-16-floyd-warshall-algorithm/

Ex. 
Input
[[0,5,INF,10],
[INF,0,3,INF],
[INF,INF,0,1],
[INF,INF,INF,0]]

Short dist updates :
if(dist[0][2]>dist[0][1]+dist[1][2]) dist[0][2]=dist[0][1]+dist[1][2]=5+3=8
if(dist[0][3]>dist[0][2]+dist[2][3]) dist[0][3]=dist[0][2]+dist[2][3]=8+1=9
if(dist[1][3]>dist[1][2]+dist[2][3]) dist[1][3]=dist[1][2]+dist[2][3]=3+1=4

Output
[[0,5,8,9],
[INF,0,3,4],
[INF,INF,0,1],
[INF,INF,INF,0]]
'''

def Floydminus1():
    
    def FloydWarshall(graph):
        Nplus1=len(graph)
    
        dist= list(map(lambda i: list(map(lambda j: j, i)), graph))
        #OR
        #dist= [[graph[i][j] for j in range(Nplus1)] for i in range(Nplus1)]
        #print(dist)
    
        for i in range(Nplus1):
            dist[i][i]=0
        
        for k in range(Nplus1):
            for i in range(Nplus1):
                for j in range(Nplus1):
                    #if (dist[i][k]>=0 and dist[k][j]>=0) since we use -1 as INF
                    if (dist[i][k]>=0 and dist[k][j]>=0) and (dist[i][j]==-1 or dist[i][j]>dist[i][k]+dist[k][j]):
                        dist[i][j]=dist[i][k]+dist[k][j] # dist 0 to k + dist k to j 
                        #(i,k,j) maintain order in this way to work and all intermediate nodes are visited  
                    
        return dist	

    N, M = map(int,input().strip().split())

    graph=[(N+1) * [int(-1)] for i in range(N+1)] #Index base 1

    for i in range(M):
        x, y, r = map(int,input().strip().split())
        graph[x][y]=r
        
    #print(graph)    
    graph=FloydWarshall(graph)

    Q = int(input())

    for i in range(Q):
        x, y = map(int,input().strip().split())
        print (graph[x][y])
    
    
def FloydINF():
    
    import sys

    INF=(sys.maxsize+1)/2

    def FloydWarshall(graph):
    
        dist= list(map(lambda i: list(map(lambda j: j, i)), graph))
        #print(dist)
    
        Nplus1=len(graph)
    
        for i in range(Nplus1):
            dist[i][i]=0
        
        for k in range(Nplus1):
            for i in range(Nplus1):
                for j in range(Nplus1):
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]) # dist 0 to k + dist k to j 
                    #(i,k,j) maintain order in this way to work and all intermediate nodes are visited  
                    
        return dist	

    N, M = map(int,input().strip().split())

    graph=[(N+1) * [int(INF)] for i in range(N+1)] #Index base 1

    for i in range(M):
        x, y, r = map(int,input().strip().split())
        graph[x][y]=r
	
    #print(graph)    
    graph=FloydWarshall(graph)

    Q = int(input())

    for i in range(Q):
        x, y = map(int,input().strip().split())
        print (int(-1) if graph[x][y]==INF else graph[x][y])
    

if __name__ == '__main__':

    testcases={1:Floydminus1, 2:FloydINF}

    #choose solution
    op=1
    
    testcases[op]()