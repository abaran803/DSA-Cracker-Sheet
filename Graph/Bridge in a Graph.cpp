#include<bits/stdc++.h>
using namespace std;

unordered_map<int,vector<int>> adj;
int n;

void DFS(int x,vector<int> &disc,vector<int> &low,vector<int> &par,vector<pair<int,int>> &bridge) {
    static int time = 0;
    disc[x] = low[x] = time;
    time++;
    for(int it: adj[x]) {
        if(disc[it] == -1) {
            par[it] = x;
            DFS(it,disc,low,par,bridge);
            low[x] = min(low[x],low[it]);
            if(low[it]>disc[x]) {
                bridge.push_back({x,it});
            }
        } else if(it != par[x]) {
            low[x] = min(low[x],disc[it]);
        }
    }
}

void Tarjan() {
    vector<int> disc(n,-1);
    vector<int> low(n,-1);
    vector<int> par(n,-1);
    vector<pair<int,int>> bridge;

    for(int i=0;i<n;i++) {
        if(disc[i] == -1) {
            DFS(i,disc,low,par,bridge);
        }
    }

    for(auto it: bridge) {
        cout << it.first << ' ' << it.second << endl;
    }

}

int main() {

    freopen("inp.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int e;
    cin >> n >> e;
    for(int i=0;i<e;i++) {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    Tarjan();

    return 0;

}