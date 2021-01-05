#include<bits/stdc++.h> 
#define int long long
#define endl '\n'

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
		cout<<"\n"; 
	} 
	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
	return 0; 
} 

int Calc(int a,int b,char c) {
	if(c == '+') {
		return a+b;
	} else if(c == '-') {
		return a-b;
	} else if(c == '*') {
		return a*b;
	} else if(c == '/') {
		return a/b;
	} return pow(a,b);
}

int evaluatePostfix(string &str) {
	stack<int> st;
	for(int i=0;i<str.length();i++) {
		if(str[i] >= '0' && str[i] <= '9') {
			st.push(str[i]-'0');
		} else {
			int val1 = st.top();
			st.pop();
			int val2 = st.top();
			st.pop();
			st.push(Calc(val2,val1,str[i]));
		}
	}
	return st.top();
}

void solve() 
{ 
	string str;
	cin >> str;
	cout << evaluatePostfix(str);
} 