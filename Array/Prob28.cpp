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

int algo1(int arr[],int n,int k)
{
	for(int i=1;i<n;i++)
		arr[i] = arr[i]+arr[i-1];
	int mini = INT_MAX;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			// cout << arr[i] << ' ' << arr[j] << " ~~" << endl;
			if(arr[j]-arr[i] > k)
			{
				// cout << i << ' ' << j << endl;
				mini = min(mini,j-i);
			}
		}
	}
	for(int i=0;i<n;i++)
		if(arr[i] > k)
		{
			// cout << i << endl;
			mini = min(mini,i+1);
		}
	return mini;
}

int algo2(int arr[],int n,int k)
{
	int start = 0,end = 0;
	int minLength = INT_MAX,cur = 0;
	while(end < n)
	{
		while(cur <= k && end < n)
			cur += arr[end++];
		while(cur > k && start < n)
		{
			minLength = min(minLength,(end-start));
			cur -= arr[start++];
		}
	}
	return minLength;
}

void solve() 
{ 
	int n,k;
	cin >> n >> k;
	int arr[n];
	for(int i=0;i<n;i++)
		cin >> arr[i];
	cout << algo2(arr,n,k);
} 