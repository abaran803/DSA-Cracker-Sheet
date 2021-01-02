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

bool isSafe(int row,int col,int m,int n) {
    if(row<0 || col<0 || row>=m || col >= n) {
        return false;
    }
    return true;
}

void Algo(int **arr,vector<int> vec,int row,int col,int m,int n) {
    if(isSafe(row,col,m,n)) {
        vec.push_back(arr[row][col]);
        if(row == m-1 && col == n-1) {
            for(int i=0;i<vec.size();i++) {
                cout << vec[i] << ' ';
            }
            cout << endl;
            return;
        }
        Algo(arr,vec,row,col+1,m,n);
        Algo(arr,vec,row+1,col,m,n);
    }
}

void solve() 
{ 
    int m,n;
    cin >> m >> n;
    int **arr = new int*[m];
    for(int i=0;i<m;i++) {
        arr[i] = new int[n];
    }
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            cin >> arr[i][j];
        }
    }
    vector<int> vec;
    Algo(arr,vec,0,0,m,n);
} 