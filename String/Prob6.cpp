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

void algo(string str)
{
	int maxi = 1;
	int init=0;
	int n = str.length();
	for(int i=0;i<n;i++)
		for(int j=i;j<n;j++)
		{
			int isPal = true;
			for(int k=0;k<(j-i+1)/2;k++)
			{
				if(str[i+k] != str[j-k])
					isPal = false;
			}
			if(isPal && (j-i+1)>maxi)
			{
				init = i;
				maxi = (j-i+1);
			}
		}
	for(int i=init;i<init+maxi;i++)
		cout << str[i];
	if(init != 0)
		cout << endl;
}

void algo2(string str)
{
	int n = str.length();
	int start = 0, maxi = 1;
	int **table = new int*[n];
	for(int i=0;i<n;i++)
		table[i] = new int[n];
	for(int i=0;i<n;i++)
		table[i][i] = 1;
	for(int i=0;i<n-1;i++)
	{
		if(str[i] == str[i+1])
		{
			table[i][i+1] = true;
			if(maxi<2)
			{
				start = i;
				maxi = 2;
			}
		}
	}
	for(int k=3;k<=n;k++)
	{
		for(int i=0;i<n-k+1;i++)
		{
			int j = i+k-1;
			if(table[i+1][j-1] == 1 && str[i] == str[j])
			{
				table[i][j] = true;
				if(k>maxi)
				{
					start = i;
					maxi = k;
				}
			}
		}
	}
	for(int i=start;i<start+maxi;i++)
		cout << str[i];
}

void solve() 
{ 
	string str;
	cin >> str;
	algo2(str);
} 