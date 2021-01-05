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

int Precidence(char c) {
	if(c == '^') {
		return 3;
	} else if(c == '*' || c == '/') {
		return 2;
	}
	return 1;
}

bool isOperand(char c) {
	return ((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9'));
}

string ITP(string str) {
	string str1;
	stack<char> st;
	for(int i=0;i<str.length();i++) {
		if(isOperand(str[i])) {
			str1.push_back(str[i]);
		} else if(str[i] == '(') {
			st.push(str[i]);
		} else if(st.empty()) {
			st.push(str[i]);
		} else if(Precidence(str[i]) > Precidence(st.top())) {
			st.push(str[i]);
		} else if(Precidence(str[i]) <= Precidence(st.top())) {
			while(!st.empty()) {
				if(Precidence(str[i]) > Precidence(st.top())) {
					break;
				}
				str1.push_back(st.top());
				st.pop();
			}
			st.push(str[i]);
		} else if(str[i] == ')') {
			while(st.top() != '(') {
				str1.push_back(st.top());
				st.pop();
			}
			st.pop();
		}
	}
	while(!st.empty()) {
		str1.push_back(st.top());
		st.pop();
	}
	return str1;
}

void solve() 
{ 
	string str;
	cin >> str;
	str = ITP(str);
	cout << str;
} 