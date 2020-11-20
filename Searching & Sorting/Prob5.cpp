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

int algo2(int arr[],int n)
{
	sort(arr,arr+n);
	for(int i=0;i<n;i++)
	{
		int count = 0;
		int num = arr[i];
		int j = i;
		while(arr[j] == arr[i])
		{
			count++;
			j++;
		}
		i = -1;
		if(count > n/2)
			return arr[i];
	}
	return -1;
}

int algo(int arr[],int n)
{
	unordered_map<int,int> mp;
	for(int i=0;i<n;i++)
		mp[arr[i]]++;
	for(auto i:mp)
		if(i.second > n/2)
			return i.first;
	return -1;
}

void solve() 
{ 
	int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin >> arr[i];
	cout << algo(arr,n);
} 