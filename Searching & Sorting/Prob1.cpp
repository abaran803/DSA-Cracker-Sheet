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

void solve() 
{ 
	int n,q;
	cin >> n >> q;
	int arr[n];
	for(int i=0;i<n;i++)
		cin >> arr[i];
	int first = -1;
	int last = -1;
	int j;
	for(int i=0;i<n;i++)
	{
		j = n-i-1;
		if(arr[i] == q && first == -1)
			first = i;
		if(arr[j] == q && last == -1)
			last = j;
		if(last != -1 && first != -1)
			break;
	}
	if(first == last && first == -1)
		cout << -1;
	else
		cout << first << ' ' << last;
} 