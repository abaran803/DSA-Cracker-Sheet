#include<iostream>
#include<vector>
#include<stack>
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
            adj[a].push_back(b);
        }

        void TopoSortUtils(int x,bool vis[],stack<int> &st) {
            vis[x] = true;

            for(int i=0;i<adj[x].size();i++) {
                if(!vis[adj[x][i]]) {
                    TopoSortUtils(adj[x][i],vis,st);
                }
            }

            st.push(x);
        }

        void TopoSort() {

            bool vis[V];

            for(int i=0;i<V;i++){
                vis[i] = false;
            }

            stack<int> st;

            for(int i=0;i<V;i++){
                if(!vis[i]) {
                    TopoSortUtils(i,vis,st);
                }
            }

            while(!st.empty()) {
                cout << st.top() << ' ';
                st.pop();
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
        int a,b;
        cin >> a >> b;
        G.addEdge(a,b);
    }

    G.TopoSort();

    return 0;

}