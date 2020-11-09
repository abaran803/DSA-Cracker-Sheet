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

void algo(string str,string pat)
{
	map<char,int> mp;
	vector<pair<char,int>> vec;
	int j=0;
	for(int i=0;i<str.length();i++)
	{
		vec.push_back({str[i],mp[str[i]]});
		mp[str[i]]++;
	}
	for(auto i:vec)
	{
		cout << i.first << ' ' << i.second << endl;
	}
}

void solve() 
{ 
	string s,q;
	cin >> s >> q;
	algo(s,q);
	// cout << "Hi" << endl;
} 