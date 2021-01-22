// Take out all the edges
// Sort them according to weight
// Put them back one by one
// If anyone form cycle then remove it
// When the no. of edge == V-1 break;


#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<queue>
using namespace std;

struct Edge {
    int a,b;
    int wt;
};

class Graph {

    vector<int> *adj;
    map<pair<int,int>,int> w;
    int V;

    public:

        Graph(int sz) {
            V = sz;
            adj = new vector<int>[V];
        }

        void addEdge(int a,int b,int wt) {
            adj[a].push_back(b);
            adj[b].push_back(a);
            w[{a,b}] = wt;
        }

        bool CheckCycle(int a,int b) {
            queue<int> q;
            bool vis[V];
            for(int i=0;i<V;i++) {
                vis[i] = false;
            }
            q.push(b);
            while(!q.empty()) {
                int s = q.front();
                q.pop();
                for(auto it: adj[s]) {
                    if(!vis[it]) {
                        if(it == a) {
                            return true;
                        }
                        vis[it] = true;
                        q.push(it);
                    }
                }
            }
            return false;
        }

        void Traverse() {
            for(int i=0;i<V;i++) {
                cout << i << " -> ";
                for(auto it: adj[i]) {
                    // if(it >= i) {
                        cout << it << ' ';
                    // }
                }
                cout << endl;
            }
        }

};

bool cmp(Edge a,Edge b) {
    return (a.wt<=b.wt);
}

int main() {

    freopen("inp.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int n,e;
    cin >> n >> e;
    
    Graph G(n);

    vector<Edge> edg;

    for(int i=0;i<e;i++) {
        int a,b,w;
        cin >> a >> b >> w;
        // G.addEdge(a,b,w);
        Edge e;
        e.a = a;
        e.b = b;
        e.wt = w;
        edg.push_back(e);
    }

    int cnt = 0;

    sort(edg.begin(),edg.end(),cmp);

    for(auto it: edg) {
        cout << it.a << ' ' << it.b << ' ' << it.wt << " ~~\n";
        if(!G.CheckCycle(it.a,it.b)) {
            G.addEdge(it.a,it.b,it.wt);
            cnt++;
            if(cnt == n-1) {
                // break;
            }
        }
    }

    G.Traverse();

    return 0;

}