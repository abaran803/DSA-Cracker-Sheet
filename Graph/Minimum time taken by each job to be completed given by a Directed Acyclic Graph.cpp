#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Calculate number of task that assign current task (let preTask)
// Store all the task that are not assigned by anyone (preTask == 0)
// Print all task number (like level wise traversal in tree) and decrease preTask of all the next task by 1
// Repeat above while queue is not empty

// Levelwise means put -1 at end of every level so that we recognise current level

int main() {

    freopen("inp.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int n;
    cin >> n;
    vector<int> *adj = new vector<int>[n+1];
    vector<int> in(n+1,0);

    int e;
    cin >> e;
    for(int i=0;i<e;i++) {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        in[b]++;
    }

    int cnt = 1;
    queue<int> q;

    for(int i=1;i<=n;i++) {
        if(!in[i]) {
            q.push(i);
        }
    }
    q.push(-1);

    while(!q.empty()) {
        int s = q.front();
        q.pop();
        if(s == -1) {
            if(q.empty()) {
                break;
            } else {
                q.push(-1);
                cnt++;
            }
        } else {
            cout << cnt << ' ';
            for(int i=0;i<adj[s].size();i++) {
                in[adj[s][i]]--;
                if(in[adj[s][i]] == 0) {
                    q.push(adj[s][i]);
                }
            }
        }
    }

    return 0;
}