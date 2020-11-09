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
	cin>>t; 
	while(t--) 
	{ 
		solve(); 
		cout<<"\n"; 
	} 
	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
	return 0; 
} 

bool algo(string str)
{
	int n = str.length();
	stack<int> st;
	for(int i=0;i<n;i++){
		if(str[i] == '(' || str[i] == '{' || str[i] == '[')
			st.push(str[i]);
		if(st.empty())
			return false;
		if(str[i] == ')') {
			if(st.top() != '(')
				return false;
			st.pop();
		}
		else if(str[i] == '}') {
			if(st.top() != '{')
				return false;
			st.pop();
		}
		else if(str[i] == ']') {
			if(st.top() != '[')
				return false;
			st.pop();
		}
	}
	return st.empty();
}

void solve() 
{ 
	string str;
	cin >> str;
	if(algo(str))
		cout << "balanced";
	else
		cout << "not balanced";
} 