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

bool isSafe(int **arr,int rowNo,int colNo,int m,int n) {
    if(rowNo < 0 || rowNo >= m || colNo < 0 || colNo >= n) {
        return false;
    }
    int rowVal[4] = {-1,0,0,1};
    int colVal[4] = {0,-1,1,0};
    for(int i=0;i<4;i++) {
        if(rowNo+rowVal[i]>=0 && rowNo+rowVal[i]<m && colNo+colVal[i]>=0 && colNo+colVal[i]<n) {
            if(arr[rowNo+rowVal[i]][colNo+colVal[i]] == 0) {
                return false;
            }
        }
    }
    if(arr[rowNo][colNo] == 0) {
        return false;
    }
    return true;
}

void AlgoUtils(int **arr,int rowNo,int colNo,int &minSize,int size,int m,int n) {
    if(!isSafe(arr,rowNo,colNo,m,n)) {
        return;
    }
    if(arr[rowNo][colNo] == -1) {
        return;
    }
    if(colNo == n-1) {
        minSize = min(minSize,size);
        return;
    }
    arr[rowNo][colNo] = -1;
    AlgoUtils(arr,rowNo+1,colNo,minSize,size+1,m,n);
    AlgoUtils(arr,rowNo-1,colNo,minSize,size+1,m,n);
    AlgoUtils(arr,rowNo,colNo+1,minSize,size+1,m,n);
    AlgoUtils(arr,rowNo,colNo-1,minSize,size+1,m,n);
    arr[rowNo][colNo] = 1;
}

void Algo(int **arr,int m,int n) {
    int res = INT_MAX;
    for(int i=0;i<m;i++) {
        AlgoUtils(arr,i,0,res,0,m,n);
    }
    if(res == INT_MAX) {
        cout << -1;
        return;
    }
    cout << res;
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
    Algo(arr,m,n);
} 