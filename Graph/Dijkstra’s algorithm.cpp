#include<iostream>
#include<queue>
#include<vector>
#include<map>
#include<limits.h>
using namespace std;

// Visited -> vis array
// Weight -> map<{NodeA,NodeB}> = Weight
// Dist[] -> Current Distance of Nodes

// Create a Graph using adjancy list
// Create a map of pair of NodeA and NodeB equal to distance between them
// Create a distance array of size V contain infinit for all except source
// Created a visited array of size V contain false for all except source
// Store source in a queue
// Traverse until queue is empty
    // Traverse the adjacent of q.front();
    // If old distance > newDist(Dist[q.front()]+distB/w(q.front(),adjacent))
        // Update distance
    // Select the element that is not visited and distance is smallest
    // store in queue and mark as visited

class Graph {

    vector<int> *adj;
    map<pair<int,int>,int> mp;
    int V;

    public:

        Graph(int sz) {
            V = sz;
            adj = new vector<int>[V];
            for(int i=0;i<V;i++) {
                for(int j=0;j<V;j++) {
                    mp[{i,j}] = INT_MAX;
                }
            }
        }

        void Dijkstra(int source,int dist[]) {

            bool vis[V];

            for(int i=0;i<V;i++) {
                dist[i] = INT_MAX;
                vis[i] = false;
            }

            queue<int> q;
            q.push(source);
            dist[source] = 0;
            vis[source] = true;

            while(!q.empty()) {
                int s = q.front();
                q.pop();
                for(int it: adj[s]) {
                    if(dist[s]+mp[{s,it}]<dist[it]) {
                        dist[it] = dist[s]+mp[{s,it}];
                    }
                }
                int pos = -1;
                int val = INT_MAX;
                for(int i=0;i<V;i++) {
                    if(!vis[i] && dist[i]<val) {
                        val = dist[i];
                        pos = i;
                    }
                }
                if(pos != -1) {
                    q.push(pos);
                    vis[pos] = true;
                }
            }
        }

        void insert(int a,int b,int c) {
            adj[a].push_back(b);
            adj[b].push_back(a);
            mp[{a,b}] = c;
            mp[{b,a}] = c;
        }
};

int main() {

    freopen("inp.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int n,e;
    cin >> n;

    Graph G(n);

    int arr[n][n];

    // // Adjacency Matrix Type insertion
    // for(int i=0;i<n;i++) {
    //     for(int j=0;j<n;j++) {
    //         int a;
    //         cin >> a;
    //         if(a != 0) {
    //             G.insert(i,j,a);
    //         }
    //     }
    // }

    // Adjacency List Type insertion
    cin >> e;
    for(int i=0;i<e;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        G.insert(a,b,c);
    }

    int dist[n];

    G.Dijkstra(2,dist);

    for(int i=0;i<n;i++) {
        cout << i << " -> " << dist[i] << endl;
    }

    return 0;

}