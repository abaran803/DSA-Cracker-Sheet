// If self-loop exist, return false
// Apply BFS and color neighbour with different color
// If neighbour is already coloured with same color return false

#include<bits/stdc++.h>
using namespace std;

bool isBiPertiteUtils(int x,vector<int> adj[],int n,vector<int> &color) {
    queue<int> q;
    q.push(x);
    color[x] = 1;
    while(!q.empty()) {
        int s = q.front();
        q.pop();
        for(int it: adj[s]) {
            if(color[it] == -1) {
                color[it] = 1-color[s];
                q.push(it);
            } else if(color[it] == color[s]) {
                return false;
            }
        }
    }
    return true;
}

bool isBiPertite(vector<int> adj[],int n) {

    for(int i=0;i<n;i++) {
        if(find(adj[i].begin(),adj[i].end(),i) != adj[i].end()) {
            return false;
        }
    }

    vector<int> color(n,-1);
    for(int i=0;i<n;i++) {
        if(color[i] == -1) {
            if(isBiPertiteUtils(i,adj,n,color) == false) {
                return false;
            }
        }
    }
    return true;
}

int main() {

    freopen("inp.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int n,e;
    cin >> n >> e;

    vector<int> adj[n];

    for(int i=0;i<e;i++) {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    if(isBiPertite(adj,n)) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;

}