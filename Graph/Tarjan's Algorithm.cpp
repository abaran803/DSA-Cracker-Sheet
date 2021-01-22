// Create a clock(name time) statics so that it can be change anywhere in the program
// Take two array disc, and low which contain time taken to reach that node first time and minimum time taken to reach that node respectively
// disc value is fixed but low value is changed
// Initial value of disc and low is -1
// Do DFS traversal and in place of visited array check by using disc is -1
// If disc is -1 put the low of adjacent else if disc is not -1 and not in stack then put the disc of adjacent

#include<bits/stdc++.h>
using namespace std;

unordered_map<int,vector<int>> adj;
int n;

void DFS(int x,vector<int> &disc,vector<int> &low,vector<bool> &isPresentInStack,stack<int> &st) {
    static int time = 0;
    disc[x] = low[x] = time;
    time++;
    st.push(x);
    isPresentInStack[x] = true;

    for(auto it: adj[x]) {
        if(disc[it] == -1) {
            DFS(it,disc,low,isPresentInStack,st);
            low[x] = min(low[x],low[it]);
        } else if(isPresentInStack[it]) {
            low[x] = min(low[x],disc[it]);
        }
    }
    if(low[x] == disc[x]) {
        cout << "SCC is ";
        while(st.top() != x) {
            cout << st.top() << ' ';
            isPresentInStack[st.top()] = false;
            st.pop();
        }
        cout << st.top() << endl;
        isPresentInStack[st.top()] = false;
        st.pop();
    }
}

void Tarjan() {
    vector<int> disc(n,-1);
    vector<int> low(n,-1);
    vector<bool> isPresentInStack(n,false);
    stack<int> st;

    for(int i=0;i<n;i++) {
        if(disc[i] == -1) {
            DFS(i,disc,low,isPresentInStack,st);
        }
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

    Tarjan();

    return 0;

}