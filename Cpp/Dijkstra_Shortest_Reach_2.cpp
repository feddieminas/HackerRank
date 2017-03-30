//
//  https://www.hackerrank.com/challenges/dijkstrashortreach
//
//  Dijkstra_Shortest_Reach_2.cpp
//  HacckerrankCpp
//

#define USING_MAIN_1

#if defined USING_MAIN_1

/*
  Solution. All testcases passed apart from last testcase 7. Testcase 7 got terminated due to timeout. Hackerrank requires max of 2.52 seconds per testcase.
 
 Adjacency priority queue list representation
 */

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct edge {
    int v; int weight=0;
    
    edge(int v, int weight) : v(v), weight(weight) {}
};

class prioritize {
public:
    bool operator()(pair<int, int>&p1, pair<int, int>&p2) { return p1.first > p2.first; }
};

void dijkstra(const vector< vector<edge> >  graph, int start, int Vs)
{
    priority_queue<pair<int,int>, vector<pair<int, int>>, prioritize> pq;   //push(1) push(3) push(2) push(4)
                                                                            //4 3 2 1
                                                                            //4 top() and pop()
                                                                            //push() insert as sort decending(left to right)
                                                                            //prioritize or greater<pair<int, int>> used to sort ascending it.Default parameter is less
    int* dist=new int[Vs];
    
    bool* sptSet = new bool[Vs];
    
    for (int i = 1; i < Vs; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
    
    pq.push(make_pair(0, start));
    
    dist[start] = 0;
    
    while (!pq.empty())
    {
        int u = pq.top().second;
        
        //if (pq.top().first < dist[u]) continue;
        //or
        //if (dist[u]==INT_MAX) {break;}
        
        pq.pop();
        
        if (sptSet[u]) continue;
        sptSet[u] = true;
        
        for (auto ul : graph[u]) {
            if (!sptSet[ul.v] && ((dist[u] + ul.weight) < dist[ul.v]))
                dist[ul.v] = dist[u] + ul.weight;
            pq.push(make_pair(dist[ul.v], ul.v));
        }
    }
    
    //Solution
    for (int i = 1; i < Vs; i++) {
        if (dist[i] != 0) {
            if (dist[i] == INT_MAX) {
                cout << "-1" << " ";
            }
            else {
                cout << dist[i] << " ";
            }
        }
    }
    cout << endl;
    
    /*
     for (int i = 1; i < Vs; i++) {
     cout << sptSet[i] << " ";
     }
     cout << endl;
     */
    
    delete[] sptSet;
    delete[] dist;
}

int main()
{
    int T;
    cin >> T;
    
    do {
        
        int N, M;
        cin >> N;
        cin >> M;
        
        vector< vector<edge> > graph(N + 1, vector<edge>());
        
        for (int j = 0; j < M; j++) {
            int u, v, w;
            cin >> u;
            cin >> v;
            cin >> w;
            
            edge e(v, w);
            
            graph[u].push_back(e);
            
            e.v = u;
            graph[v].push_back(e);
        }
        
        /*
         for (int i = 1; i < N + 1; i++) {
         for (auto u : graph[i]) {
         cout << i <<" " << u.v << " " << u.weight << " ";
         }
         cout << endl;
         }
         cout << endl;
         */
        
        int s;
        cin >> s;
        
        dijkstra(graph, s, (N+1));
        
        T--;
        
    } while (T > 0);
    
    return 0;
}

#elif defined USING_MAIN_2

/*
  Solution. All testcases passed apart from last testcase 7. Testcase 7 got terminated due to timeout. Hackerrank requires max of 2.52 seconds per testcase.
 
 Adjacency list representation
 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct edge {
    int v; int weight=0;
    
    edge(int v, int weight) : v(v), weight(weight) {}
};

void dijkstra(const vector< vector<edge> >  graph, int start, int Vs)
{
    int* dist=new int[Vs];
    
    bool* sptSet = new bool[Vs];
    
    for (int i = 1; i < Vs; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
    
    dist[start] = 0;
    
    for (int count = 0; count < Vs-1; count++)
    {
        int min = INT_MAX, min_index;
        for (int v = 1; v < Vs; v++)
            if (sptSet[v] == false && dist[v] <= min)
                min = dist[v], min_index = v;
        
        if (min == INT_MAX) { break; }
        
        int u = min_index;
        
        sptSet[u] = true;
        
        for (auto ul : graph[u]) {
            if (!sptSet[ul.v] && ((dist[u] + ul.weight) < dist[ul.v]))
                dist[ul.v] = dist[u] + ul.weight;
        }
    }
    
    //Solution
    for (int i = 1; i < Vs; i++) {
        if (dist[i] != 0) {
            if (dist[i] == INT_MAX) {
                cout << "-1" << " ";
            }
            else {
                cout << dist[i] << " ";
            }
        }
    }
    cout << endl;
    
    /*
     for (int i = 1; i < Vs; i++) {
     cout << sptSet[i] << " ";
     }
     cout << endl;
     */
    
    delete[] sptSet;
    delete[] dist;
}

