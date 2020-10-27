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
	vector<int> vec;
	for(int i=0;i<n;i++)
		if(arr[i]<=k)
			vec.push_back(i);
	int m = 1;
	int mini = INT_MAX;
	for(int i=1;i<vec.size();i++)
	{
		if(vec[i]-vec[i+1]==(vec.size()-i))
			mini = min(mini,vec[i]-vec[i+1]);
		else if(vec[i]-vec[i+1]>(vec.size()-i))
			mini = min(mini,vec[i]-vec[i+1]) + m++;
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