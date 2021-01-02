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
    cin>>t; 
    while(t--) 
    { 
        solve(); 
        cout<<endl; 
    } 
    cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
    return 0; 
} 

void Algo(string str,int x,vector<string> &vec) {
    if(x == str.length()) {
        vec.push_back(str);
    }
    for(int i=x;i<str.length();i++) {
        swap(str[i],str[x]);
        Algo(str,x+1,vec);
        swap(str[i],str[x]);
    }
}

void solve() 
{ 
    string str;
    cin >> str;
    vector<string> vec;
    Algo(str,0,vec);
    sort(vec.begin(),vec.end());
    for(int i=0;i<vec.size();i++) {
        cout << vec[i] << ' ';
    }
} 