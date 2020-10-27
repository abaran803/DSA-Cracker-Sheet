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

ll algo1(ll arr[],ll n,ll arr1[],ll m)
{
	map<ll,ll> mp;
	ll count = 0;
	for(ll i=0;i<n;i++)
	{
		if(mp[arr[i]] != 1)
		{
			mp[arr[i]] = 1;
			count++;
		}
	}
	for(ll i=0;i<m;i++)
	{
		if(mp[arr1[i]] != 1)
		{
			mp[arr1[i]] = 1;
			count++;
		}
	}
	return count;
}

void solve() 
{ 
	ll n,m;
	cin >> n >> m;
	ll arr[n];
	for(ll i=0;i<n;i++)
		cin >> arr[i];
	ll arr1[m];
	for(ll i=0;i<m;i++)
		cin >> arr1[i];
	sort(arr,arr+n);
	sort(arr1,arr1+m);
	ll count = algo1(arr,n,arr1,m);
	cout << count;
} 
