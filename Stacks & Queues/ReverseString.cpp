// #include<bits/stdc++.h> 
#include<iostream>
#include<stack>
#include<cstdio>
#include<cstring>
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

char* Algo(char* str,int len) {
    stack<char> st;
    char *ch = str;
    for(int i=0;i<len;i++) {
        st.push(str[i]);
    }
    int i;
    char c[len+1];
    char* p = new char[len+1];
    for(i=0;i<len;i++) {
        c[i] = st.top();
        p[i] = c[i];
        st.pop();
    }
    p[i] = '\0';
    return p;
}

void solve() 
{ 
    char* str;
    str = "GeeksforGeeks";
    cout << Algo(str,13);
} 