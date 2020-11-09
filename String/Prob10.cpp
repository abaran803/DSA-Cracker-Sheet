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

int algo(string str)
{
	int c0 = 0, c1 = 0;
	int count = 0;
	for(int i=0;i<str.length();i++)
	{
		if(str[i] == '0')
			c0++;
		else
			c1++;
		if(c0 == c1)
			count++;
	}
	if(c0 != c1)
		return -1;
	return count;
}

void solve() 
{ 
	string str;
	cin >> str;
	cout << algo(str);
} 