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

struct Pair
{
	int rep;
	int no;
};

Pair algo(int *arr,int n)
{
	Pair p;
	for(int i=0;i<n;i++)
	{
		if(arr[abs(arr[i])-1] > 0)
			arr[abs(arr[i])-1] *= -1;
		else
			p.rep = abs(arr[i]);
	}
	for(int i=0;i<n;i++)
		if(arr[i] > 0)
		{
			p.no = i+1;
			break;
		}
	return p;
}

void solve() 
{ 
	int n;
	cin >> n;
	int *arr = new int[n];
	for(int i=0;i<n;i++)
		cin >> arr[i];
	Pair p = algo(arr,n);
	cout << p.rep << ' ' << p.no;
} 