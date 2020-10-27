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
//cin>>t; 
while(t--) 
{ 
	solve(); 
	cout<<"\n"; 
} 

cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
return 0; 
} 

ll algo1(ll arr[],ll n)
{
	map<ll,ll> mp;
	for(ll i=0;i<n;i++)
	{
		if(mp[arr[i]] == 1)
			return arr[i];
		mp[arr[i]] = 1;
	}
	return -1;
}

ll algo2(ll arr[],ll n)
{
	for(ll i=0;i<n;i++)
    {
        if(arr[abs(arr[i])] < 0)
            return abs(arr[i]);
        arr[abs(arr[i])] *= -1;
    }
    return -1;
}

void solve() 
{ 
	ll n;
	cin >> n;
	ll arr[n];
	for(ll i=0;i<n;i++)
		cin >> arr[i];
	cout << algo2(arr,n);
} 
