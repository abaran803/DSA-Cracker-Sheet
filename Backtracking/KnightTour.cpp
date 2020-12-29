#include<bits/stdc++.h> 
#define int long long
#define vi vector<int>
#define vs vector<string>
#define F first
#define S second
#define mii map<int,int>
#define mci map<char,int>
#define N 8

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

int choices[N][2] = {
    {2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}
};

int k = 1;

bool isSafe(int arr[N][N],int row,int col) {
    if(row < 0 || row >= N || col < 0 || col >= N) {
        return false;
    }
    if(arr[row][col] != -1) {
        return false;
    }
    return true;
}

bool Algo(int arr[N][N],int row,int col) {
    if(k == N*N) {
        return true;
    }
    for(int i=0;i<N;i++) {
        if(isSafe(arr,row+choices[i][0],col+choices[i][1])) {
            arr[row+choices[i][0]][col+choices[i][1]] = k++;
            if(Algo(arr,row+choices[i][0],col+choices[i][1])) {
                return true;
            }
            arr[row+choices[i][0]][col+choices[i][1]] = -1;
            k--;
        }
    }
    return false;
}

void solve() 
{ 
    int arr[N][N];
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            arr[i][j] = -1;
        }
    }
    arr[0][0] = 0;
    Algo(arr,0,0);
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
} 