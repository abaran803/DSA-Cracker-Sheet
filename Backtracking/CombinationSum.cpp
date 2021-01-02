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

void combinationSumUtils(vi arr,int curr,int x,int n,int b,vi vec,vector<vi> &vec1){
    if(curr > b) {
        return;
    }
    if(curr == b) {
        vec1.push_back(vec);
        return;
    }
    for(int i=x;i<n;i++) {
        vec.push_back(arr[i]);
        combinationSumUtils(arr,curr+arr[i],i,n,b,vec,vec1);
        vec.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> &A, int B)  {
    vi vec;
    sort(A.begin(),A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    vector<vi> vec1;
    combinationSumUtils(A,0,0,A.size(),B,vec,vec1);
    return vec1;
}

void solve() 
{ 
    int n;
    cin >> n;
    vi arr;
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    int b;
    cin >> b;
    vector<vi> vec = combinationSum(arr,b);
    for(int i=0;i<vec.size();i++) {
        for(int j=0;j<vec[i].size();j++) {
            cout << vec[i][j] << ' ';
        }
        cout << endl;
    }
} 
