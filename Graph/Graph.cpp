#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Graph {
    vector<int> *arr;
    int V;


    public:
        Graph(int);
        void push(int,int);
        void DFS(int);
        void DFSDisconnected();
        void DFSUtils(int,bool*);
        void BFS(int);
    
};


Graph::Graph(int NodeCount) {
    this->V = NodeCount;
    arr = new vector<int>[V];
}

void Graph::push(int a,int b) {
    arr[a].push_back(b);
    // arr[b].push_back(a);
}

void Graph::DFSUtils(int a,bool vis[]) {
    cout << a << ' ';
    vis[a] = true;
    for(int i=0;i<arr[a].size();i++) {
        if(!vis[arr[a][i]]) {
            DFSUtils(arr[a][i],vis);
        }
    }
}

void Graph::DFS(int a) {
    bool vis[V];
    for(int i=0;i<V;i++) {
        vis[i] = false;
    }
    DFSUtils(a,vis);
    cout << endl;
}

void Graph::DFSDisconnected() {
    bool vis[V];
    for(int i=0;i<V;i++) {
        vis[i] = false;
    }
    for(int i=0;i<V;i++) {
        if(!vis[i]) {
            DFSUtils(i,vis);
        }
    }
}

void Graph::BFS(int a) {
    queue<int> q;
    bool vis[V];
    for(int i=0;i<V;i++) {
        vis[i] = false;
    }
    q.push(a);
    vis[a] = true;
    while(!q.empty()) {
        int b = q.front();
        cout << b << ' ';
        q.pop();
        for(int it: arr[b]) {
            if(!vis[it]) {
                vis[it] = true;
                q.push(it);
            }
        }
    }
    cout << endl;
}

int main() {

    freopen("inp.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int n,e;
    cin >> n >> e;

    Graph G(n);

    for(int i=0;i<e;i++) {
        int a,b;
        cin >> a >> b;
        G.push(a,b);
    }

    G.DFS(2);
    G.BFS(2);

    return 0;
}