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
	int **table = new int*[n];
	for(int i=0;i<n;i++)
		table[i] = new int[n];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			table[i][j] = 0;
	for(int i=0;i<n;i++)
		table[i][i] = 1;
	for(int i=0;i<n-1;i++)
		if(str[i] == str[i+1])
			table[i][i+1] = 1;
	for(int k=3;k<=n;k++)
	{
		for(int i=0;i<=n-k;i++)
		{
			int j = i+k-1;
			if(str[i] == str[j] && table[i+1][j-1] == 1)
				table[i][j] = 1;
		}
	}
	int count = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			// if(table[i][j] == 1)
				// count++;
			cout << table[i][j] << ' ';
		}
		cout << endl;
	}
	return count;
}

void solve() 
{ 
	string str;
	cin >> str;
	cout << algo(str);
	// cout << "Hi " << endl;
} 