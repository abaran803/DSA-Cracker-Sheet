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

bool algo1(int arr[],int arr1[],int n,int m)
{
	map<int,int> mp;
	for(int i=0;i<n;i++)
		mp[arr[i]] = 1;
	for(int i=0;i<m;i++)
		if(mp[arr1[i]] != 1)
			return false;
	return true;
}

bool algo2(int arr[],int arr1[],int n,int m)
{
	sort(arr,arr+n);
	for(int i=0;i<m;i++)
		if(!binary_search(arr,arr+n,arr1[i]))
			return false;
	return true;
}

void solve() 
{ 
	int n,m;
	cin >> n >> m;
	int arr[n],arr1[m];
	for(int i=0;i<n;i++)
		cin >> arr[i];
	for(int i=0;i<m;i++)
		cin >> arr1[i];
	if(algo2(arr,arr1,n,m))
		cout << "Yes";
	else 
		cout << "No";
} 