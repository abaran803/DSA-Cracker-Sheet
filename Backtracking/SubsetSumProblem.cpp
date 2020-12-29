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

void equalPartitionUtils(int arr[],int x,int curr,int res,bool &isCorr,int n) {
    if(x == n) {
        if(curr == res) {
            isCorr = true;
        }
        return;
    }
    if(!isCorr) {
        if(x+1 < n)
            equalPartitionUtils(arr,x+1,curr+arr[x+1],res,isCorr,n);
        equalPartitionUtils(arr,x+1,curr,res,isCorr,n);
    }
}

int equalPartition(int N, int arr[]) {
    bool isCorr = false;
    int res = 0;
    for(int i=0;i<N;i++) {
        res += arr[i];
    }
    if(res&1) {
        return false;
    }
    res /= 2;
    equalPartitionUtils(arr,0,0,res,isCorr,N);
    if(!isCorr) {
        return false;
    } else {
        return true;
    }
}

void solve() 
{ 
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    if(equalPartition(n,arr)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
} 