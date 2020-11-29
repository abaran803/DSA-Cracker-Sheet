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

int algo(int arr[],int n,int q)
{
	int ans = -1;
	for(int i=0;i<n;i++)
	{
		int m = arr[i]+q;
		int j = 0;
		for(j=0;j<n;j++)
			if(arr[j] == m)
				return 1;
	}
	return -1;
}

int algo2(int arr[],int n,int q)
{
	for(int i=0;i<n;i++)
	{
		int m = arr[i]+q;
		if(binary_search(arr,arr+n,m))
			return 1;
	}
	return -1;
}

int algo3(int arr[],int n,int q)
{
	int n1 = 0,n2 = n-1;
	sort(arr,arr+n);
	while(n1<n && n2<n)
	{
		if(arr[n2]-arr[n1] == q)
			return 1;
		if(arr[n2]-arr[n1] > q)
			n1++;
		else if(arr[n2]-arr[n1] < q)
			n2--;
	}
	return -1;
}

void solve() 
{ 
	int n,q;
	cin >> n >> q;
	int arr[n];
	for(int i=0;i<n;i++)
		cin >> arr[i];
	cout << algo3(arr,n,q);
} 