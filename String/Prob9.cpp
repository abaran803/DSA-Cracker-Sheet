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

void algo(string str,int l,int r)
{
	if(l == r)
		cout << str << ' ';
	else
	{
		for(int i=l;i<=r;i++)
		{
			swap(str[i],str[l]);
			algo(str,l+1,r);
			swap(str[i],str[l]);
		}
	}
}

void solve() 
{ 
	string str;
	cin >> str;
	algo(str,0,str.length()-1);
} 