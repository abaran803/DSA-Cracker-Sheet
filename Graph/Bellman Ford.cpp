// Create a Distance array (say Dist) of size = number of elements
// Make all elements infinite
// Take a source element
// Make distance of that node 0
// Traverse all the edges (V-1) times and update their distances minimum
// Traverse one more time and if the current distance is greater than new one then negative cycle exist

#include<iostream>
#include<vector>
#include<limits.h>
#include<queue>
#include<map>
using namespace std;

class Graph {

    vector<int> *adj;
    int V;
    map<pair<int,int>,int> wt;

    public:

        Graph(int sz) {
            V = sz;
            adj = new vector<int>[V];
        }

        void addEdge(int a,int b,int w) {
            adj[a].push_back(b);
            // adj[b].push_back(a);
            wt[{a,b}] = w;
            // wt[{b,a}] = w;
        }

        void BellmanFord(int source) {

            int Dist[V];
            for(int i=0;i<V;i++) {
                Dist[i] = INT_MAX;
            }

            Dist[source] = 0;

            for(int k=0;k<V;k++) {
                for(int i=0;i<V;i++) {
                    for(int j=0;j<adj[i].size();j++) {
                        if(wt[{i,adj[i][j]}] && Dist[i] != INT_MAX && (Dist[adj[i][j]] > Dist[i]+wt[{i,adj[i][j]}])) {
                            Dist[adj[i][j]] = Dist[i]+wt[{i,adj[i][j]}];
                        }
                    }
                }
            }

            for(int k=0;k<V;k++) {
                for(int i=0;i<V;i++) {
                    for(int j=0;j<adj[i].size();j++) {
                        if(wt[{i,adj[i][j]}] && Dist[i] != INT_MAX && (Dist[adj[i][j]] > Dist[i]+wt[{i,adj[i][j]}])) {
                            cout << "Having Negative Cycle\n";
                            return;
                        }
                    }
                }
            }

            for(int i=0;i<V;i++) {
                cout << i << ' ' << Dist[i] << endl;
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

    G.BellmanFord(0);

    return 0;

}