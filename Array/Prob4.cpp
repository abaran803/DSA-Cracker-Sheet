#include<bits/stdc++.h> 
#define ll long long

using namespace std; 
void solve(); 
int main() 
{ 
ios_base::sync_with_stdio(false);cin.tie(NULL); 

#ifndef ONLINE_JUDGE 
freopen("inp.txt", "r", stdin); 
freopen("err.txt", "w", stderr); 
freopen("out.txt", "w", stdout); 
#endif 

ll t=1; 
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
	ll n;
	cin >> n;
	ll arr[n];
	for(ll i=0;i<n;i++)
		cin >> arr[i];
	ll p1 = 0;
	ll p2 = n-1;
	for(ll i=0;i<=p2;i++)
	{
		if(arr[i] == 0)
			swap(arr[p1++],arr[i]);
		else if(arr[i] == 2)
			swap(arr[p2--],arr[i--]);
	}
	for(ll i=0;i<n;i++)
		cout << arr[i] << " ";
} 
