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

int algo(int arr[],int n,int c)
{
	sort(arr,arr+n);
	int minDist = (arr[n-1]-arr[0]);
	while(1)
	{
		int m = c;
		int pos = arr[0];
		while(m--)
		{
			
		}
		if(m == 0)
			return mid;
		mid /= 2;
	}
}

void solve() 
{ 
	int n,c;
	cin >> n >> c;
	int arr[n];
	for(int i=0;i<n;i++)
		cin >> arr[i];
	cout << algo(arr,n,c);
} 