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
        bool DFS();
        bool DFSUtils(int,bool*);
    
};


Graph::Graph(int NodeCount) {
    this->V = NodeCount;
    arr = new vector<int>[V];
}

void Graph::push(int a,int b) {
    arr[a].push_back(b);
    // arr[b].push_back(a);
}

bool isCorr = true;

bool Graph::DFSUtils(int a,bool vis[]) {
    if(vis[a]) {
        return true;
    }
    vis[a] = true;
    for(int i=0;i<arr[a].size();i++) {
        if(DFSUtils(arr[a][i],vis)) {
            return true;
        }
    }
    vis[a] = false;
    return false;
}

bool Graph::DFS() {
    bool vis[V];
    for(int i=0;i<V;i++) {
        vis[i] = false;
    }
    for(int i=0;i<V;i++) {
        vis[i] = true;
        for(int j=0;j<arr[i].size();j++) {
            if(DFSUtils(arr[i][j],vis)) {
                return true;
            }
        }
        vis[i] = false;
    }
    return false;
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

    if(G.DFS()) {
        cout << "Cycle Exist\n";
    } else {
        cout << "Cycle does not exist\n";
    }

    return 0;
}