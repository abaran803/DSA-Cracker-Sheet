#include<iostream>
#include<vector>
using namespace std;

class Graph {
    vector<int> *adj;
    int V;

    public:

        Graph(int sz) {
            V = sz;
            adj = new vector<int>[V];
        }

        void insert(int a,int b) {
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        bool isCyclicUtils(int par,int curr,bool vis[]) {

            vis[curr] = true;

            for(int i=0;i<adj[curr].size();i++) {
                if(vis[adj[curr][i]]) {
                    if(adj[curr][i] != par) {
                        return true;
                    }
                }
                else if(isCyclicUtils(curr,adj[curr][i],vis)) {
                    return true;
                }
            }

            vis[curr] = false;

            return false;
        }

        bool isCyclic(int val) {
            bool vis[V];

            for(int i=0;i<V;i++) {
                vis[i] = false;
            }

            vis[val] = true;

            for(int i=0;i<adj[val].size();i++) {
                if(isCyclicUtils(val,adj[val][i],vis)) {
                    return true;
                }
            }
        }

};

int main() {


    freopen("inp.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int t;
    cin >> t;
    while(t--) {


        int v,e;
        cin >> v >> e;
        Graph G(v);

        for(int i=0;i<e;i++) {
            int a,b;
            cin >> a >> b;
            G.insert(a,b);
        }

        if(G.isCyclic(0)) {
            cout << "Cycle exist";
        } else {
            cout << "Cycle does not exist";
        } cout << endl;

    }


    return 0;

}