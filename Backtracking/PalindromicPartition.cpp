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

bool isPal(string str) {
    int n = str.length();
    for(int i=0,j=n-1;i<j;i++,j--) {
        if(str[i] != str[j]) {
            return false;
        }
    }
    return true;
}

void Algo(string curr,string str,int x,vector<string> &vec) {
    if(!str.length()) {
        vec.push_back(curr);
        return;
    }
    int n = str.length();
    for(int i=1;i<=n-x;i++) {
        // cout << str.substr(x,i) << endl;
        if(isPal(str.substr(x,i))) {
            Algo(curr+str.substr(x,i)+" ",str.substr(x+i,n-(x+i-1)),0,vec);
        }
    }
}

void solve() 
{ 
    string str;
    cin >> str;
    vector<string> vec;
    Algo("",str,0,vec);
    for(string it: vec) {
        cout << it << endl;
    }
} 