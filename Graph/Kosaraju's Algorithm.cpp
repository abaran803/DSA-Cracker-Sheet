// Do DFS traversal and put element in stack in reverse order
// Reverse all edges
// Do DFS traversal of all the element in stack
// Print DFS value of all the element in stack

#include<bits/stdc++.h>
using namespace std;

unordered_map<int,vector<int>> adj,rAdj;
int n;

void DFS(int x,vector<bool> &vis,stack<int> &st) {
    vis[x] = true;
    for(int it: adj[x]) {
        if(!vis[it]) {
            DFS(it,vis,st);
        }
    }
    st.push(x);
}

void rDFS(int x,vector<bool> &vis) {
    vis[x] = true;
    cout << x << ' ';
    for(int it: rAdj[x]) {
        if(!vis[it]) {
            rDFS(it,vis);
        }
    }
}

void Kosaraju() {
    stack<int> st;
    vector<bool> vis(n,false),vis1(n,false);
    for(int i=0;i<n;i++) {
        if(!vis[i]) {
            DFS(i,vis,st);
        }
    }
    for(int i=0;i<n;i++) {
        for(int it: adj[i]) {
            rAdj[it].push_back(i);
        }
    }
    while(!st.empty()) {
        if(!vis1[st.top()]) {
            rDFS(st.top(),vis1);
            cout << endl;
        }
        st.pop();
    }
}

int main() {

    freopen("inp.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int e;
    cin >> n >> e;

    for(int i=0;i<n;i++) {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    Kosaraju();

    return 0;

}