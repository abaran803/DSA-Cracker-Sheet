// Integer Overflow

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
// 	//cin>>t; 
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
// 	int n;
// 	cin >> n;
// 	int arr[n];
// 	for(int i=0;i<n;i++)
// 		cin >> arr[i];
// 	int curMa = arr[0];
// 	int curMi = arr[0];
// 	int preMa = arr[0];
// 	int preMi = arr[0];
// 	int res = arr[0];
// 	for(int i=1;i<n;i++)
// 	{
// 		// if(preMa == 0 && preMi == 0)
// 		// {
// 		// 	preMi = arr[i];
// 		// 	preMa = arr[i];
// 		// }
// 		curMa = max(max(preMi*arr[i],preMa*arr[i]),arr[i]);
// 		curMi = min(min(preMi*arr[i],preMa*arr[i]),arr[i]);
// 		res = max(res,curMa);
// 		preMa = max(curMa,preMa);
// 		preMi = min(curMi,preMi);
// 		cout << arr[i] << " " << preMi << " " << preMa << " " << res << " ~~\n";
// 	}
// 	cout << res << endl;
// } 