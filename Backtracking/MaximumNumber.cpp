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

void Algo(string str,int x,int k,string &maxi) {
    if(!k) {
        return;
    }
    int maxx = str[x];
    for(int i=x+1;i<str.length();i++) {
        if(str[i]>maxx) {
            maxx = str[i];
        }
    }
    if(maxx > str[x]) {
        k--;
    }
    for(int i=x;i<str.length();i++) {
        if(str[i] == maxx) {
            swap(str[i],str[x]);
            if(str.compare(maxi) > 0) {
                maxi = str;
            }
            Algo(str,x+1,k,maxi);
            swap(str[i],str[x]);
        }
    }
}

void solve() 
{ 
    int k;
    cin >> k;
    string str;
    cin >> str;
    string maxi = str;
    Algo(str,0,k,maxi);
    cout << maxi;
} 