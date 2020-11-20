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

int algo(string str)
{
	map<char,int> mp;
	mp['I'] = 1;
	mp['V'] = 5;
	mp['X'] = 10;
	mp['L'] = 50;
	mp['C'] = 100;
	mp['D'] = 500;
	mp['M'] = 1000;
	int temp = 0;
	int tot = 0;
	if(str.length() == 0)
		return 0;
	temp += mp[str[0]];
	for(int i=1;i<str.length();i++)
	{
		if(mp[str[i]]>mp[str[i-1]])
		{
			temp -= mp[str[i-1]];
			temp += (mp[str[i]]-mp[str[i-1]]);
		}
		else
			temp += mp[str[i]];
	}
	return temp;
}

void solve() 
{ 
	string str;
	cin >> str;
	cout << algo(str);
} 