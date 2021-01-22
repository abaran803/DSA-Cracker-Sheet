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

        void addEdge(int a,int b) {
            adj[b].push_back(a);
        }

        bool isCyclicUtils(vector<bool> vis,int x) {

            if(vis[x]) {
                return true;
            }

            vis[x] = true;
            for(int i=0;i<adj[x].size();i++) {
                if(isCyclicUtils(vis,adj[x][i])) {
                    return true;
                }
            }
            return false;
        }

        bool isCyclic() {

            vector<bool> vis(V,false);

            for(int i=0;i<V;i++) {
                vis[i] = true;
                for(int j=0;j<adj[i].size();j++) {
                    if(isCyclicUtils(vis,adj[i][j])) {
                        return true;
                    }
                }
                vis[i] = false;
            }
            return false;
        }
};

int main() {

    freopen("inp.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int n,e;
    cin >> n >> e;

    Graph G(n);

    while(e--) {
        int a,b;
        cin >> a >> b;
        G.addEdge(a,b);
    }

    if(G.isCyclic()) {
        cout << "false";
    } else {
        cout << "true";
    }

    return 0;

}