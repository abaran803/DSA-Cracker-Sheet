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

bool algo1(int arr[],int k,int n)
{
	sort(arr,arr+n);
	int j = n-1;
	while(arr[j]+arr[0] > k)
		j--;
	n = j+1;
	for(int i=0;i<n-2;i++)
		for(int j=i+1;j<n;j++)
		{
			if(binary_search(arr,arr+n,k-arr[i]-arr[j]))
			{
				int m = lower_bound(arr,arr+n,k-arr[i]-arr[j])-arr;
				if(m != i && m != j)
					return 1;
			}
		}
	return 0;

}

bool algo2(int arr[],int k,int n)
{
	sort(arr,arr+n);
	for(int i=0;i<n;i++)
	{
		int a=i+1;
		int b = n-1;
		while(a < b)
		{
			if(arr[i]+arr[a]+arr[b] < k)
				a++;
			else if(arr[i]+arr[a]+arr[b] > k)
				b--;
			else
				return 1;
		}
	}
	return 0;
}

bool algo3(int arr[],int k,int n)
{
	map<int,int> mp;
	for(int i=0;i<n;i++)
		mp[arr[i]] = i+1;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			if(mp[k-arr[i]-arr[j]] != 0 && mp[k-arr[i]-arr[j]] != i+1 && mp[k-arr[i]-arr[j]] != j+1)
				return 1;
	return 0;
}

void solve() 
{ 
	int n,k;
	cin >> n >> k;
	int arr[n];
	for(int i=0;i<n;i++)
		cin >> arr[i];
	cout << algo3(arr,k,n);
} 