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

void algo(vector<int> &vec,int n)
{
	bool isZero = false;
	bool isDZero = false;
	int totProd = 1;
	for(int i=0;i<n;i++)
	{
		if(vec[i] == 0 && isZero)
			isDZero = true;
		if(vec[i] == 0)
			isZero = true;
		if(vec[i] != 0)
			totProd *= vec[i];
	}
	for(int i=0;i<n;i++)
	{
		if(isDZero)
			vec[i] = 0;
		else
		{
			if(vec[i] == 0)
				vec[i] = totProd;
			else
			{
				if(isZero)
					vec[i] = 0;
				else
					vec[i] = totProd/vec[i];
			}
		}
	}
}

void solve() 
{ 
	int n;
	cin >> n;
	vector<int> vec;
	for(int i=0;i<n;i++)
	{
		int a=0;
		cin >> a;
		vec.push_back(a);
	}
	algo(vec,n);
	for(int i=0;i<n;i++)
		cout << vec[i] << ' ';
} 