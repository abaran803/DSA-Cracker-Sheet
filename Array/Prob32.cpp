// Not Understand

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

// int algo1(int arr[],int arr1[],int n,int m)
// {
// 	int *arr2 = new int[m+n];
// 	int k=0,i=0,j=0;
// 	while(i<n && j<m)
// 		arr2[k++] = (arr[i]<arr1[j])?arr[i++]:arr1[j++];
// 	while(i<n)
// 		arr2[k++] = arr[i++];
// 	while(j<m)
// 		arr2[k++] = arr1[j++];
// 	if((n+m)%2 == 0)
// 		return (arr2[(n+m)/2]+arr2[((n+m)/2)-1])/2;
// 	return (arr2[(n+m)/2]);
// }

// void solve() 
// { 
// 	int n,m;
// 	cin >> n >> m;
// 	int arr[n],arr1[m];
// 	for(int i=0;i<n;i++)
// 		cin >> arr[i];
// 	for(int i=0;i<m;i++)
// 		cin >> arr1[i];
// 	cout << algo1(arr,arr1,n,m);
// } 