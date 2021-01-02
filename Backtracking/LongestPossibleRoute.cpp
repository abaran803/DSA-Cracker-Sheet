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

int xNb[] = {-1,0,0,1};
int yNb[] = {0,-1,1,0};

bool isSafe(int **arr,int row,int col,int MaxRow,int MaxCol) {
    if(row < 0 || row >= MaxRow || col < 0 || col >= MaxCol) {
        return false;
    }
    if(arr[row][col] == 0) {
        return false;
    }
    return true;
}

void Algo(int **arr,int currDist,int row,int col,int x,int y,int &maxDist,int m,int n) {
    if(!isSafe(arr,row,col,m,n)) {
        return;
    }
    if(row == x && col == y) {
        maxDist = max(maxDist,currDist);
    }
    arr[row][col] = 0;
    for(int i=0;i<4;i++) {
        Algo(arr,currDist+1,row+xNb[i],col+yNb[i],x,y,maxDist,m,n);
    }
    arr[row][col] = 1;
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
    int a,b,x,y;
    cin >> a >> b >> x >> y;
    int maxDist = 0;
    Algo(arr,0,a,b,x,y,maxDist,m,n);
    cout << maxDist;
} 