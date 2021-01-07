#include<bits/stdc++.h> 
#include"MaxHeap.h"
#include"MinHeap.h"
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
    // MinHeap h(n+1);
    Heap h(n+1);
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        h.push(a);
    }
    for(int i=0;i<n;i++) {
        h.pop();
    }
    h.TraverseHeapSort();
} 