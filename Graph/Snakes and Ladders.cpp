// Create a linear array that store all the position values of snake shaped to linear form
// Store the first element in queue
// take out front element and perform below process
// if element is the last position return count
// traverse for next 6 unvisited elements, store and mark as visited
// if the position val isn't -1 store current position val in queue
// repeat above while queue become empty

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct pir {
    int v;
    int cnt;
};

int snakesAndLadders(vector<vector<int>>& board) {
    int n = board.size();
    int arr[n*n];
    int l = 0;
    for(int i=n-1,k=0;i>=0;i--,k++) {
        if(k%2 == 0) {
            for(int j=0;j<n;j++) {
                arr[l++] = board[i][j];
            }
        } else {
            for(int j=n-1;j>=0;j--) {
                arr[l++] = board[i][j];
            }
        }
    }
    queue<pir> q;
    bool vis[n*n];
    for(int i=0;i<n*n;i++) {
        vis[i] = false;
    }
    pir p;
    vis[0] = true;
    if(arr[0] == -1) {
        p.v = 0;
    } else {
        p.v = arr[0]-1;
        vis[arr[0]-1] = true;
    }
    p.cnt = 0;
    q.push(p);
    while(!q.empty()) {
        pir pii = q.front();
        q.pop();
        if(pii.v == n*n-1) {
            return pii.cnt;
        }
        for(int i=1;i<=6;i++) {
            if(pii.v+i < n*n && !vis[pii.v+i])
            {
                pir pi;
                pi.cnt = pii.cnt+1;
                vis[pii.v+i] = true;
                if(arr[pii.v+i] == -1) {
                    pi.v = pii.v+i;
                } else {
                    pi.v = arr[pii.v+i]-1;
                }
                q.push(pi);
            }
        }
    }
    return -1;
}

int main() {

    freopen("inp.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int n;
    cin >> n;
    
    vector<vector<int>> vec;

    for(int i=0;i<n;i++) {
        vector<int> vec1;
        for(int j=0;j<n;j++) {
            int a;
            cin >> a;
            vec1.push_back(a);
        }
        vec.push_back(vec1);
    }

    cout << snakesAndLadders(vec);

    return 0;

}