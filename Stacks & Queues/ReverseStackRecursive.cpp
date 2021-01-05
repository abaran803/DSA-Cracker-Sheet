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

void InsertAtBottom(stack<int> &st, int data) {
	if(st.empty()) {
		st.push(data);
		return;
	}
	int val = st.top();
	st.pop();
	InsertAtBottom(st,data);
	st.push(val);
}

void Reverse(stack<int> &st) {
	if(st.empty()) {
		return;
	}
	int val = st.top();
	st.pop();
	Reverse(st);
	InsertAtBottom(st,val);
}

void solve() 
{ 
	stack<int> st;
	int n;
	cin >> n;
	for(int i=0;i<n;i++) {
		int a;
		cin >> a;
		st.push(a);
	}
	Reverse(st);
	while(!st.empty()) {
		cout << st.top() << ' ';
		st.pop();
	}
} 