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

int algo(int arr[],int n,int k)
{
	int mini = n+1;
	int cnt=0;
	for(int i=0;i<n;i++)
		if(arr[i]<=k)
			cnt++;
	int count = 0;
	for(int i=0;i<cnt;i++)
		if(arr[i]>k)
			count++;
	mini = min(mini,count);
	for(int i=cnt;i<n;i++)
	{
		if(arr[i-cnt] > k)
			count--;
		if(arr[i] > k)
			count++;
		mini = min(mini,count);
	}
	return mini;
}

void solve() 
{ 
	int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin >> arr[i];
	int k;
	cin >> k;
	cout << algo(arr,n,k);
}