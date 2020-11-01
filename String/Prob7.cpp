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
	int n = str.length();
	int size = 0;
	for(int i=1;i<=n;i++)
	{
		string str1;
		for(int j=i;j<n;j++)
		{
			for(int k=i;k<=j;k++)
				str1 += str[i];
		}
	}
}

void solve() 
{ 
	int n;
	cin >> n;
	string str;
	cin >> str;
	cout << algo(str);
} 