'''
https://www.hackerrank.com/challenges/kruskalmstrsub
Kruskal_MST_Really_Special_Subtree.py
HacckerrankPy
'''

'''
Solution. Fully accepted

Kruskal (Min Spanning Tree) using Union Find and Rank

ex. testcase 0:
4 6
1 2 5
1 3 3
4 1 6
2 4 7
3 2 4
3 4 5

sorted edges=[[1,3,3],[3,2,4],[1,2,5],[3,4,5],[4,1,6],[2,4,7]]

Min Vertex=(1 not 0) so parent and rank is based Index 1 (no Index 0)
parent=[0,1,1,1,1] 
rank=[0,1,0,0,0]

result=[[1,3,3],[3,2,4],[3,4,5]]
totalweight=3+4+5=12

http://www.geeksforgeeks.org/greedy-algorithms-set-2-kruskals-minimum-spanning-tree-mst/
'''

from collections import defaultdict, namedtuple

Edge=namedtuple('Edge',['u', 'v', 'w'])
 
def KruskalMST(V,edges):
    
    result =[]
    i = 0 
    e = 0
    
    #graph = edges

    #parent: if index 3 has num 1, then index 3 parent has child 1 
    #union by rank (rank of childs to be considered). For ex. if index 1 is 1, child 1 is first rank
    parent = [] ; rank = []

    def find(parent, i):
        if parent[i] == i:
            return i
        return find(parent, parent[i])

    def union(parent, rank, x, y): 
        xroot = find(parent, x)
        yroot = find(parent, y)
 
        '''
        a)Min child rank(rank[xroot]) has less parents to other vertices(v) compared to
        max child rank(rank[yroot]) that has more parents. So increase min rank parents(xroot) 
        and increase max rank childs(yroot) to help identify a circle. 
        Vice versa for b)
        '''
        if rank[xroot] < rank[yroot]: #a)
            parent[xroot] = yroot
        elif rank[xroot] > rank[yroot]: #b)
            parent[yroot] = xroot
        else :
            parent[yroot] = xroot #make a parent
            rank[xroot] += 1

    for node in range(V+1):
        parent.append(node) #before proceeding below to identify circles, initialise each node as parent and child of its own (parent(this))
        rank.append(0)
 
    for edge in edges :
            u,v,w =  edge
            i = i + 1
            if callable(find): #used it to verify that inner method can be called (__call__)
                x = find(parent, u)
                y = find(parent ,v)
 
            if x != y: #if edge not causes a circle
                e = e + 1  
                result.append([u,v,w])
                if callable(union): #inner method can be called
                    union(parent, rank, x, y) 

            if e == V-1: break

    '''
    print (parent)
    print (rank)
    print (result)
    '''
    
    totw=sum([e[2] for e in result])
    return totw

if __name__ == '__main__':
    
    N, M = map(int,input().strip().split())

    edges=[]
    for i in range(M):
        u, v, w = map(int,input().strip().split())
        edges.append(Edge(u, v, w))
    
    edges = sorted(edges,key=lambda item: item[2])

    #print (edges)

    totalweight=KruskalMST(N,edges)

    print (totalweight)