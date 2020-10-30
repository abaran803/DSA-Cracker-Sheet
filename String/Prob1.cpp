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

void algo1(vector<char> &s,int l,int r)
{
	if(l<r)
	{
		swap(s[l],s[r]);
		algo1(s,l+1,r-1);
	}
}

void solve() 
{ 
	vector<char> vec;
	int n;
	cin >> n;
	char a;
	for(int i=0;i<n;i++)
	{
		cin >> a;
		vec.push_back(a);
	}
	algo1(vec,0,n-1);
	for(int i=0;i<n;i++)
		cout << vec[i] << ' ';
} 