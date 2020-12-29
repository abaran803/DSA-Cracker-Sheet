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

void Algo(string str,string Dict[],int x,string curr,int n,vector<string> &vec) {
    if(x == str.length()) {
        curr = curr.substr(0,curr.length()-1);
        vec.push_back(curr);
        return;
    }
    for(int i=x;i<str.length();i++) {
        string temp = str.substr(x,i-x+1);
        if(find(Dict,Dict+n,temp) != Dict+n) {
            Algo(str,Dict,i+1,curr+temp+" ",n,vec);
        }
    }
}

void solve() 
{ 
    int n;
    cin >> n;
    vector<string> vec;
    string Dict[n];
    for(int i=0;i<n;i++) {
        cin >> Dict[i];
    }
    string str;
    cin >> str;
    Algo(str,Dict,0,"",n,vec);
    for(int i=0;i<vec.size();i++) {
        cout << '(' << vec[i] << ')';
    }
} 