#include<bits/stdc++.h> 
#define int long long
#define vi vector<int>
#define vs vector<string>
#define F first
#define S second
#define mii map<int,int>
#define mci map<char,int>

using namespace std;
void solve(); 

int32_t main() 
{ 
    ios_base::sync_with_stdio(false);cin.tie(NULL); 

    #ifndef ONLINE_JUDGE 
        freopen("inp.txt", "r", stdin); 
        freopen("err.txt", "w", stderr); 
        freopen("out.txt", "w", stdout); 
    #endif 

    int t=1; 
    //cin>>t; 
    while(t--) 
    { 
        solve(); 
        cout<<endl; 
    } 
    cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
    return 0; 
} 

void solve() 
{ 
    int n;
    cin >> n;
    int arr[n];
    stack<int> q;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    vector<int> vec;
    for(int i=n-1;i>=0;i--) {
        while(!q.empty() && q.top() >= arr[i]) {
            q.pop();
        }
        if(q.empty()) {
            vec.push_back(-1);
        } else {
            vec.push_back(q.top());
        }
        q.push(arr[i]);
    }
    for(int i=vec.size()-1;i>=0;i--) {
        cout << vec[i] << ' ';
    }
    cout << endl;
} 