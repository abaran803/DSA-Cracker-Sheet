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

vector<pair<int,int>> p;

bool IsExist(char **arr,int r,int c,int m,int n,string str)
{
	if(r >= 0 && r < m && c >= 0 && c < n && str[0] == arr[r][c])
	{
		int row[] = {-1,-1,-1,0,0,1,1,1};
		int col[] = {-1,0,1,-1,1,-1,0,1};
		for(int k=0;k<8;k++)
		{
			int start = 0;
			for(int i=r,j=c;i>=0 && i<m && j>=0 && j<n;i+=row[k],j+=col[k])
			{
				if(arr[i][j] != str[start] || start == str.length())
					break;
				start++;
			}
			if(start == str.length())
				return true;
		}
	}
	return false;
}

void algo(string str,char **arr,int m,int n)
{
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
		{
			int count = 0;
			count = IsExist(arr,i,j,m,n,str);
			// count = 1;
			if(count)
				p.push_back({i,j});
				// cout << i << ' ' << j << ',';
		}
}

void solve() 
{ 
	int m,n;
	cin >> m >> n;
	char **arr = new char*[m];
	for(int i=0;i<m;i++)
		arr[i] = new char[n];
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin >> arr[i][j];
	string str;
	cin >> str;
	algo(str,arr,m,n);
	if(p.empty())
		cout << -1;
	else
	{
		for(auto i:p)
			cout << i.first << ' ' << i.second << ", ";
		p.clear();
	}
}