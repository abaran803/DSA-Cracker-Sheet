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
    cin>>t; 
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
    int n,k;
    cin >> n >> k;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];
    sort(arr,arr+n);
    int minCost = 0,maxCost = 0;
    int minSize = n,maxSize = n;
    for(int i=0;minSize > 0;i++)
    {
        minCost += arr[i];
        minSize -= k+1;
    }
    for(int i=n-1;maxSize > 0;i--)
    {
        maxCost += arr[i];
        maxSize -= k+1;
    }
    cout << minCost << ' ' << maxCost;
} 