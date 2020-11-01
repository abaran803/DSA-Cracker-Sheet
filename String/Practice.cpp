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

void DpAlgo(string str)
{
	int n = str.length();
	int **table = new int*[n];
	int st = 0,maxi = 1;
	for(int i=0;i<n;i++)
		table[i] = new int[n];
	for(int i=0;i<n;i++)
		table[i][i] = 1;
	for(int i=0;i<n-1;i++)
		if(str[i] == str[i+1])
		{
			table[i][i+1] = 1;
			if(maxi<2)
			{
				maxi = 2;
				st = i;
			}
		}
	for(int k=3;k<=n;k++)
	{
		for(int i=0;i<n-k+1;i++)
		{
			int j=i+k-1;
			if(table[i+1][j-1] == 1 && str[i] == str[j])
			{
				table[i][j] = 1;
				if(maxi<(j-i+1))
				{
					maxi = (j-i+1);
					st = i;
				}
			}
		}
	}
	for(int i=st;i<st+maxi;i++)
		cout << str[i];
}

void solve() 
{ 
	string str;
	cin >> str;
	DpAlgo(str);
} 