int main()
{
    int T;
    cin >> T;
    
    do {
        
        int N, M;
        cin >> N;
        cin >> M;
        
        vector< vector<edge> > graph(N + 1, vector<edge>());
        
        for (int j = 0; j < M; j++) {
            int u, v, w;
            cin >> u;
            cin >> v;
            cin >> w;
            
            edge e(v, w);
            
            graph[u].push_back(e);
            
            e.v = u;
            graph[v].push_back(e);
        }
        
        /*
         for (int i = 1; i < N + 1; i++) {
         for (auto u : graph[i]) {
         cout << i <<" " << u.v << " " << u.weight << " ";
         }
         cout << endl;
         }
         cout << endl;
         */
        
        int s;
        cin >> s;
        
        dijkstra(graph, s, (N+1));
        
        T--;
        
    } while (T > 0);
    
    return 0;
}

#else

/*
 Solution. All testcases passed apart from last testcase 7. Testcase 7 got terminated due to timeout. Hackerrank requires max of 2.52 seconds per testcase.
 
 Adjacency matrix representation
 
 The graph presents the values with index 1 instead of 0. Thus N=4 the graph is from row 1 to 4 instead of 0 to 3. Equally the columns.
 Below at the graph it required to update your edge to minimum value on inputs as duplicate edges inputs might appear
 */

#include <iostream>
#include <climits>

using namespace std;

void dijkstra(int** graph, int start, int Vs)
{
    int* dist=new int[Vs];
    
    bool* sptSet = new bool[Vs];
    
    for (int i = 1; i < Vs; i++)
        dist[i] = INT_MAX, sptSet[i] = false; //another initialisation could be using vector<int> and vector<bool>
    
    dist[start] = 0;
    
    for (int count = 0; count < Vs-1; count++)
    {
        int min = INT_MAX, min_index;
        for (int v = 1; v < Vs; v++)
            if (sptSet[v] == false && dist[v] <= min)
                min = dist[v], min_index = v;
        
        if (min == INT_MAX) { break; }
        
        int u = min_index;
        
        sptSet[u] = true;
        
        for (int v = 1; v < Vs; v++) {
            if (!sptSet[v] && graph[u][v] && ((dist[u] + graph[u][v]) < dist[v]))
                dist[v] = dist[u] + graph[u][v];
        }
    }
    
    //Solution
    for (int i = 1; i < Vs; i++) {
        if (dist[i] != 0) {
            if (dist[i] == INT_MAX) {
                cout << "-1" << " ";
            }
            else {
                cout << dist[i] << " ";
            }
        }
    }
    cout << endl;
    
    /*
     for (int i = 1; i < Vs; i++) {
     cout << sptSet[i] << " ";
     }
     cout << endl;
     */
    
    delete[] sptSet;
    delete[] dist;
}

int main()
{
    int T;
    cin >> T;
    
    do {
        
        int N, M;
        cin >> N;
        cin >> M;
        
        int **graph = new int*[N + 1];
        for (int i = 0; i < N + 1; i++) {
            graph[i] = new int[N + 1];
            for (int j = 0; j < N + 1; j++) {
                graph[i][j]=0;
            }
        }
        
        for (int j = 0; j < M; j++) {
            int u, v, w;
            cin >> u;
            cin >> v;
            cin >> w;
            
            if (graph[u][v] > 0) {
                if (w < graph[u][v]) {
                    graph[u][v] = w;
                }
            }
            else {
                graph[u][v] = w;
            }
            
            
            if (graph[v][u] > 0) {
                if (w < graph[v][u]) {
                    graph[v][u] = w;
                }
            }
            else {
                graph[v][u] = w;
            }
        }
        
        /*
         for (int i = 0; i < N + 1; i++) {
         for (int j = 0; j < N + 1; j++) {
         cout << graph[i][j] << " ";
         }
         cout << endl;
         }
         */
        
        int s;
        cin >> s;
        
        dijkstra(graph, s, (N+1));
        
        for (int i = 0; i < N + 1; i++)
            delete[] graph[i];
        delete[] graph;
        
        T--;
        
    } while (T > 0);
    
    return 0;
}


#endif // USING_MAIN_1