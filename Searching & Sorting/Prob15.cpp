// Error

// #include<bits/stdc++.h> 
// #define int long long
// #define endl '\n'

// using namespace std; 
// void solve(); 

// int32_t main() 
// { 
// 	ios_base::sync_with_stdio(false);cin.tie(NULL); 

// 	#ifndef ONLINE_JUDGE 
// 		freopen("inp.txt", "r", stdin); 
// 		freopen("err.txt", "w", stderr); 
// 		freopen("out.txt", "w", stdout); 
// 	#endif 

// 	int t=1; 
// 	cin>>t; 
// 	while(t--) 
// 	{ 
// 		solve(); 
// 		cout<<"\n"; 
// 	} 
// 	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
// 	return 0; 
// } 

// void solve() 
// { 
// 	set<int> st;
// 	int n,q;
// 	cin >> n >> q;
// 	while(n--)
// 	{
// 		int a,b;
// 		cin >> a >> b;
// 		for(int i=a;i<=b;i++)
// 			st.insert(i);
// 	}
// 	int m = 3;
// 	auto it = st.begin();
// 	for(int i=0;i<m;i++)
// 	{
// 		cout << *(st.begin()++);
// 	}
// 	cout << *(st.begin()) << ' ';
// 	// st.begin() = it;
// 	while(q--)
// 	{
// 		int k;
// 		cin >> k;
// 		// if(k-1<st.size())
// 		// 	cout << *(st.begin()+(k-1)) << endl;
// 		// else
// 		// 	cout << -1 << endl;
// 	}
// 	// for(int i:vec)
// 	// 	cout << i << ' ';
// 	// cout << endl;
// } 