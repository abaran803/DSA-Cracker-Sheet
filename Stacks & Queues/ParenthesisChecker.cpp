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

bool Algo(string str) {
    stack<char> st;
    for(int i=0;i<str.length();i++) {
        if(str[i] == '(' || str[i] == '{' || str[i] == '[') {
            st.push(str[i]);
        } else if(!st.empty()) {
            if(str[i] == ')' && st.top() == '(') {
                st.pop();
            }
            else if(str[i] == '}' && st.top() == '{') {
                st.pop();
            }
            else if(str[i] == ']' && st.top() == '[') {
                st.pop();
            }
            else {
                return false;
            }
        } else {
            return false;
        }
    }
    if(st.empty()) {
        return true;
    } else {
        return false;
    }
}

void solve() 
{ 
    string str;
    cin >> str;
    if(Algo(str)) {
        cout << "true";
    } else {
        cout << "false";
    }
} 