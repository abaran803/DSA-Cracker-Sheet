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

void solve() 
{ 
	int n;
	cin >> n;
	map<string,int> mp;
	int maxi = INT_MIN;
	for(int i=0;i<n;i++)
	{
		string str;
		cin >> str;
		mp[str]++;
		maxi = max(maxi,mp[str]);
	}
	string res;
	int maxi1 = INT_MIN;
	for(auto i:mp)
	{
		if(i.second < maxi && i.second > maxi1)
		{
			maxi1 = i.second;
			res = i.first;
		}
	}
	cout << res;
} 