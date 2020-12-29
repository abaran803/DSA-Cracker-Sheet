#include<bits/stdc++.h> 
#define int long long

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

bool isSafe(int **arr,int row,int col,int n) {
    for(int i=0;i<=row;i++) {
        if(arr[i][col]) {
            return false;
        }
    }
    for(int i=row,j=col;i>=0 && j>=0;i--,j--) {
        if(arr[i][j] == 1) {
            return false;
        }
    }
    for(int i=row,j=col;i>=0 && j<n;i--,j++) {
        if(arr[i][j] == 1) {
            return false;
        }
    }
    return true;
}

bool nQueenUtils(int **arr,int row,int n) {
    if(row == n) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cout << arr[i][j] << ' ';
            }
            cout << endl;
        }
        cout << endl;
        return true;
    }
    for(int i=0;i<n;i++) {
        if(isSafe(arr,row,i,n)) {
            arr[row][i] = 1;
            nQueenUtils(arr,row+1,n);
            arr[row][i] = 0;
        }
    }
    return false;
}

void nQueen(int **res,int n) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            res[i][j] = 0;
        }
    }
    if(nQueenUtils(res,0,n)) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cout << res[i][j] << ' ';
            }
            cout << endl;
        }
    }
}

void solve() 
{ 
    int n;
    cin >> n;
    int **arr = new int*[n];
    for(int i=0;i<n;i++) {
        arr[i] = new int[n];
    }
    nQueen(arr,n);
} 