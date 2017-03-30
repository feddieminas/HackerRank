//
//  https://www.hackerrank.com/challenges/cut-the-tree
//
//  Cut_the_Tree.cpp
//  HacckerrankCpp
//

#define USING_MAIN_1

#if defined USING_MAIN_1

/*
 Solution. Fully Accepted (Yes Class)
 
 depth first search
 
 1) Init the root element with max collections to decrease the resursion depth
 
 ex. testcase
 Seq : 2->1->2->3->2->5->4->5->6
 
 Ind : 1   | 2    | 3   | 4   | 5    | 6
 Sum : 100 | 1600 | 100 | 500 | 1200 | 600
 
 2) Set as default first node as root
 
 ex. testcase
 Seq : 1->2->3->2->5->4->5->6
 
 Ind : 1    | 2    | 3   | 4   | 5    | 6
 Sum : 1600 | 1500 | 100 | 500 | 1200 | 600
 
 */

#include<iostream>
#include<list>
#include<climits>

using namespace std;

class dfsGraph {
private:
    int V;
    list<int> *adj;
    bool *visited;
    int value[100001], sum[100001];
    int tot = 0;
    int root; // rootnode
    
public:
    dfsGraph(int n) {
        V = n;
        adj = new list<int>[V + 1];
    }
    
    void Vertices() {
        for (int i = 1; i <= V; i++) {
            cin >> value[i];
            tot += value[i];
        }
    }
    
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    void Resets() {
        visited = new bool[V + 1];
        for (int i = 1; i <= V; i++) {
            sum[i] = 0;
            visited[i] = false;
        }
    }
    
    int MaxRoot() {  //Init the root element with max collections to decrease the resursion depth
        int maxlen = 0;
        for (int i = 1; i <= V; i++) {
            if (adj[i].size() > maxlen) {
                maxlen = adj[i].size();
                root = i;
            }
        }
        
        return root;
    }
    
    int dfs(int node) {
        int ret = 0;
        visited[node] = true;
        
        list<int>::iterator i;
        for (i = adj[node].begin(); i != adj[node].end(); ++i) {
            if (!visited[*i]) {
                ret += dfs(*i);
            }
        }
        
        //cout << "ret " << node << " " << ret << endl;
        //cout << "sum " << node << " " << value[node] + ret << endl;
        return sum[node] = value[node] + ret;
    }
    
    int MinVal() {
        int best = INT_MAX;
        for (int i = 1; i <= V; i++) {
            int diff = abs(tot - sum[i] - sum[i]); //delta of sum(tree1)=tot-sum[i] and sum(tree2)=sum[i]
            if (diff < best) best = diff;
        }
        return best;
    }
    
    
    ~dfsGraph() {
        delete[] adj; delete[] visited;
    }
    
};

int main() {
    int n;
    cin >> n;
    dfsGraph g(n);
    
    g.Vertices();
    
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g.addEdge(a, b);
    }
    
    g.Resets();
    
    int root = g.MaxRoot(); //1)
    //OR
    //int root = 1;         //2)
    g.dfs(root);
    
    cout << g.MinVal() << endl;
    
    return 0;
}

#else

/*
 Solution. Fully Accepted (No Class)
 
 depth first search
 */

#include<iostream>
#include<list>
#include<climits>

using namespace std;

int value[100001];
int sum[100001];

int dfs(int node,list<int> adj[], bool visited[]) {
    int ret = 0;
    visited[node] = true;
    
    list<int>::iterator i;
    for (i = adj[node].begin(); i != adj[node].end(); ++i) {
        if (!visited[*i]) {
            ret += dfs(*i, adj, visited);
        }
    }
    
    //cout << "ret " << node << " " << ret << endl;
    //cout << "sum " << node << " " << value[node] + ret << endl;
    return sum[node] = value[node] + ret;
}

int main() {
    int n;
    cin >> n;
    
    //vertex
    int tot = 0;
    for (int i = 1; i <= n; i++) {
        cin >> value[i];
        tot += value[i];
    }
    
    //edges
    list<int> *adj=new list<int>[n+1];
    
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    bool *visited = new bool[n+1];
    for (int i = 1; i <= n; i++) {
        sum[i] = 0;
        visited[i] = false;
    }
    
    //Init the root element with max collections to decrease the resursion depth
    int maxlen = 0;
    int root; //rootnode
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() > maxlen) {
            maxlen = adj[i].size();
            root = i;
        }
    }
    
    dfs(root, adj, visited); //1)
    //OR
    //dfs(1,adj,visited);    //2)
    
    delete[] adj; delete[] visited;
    
    int best = INT_MAX;
    for (int i = 1; i <= n;i++) {
        int diff = abs(tot - sum[i] - sum[i]); //delta of sum(tree1)=tot-sum[i] and sum(tree2)=sum[i]
        if (diff < best) best = diff;
    }
    cout << best << endl;
    
    return 0;
}

#endif // USING_MAIN_1