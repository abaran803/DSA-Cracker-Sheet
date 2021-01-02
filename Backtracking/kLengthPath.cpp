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

bool Algo(int arr[9][9],int currSum,int x,int sum,int n,int vis[]) {
    if(currSum >= sum) {
        return true;
    }
    if(x >= n) {
        return false;
    }
    for(int i=0;i<n;i++) {
        if(arr[x][i] && !vis[i]) {
            int val = arr[x][i];
            vis[i] = 1;
            if(Algo(arr,currSum+val,i,sum,n,vis)) {
                return true;
            }
            vis[i] = 0;
        }
    }
    return false;
}

void solve() 
{ 
    int N,E;
    N = 9;
    cin >> E;
    int arr[9][9];
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            arr[i][j] = 0;
        }
    }
    for(int i=0;i<E;i++) {
        int a,b,w;
        cin >> a >> b >> w;
        arr[a][b] = w;
        arr[b][a] = w;
    }
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
    int sPoint,sum;
    cin >> sPoint >> sum;
    int vis[N];
    for(int i=0;i<N;i++) {
        vis[i] = 0;
    vis[sPoint] = 1;
    }
    cout << Algo(arr,0,sPoint,sum,N,vis);
} 