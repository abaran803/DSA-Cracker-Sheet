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

bool algo(string str)
{
	map<char,int> mp;
	for(int i=0;i<str.length();i++)
		mp[str[i]]++;
	int k = ceil(str.length()/2.0);
	for(auto i:mp)
		if(i.second > k)
			return false;
	return true;
}

void solve() 
{ 
	string str;
	cin >> str;
	cout << algo(str);
} 