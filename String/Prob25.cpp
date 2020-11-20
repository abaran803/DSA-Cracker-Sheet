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

// int algo(string str)
// {
// 	int count = 0;
// 	int num = 0;
// 	for(int i=0;i<str.length();i++)
// 	{
// 		if(num == 0 && str[i] == ']')
// 			count++;
// 		else
// 		{
// 			if(str[i] == '[')
// 				num++;
// 			else
// 				num--;
// 		}
// 	}
// 	return ceil(count/2.0)+ceil(num/2.0);
// }

// void solve() 
// { 
// 	int n;
// 	cin >> n;
// 	string str;
// 	cin >> str;
// 	cout << algo(str);
// } 