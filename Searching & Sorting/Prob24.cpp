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
	while(1)
	{
		int n;
		cin >> n;
		// cout << "Hey\n";
		if(n == 0)
			break;
		int arr1[n];
		for(int i=0;i<n;i++)
			cin >> arr1[i];
		int m;
		cin >> m;
		int arr2[m];
		for(int i=0;i<m;i++)
			cin >> arr2[i];
		map<int,int> mp;
		for(int i=0;i<n;i++)
			mp[arr1[i]] = i+1;
		int ind = -1;
		int sum1 = 0;
		int sum2 = 0;
		int totVal = 0;
		for(int i=0;i<m;i++)
		{
			sum2 += arr2[i];
			if(mp[arr2[i]] != 0)
			{
				int j;
				for(j=ind+1;j<mp[arr2[i]];j++)
					sum1 += arr1[j];
				ind = mp[arr2[i]]-1;
				totVal += max(sum2,sum1);
				sum2 = 0;
				sum1 = 0;
			}
		}
		for(int j=ind+1;j<n;j++)
			sum1 += arr1[j];
		totVal += max(sum1,sum2);
		cout << totVal << endl;
	}
} 