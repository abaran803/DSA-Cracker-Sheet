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
// 	//cin>>t; 
// 	while(t--) 
// 	{ 
// 		solve(); 
// 		cout<<"\n"; 
// 	} 
// 	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
// 	return 0; 
// } 

// int cnt = 0;

// void algo(int arr[],int i,int l,int r,int n,int a,int b)
// {
// 	if(i > n)
// 		return;
// 	if(l>=a && l<=b)
// 		cnt++;
// 	algo(arr,i+1,l+arr[i],r-arr[i],n,a,b);
// 	algo(arr,i+1,l,r,n,a,b);
// }

// void solve() 
// { 
// 	int n,a,b;
// 	cin >> n >> a >> b;
// 	int arr[n];
// 	int sum = 0;
// 	for(int i=0;i<n;i++)
// 	{
// 		cin >> arr[i];
// 		sum += arr[i];
// 	}
// 	// sort(arr,arr+n);
// 	// int count = 0;
// 	// for(int i=0;i<n;i++)
// 	// 	for(int j=n-1;j>=i;j--)
// 	// 	{
// 	// 		if(arr[i]+arr[j]>=a && arr[i]+arr[j]<=b)
// 	// 		{
// 	// 			count += (j-i+1);
// 	// 			break;
// 	// 		}
// 	// 	}
// 	// if(0>=a && 0<=b)
// 	// 	count++;
// 	// cout << count;
// 	algo(arr,0,0,sum,n,a,b);
// 	cout << cnt/2;
// } 