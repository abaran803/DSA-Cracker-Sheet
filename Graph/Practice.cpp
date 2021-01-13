#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Graph {
    list<int> *adj;
    int V;

    public:

    Graph(int sz) {
        this->V = sz;
        this->adj = new list<int>[V];
    }

    void insert(int a,int b) {
        adj[a].push_front(b);
    }

    bool isCyclicUtils(int x,vector<bool> vis) {

        if(vis[x]) {
            return true;
        }

        vis[x] = true;

        for(auto it=adj[x].begin();it != adj[x].end();it++) {
            if(isCyclicUtils(vis[*it],vis)) {
                cout << *it << " ~~\n";
                return true;
            }
        }
        vis[x] = false;

        return false;
    }

    bool isCyclic() {
        vector<bool> vis(V,false);

        for(int i=0;i<V;i++) {
            if(isCyclicUtils(i,vis)) {
                cout << i << " ~~\n";
                return true;
            }
        }
        
        return false;
    }

};

int main() {

    freopen("inp.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int n,v;
    cin >> n >> v;
    Graph G(n);

    for(int i=0;i<v;i++) {
        int a,b;
        cin >> a >> b;
        G.insert(a,b);
    }

    if(G.isCyclic()) {
        cout << "Cycle Exist";
    } else {
        cout << "Cycle doesn't Exist";
    }

    return 0;

}