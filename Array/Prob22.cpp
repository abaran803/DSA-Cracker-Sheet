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

int algo1(int arr[],int n)
{	
	sort(arr,arr+n);
	int maxi = 0;
	int k = 0;
	for(int i=1;i<n;i++)
	{
		if(arr[i]-arr[i-1] != 0)
		{
			if(arr[i]-arr[i-1] == 1)
				k++;
			else
			{
				maxi = max(maxi,k);
				k = 0;
			}
		}
	}
	maxi = max(maxi,k);
	return maxi+1;
}

int algo2(int arr[],int n)
{
	unordered_set<int> st;
	for(int i=0;i<n;i++)
		st.insert(arr[i]);
	int res = 0;
	for(int i=0;i<n;i++)
	{
		if(st.find(arr[i]-1) == st.end())
		{
			int j = arr[i];
			while(st.find(j) != st.end())
				j++;
			res = max(res,j-arr[i]);
		}
	}
	return res;
}

void solve() 
{ 
	int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin >> arr[i];
	cout << algo2(arr,n);
} 