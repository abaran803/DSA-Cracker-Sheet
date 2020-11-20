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
	int c1 = 0,c2 = 0;
	for(int i=0;i<str.length();i++)
	{
		if(i%2 == 0)
		{
			if(str[i] == '1')
				c1++;
			else
				c2++;
		}
		else
		{
			if(str[i] == '0')
				c1++;
			else
				c2++;
		}
	}
	return min(c1,c2);
}

void solve() 
{ 
	string str;
	cin >> str;
	cout << algo(str);
} 