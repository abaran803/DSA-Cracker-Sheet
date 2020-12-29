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

bool isSafe(bool graph[101][101],int i,int colour,int n,int color[]) {
    for(int j=0;j<n;j++) {
        if(graph[i][j] && color[j] == colour) {
            return false;
        }
    }
    return true;
}

bool graphColoringUtils(bool graph[101][101],int x,int m,int V,int color[]) {
    if(x == V) {
        return true;
    }
    for(int i=1;i<=m;i++) {
        if(isSafe(graph,x,i,V,color)) {
            color[x] = i;
            if(graphColoringUtils(graph,x+1,m,V,color)) {
                return true;
            }
            color[x] = 0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int V) {
    int color[V];
    for(int i=0;i<V;i++) {
        color[i] = 0;
    }
    bool b = graphColoringUtils(graph,0,m,V,color);
    return b;
}

void solve() 
{ 
    int n,m,e;
    cin >> n >> m >> e;
    bool arr[101][101];
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            arr[i][j] = 0;
        }
    }
    for(int i=0;i<e;i++) {
        int a,b;
        cin >> a >> b;
        arr[a-1][b-1] = 1;
        arr[b-1][a-1] = 1;
    }
    cout << graphColoring(arr,m,n);
} 