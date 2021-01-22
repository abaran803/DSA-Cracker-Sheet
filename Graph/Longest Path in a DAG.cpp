#include<bits/stdc++.h>
using namespace std;
    
map<pair<int,int>,int> wt;

void TopoUtils(int x,vector<int> adj[],stack<int> &st,vector<bool> &vis) {
    vis[x] = true;
    for(int it: adj[x]) {
        if(!vis[it]) {
            TopoUtils(it,adj,st,vis);
        }
    }
    st.push(x);
}

void Topo(vector<int> adj[],int n,int sou) {
    vector<int> Dist(n,INT_MIN);
    vector<bool> vis(n,false);
    stack<int> st;
    Dist[sou] = 0;
    for(int i: adj[sou]) {
        if(!vis[i]) {
            TopoUtils(i,adj,st,vis);
        }
        st.push(sou);
    }
    while(!st.empty()) {
        int s = st.top();
        for(int it: adj[s]) {
            if(Dist[it] < Dist[s]+wt[{s,it}]) {
                Dist[it] = Dist[s]+wt[{s,it}];
            }
        }
        st.pop();
    }
    for(int i=0;i<n;i++) {
        if(Dist[i] == INT_MIN) {
            cout << "INF";
        } else {
            cout << Dist[i];
        } cout << ' ';
    }
}

int main() {

    freopen("inp.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int n,e;
    cin >> n >> e;

    vector<int> adj[n];

    for(int i=0;i<e;i++) {
        int a,b,w;
        cin >> a >> b >> w;
        adj[a].push_back(b);
        wt[{a,b}] = w;
        wt[{b,a}] = w;
    }

    Topo(adj,n,1);

    return 0;

}