// Create a weighted graph
// Create three array -> vis,dist,par
// vis -> to check if visited, initially false for all except source
// dist -> contain current distance for all, initially infinite for all except source, for source -> 0
// par -> contain parent of current node

// Algorithm
// store source in queue
// do while queue isn't empty
// traverse all adjacent if(dist[adj]>wt[source,adj])
// update dist[adj]
// make source as parent of adjacent
// after traversing the adjacent traverse for unvisited minimum distance node
// store minimum and mark minimum as visited

#include<iostream>
#include<limits.h>
#include<vector>
#include<queue>
#include<map>
using namespace std;

class Graph {

    vector<int> *adj;
    map<pair<int,int>,int> wt;
    int V;

    public:

        Graph(int sz) {
            V = sz;
            adj = new vector<int>[V];
        }

        void addEdge(int a,int b,int w) {
            adj[a].push_back(b);
            adj[b].push_back(a);
            wt[{a,b}] = w;
            wt[{b,a}] = w;
        }

        void PrimAlgo(int so) {
            int Dist[V];
            bool vis[V];
            queue<int> q;
            int par[V];
            for(int i=0;i<V;i++) {
                Dist[i] = INT_MAX;
                par[i] = -1;
                vis[i] = false;
            }
            Dist[so] = 0;
            q.push(so);
            vis[so] = true;

            while(!q.empty()) {
                int s = q.front();
                q.pop();
                for(int it: adj[s]) {
                    if(Dist[it]>wt[{s,it}] && !vis[it]) {
                        Dist[it] = wt[{s,it}];
                        par[it] = s;
                    }
                }
                int minVal = INT_MAX;
                int pos;
                for(int i=0;i<V;i++) {
                    if(!vis[i] && Dist[i]<minVal) {
                        minVal = Dist[i];
                        pos = i;
                    }
                }
                if(minVal != INT_MAX) {
                    q.push(pos);
                    vis[pos] = true;
                }
            }
            for(int i=0;i<V;i++) {
                cout << par[i] << ' ' << i << ' ' << wt[{par[i],i}] << "\n";
            }
        }
};

int main() {

    freopen("inp.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int n,e;
    cin >> n >> e;

    Graph G(n);

    for(int i=0;i<e;i++) {
        int a,b,w;
        cin >> a >> b >> w;
        G.addEdge(a,b,w);
    }

    G.PrimAlgo(0);

    return 0;

}