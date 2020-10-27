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

ll kaden_S(ll arr[],ll n)
{
	ll maxi = INT_MIN;
	ll tot = 0;
	for(ll i=0;i<n;i++)
	{
		tot += arr[i];
		if(maxi < tot)
			maxi = tot;
		if(tot < 0)
			tot = 0;
	}
	return maxi;
}

void solve() 
{
	ll n;
	cin >> n;
	ll arr[n];
	for(ll i=0;i<n;i++)
		cin >> arr[i];
	cout << kaden_S(arr,n);
}