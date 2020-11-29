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

void solve() 
{ 
	int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin >> arr[i];
	sort(arr,arr+n);
	int q;
	cin >> q;
	for(int i=0;i<q;i++)
	{
		int m;
		cin >> m;
		int count = 0;
		int sum = 0;
		for(int j=0;j<n;j++)
		{
			if(arr[j]<=m)
			{
				count++;
				sum += arr[j];
			}
			else
				break;
		}
		cout << count << ' ' << sum << endl;
	}
} 