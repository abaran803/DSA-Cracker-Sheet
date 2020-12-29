#include<bits/stdc++.h> 
#define int long long
#define MAX 5

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
    cin>>t; 
    while(t--) 
    { 
    solve(); 
    cout<<endl; 
    } 
    cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
    return 0; 
} 

bool isSafe(int arr[MAX][MAX],int i,int j,int n) {
    if((i<n && j<n) && (i>=0 && j>=0) && arr[i][j]) {
        return true;
    }
    return false;
}

void printPathUtils(int arr[MAX][MAX],int i,int j,int n,vector<string> &vec,string currPos) {
    if(!isSafe(arr,i,j,n)) {
        return;
    }
    if(i == n-1 && j == n-1) {
        vec.push_back(currPos);
    }
    arr[i][j] = 0;
    printPathUtils(arr,i+1,j,n,vec,currPos+'D');
    printPathUtils(arr,i,j+1,n,vec,currPos+'R');
    printPathUtils(arr,i,j-1,n,vec,currPos+'L');
    printPathUtils(arr,i-1,j,n,vec,currPos+'U');
    arr[i][j] = 1;
}

vector<string> printPath(int arr[MAX][MAX],int n) {
    vector<string> vec;
    vec.clear();
    printPathUtils(arr,0,0,n,vec,"");
    return vec;
}

void solve() 
{ 
    int n;
    cin >> n;
    int arr[MAX][MAX];
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> arr[i][j];
        }
    }
    vector<string> vec = printPath(arr,n);
    if(!vec.size()) {
        cout << -1;
    }
    else {
        for(int i=0;i<vec.size();i++) {
            cout << vec[i] << ' ';
        }
    }
} 