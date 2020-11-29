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

// int algo(vector<int> arr,int n)
// {
// 	int count = 0;
// 	for(int i=0;i<n;i++)
// 		if(arr[i] == 0)
// 			count++;
// 	for(int i=1;i<n;i++)
// 		arr[i] = arr[i]+arr[i-1];
// 	for(int i=0;i<n;i++)
// 		cout << arr[i] << ' ';
// 	cout << endl;
// 	for(int i=0;i<n;i++)
// 		for(int j=i+1;j<n;j++)
// 			if(arr[i] == arr[j] && j-i >= 2)
// 				count++;
// 	return count;
// }

// void solve() 
// { 
// 	int n;
// 	cin >> n;
// 	vector<int> vec;
// 	for(int i=0;i<n;i++)
// 	{
// 		int a;
// 		cin >> a;
// 		vec.push_back(a);
// 	}
// 	cout << algo(vec,n);
// } 