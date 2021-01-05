#include<iostream>
#include<queue>
using namespace std;

int main() {
    
    freopen("inp.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int t;
    cin >> t;
    while(t--) {
        queue<int> q;
        int n;
        cin >> n;
        int arr[n];
        for(int i=0;i<n;i++) {
            cin >> arr[i];
        }
        int k;
        cin >> k;
        int i=0;
        for(i=0;i<k-1;i++) {
            q.push(arr[i]);
        }
        for(;i<n;i++) {
            if(q.size() == k) {
                q.pop();
            }
            q.push(arr[i]);
            while(!q.empty() && q.front()>=0) {
                q.pop();
            }
            if(q.empty()) {
                cout << 0 << ' ';
            } else {
                cout << q.front() << ' ';
            }
        }
        cout << endl;
    }
    return 0;
}