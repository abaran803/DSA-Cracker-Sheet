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

void algo1(ll arr[],ll n)
{
	ll k = 0;
	ll p = 0;
	ll count = 0;
	while(p < n)
	{
		ll maxi = -1;
		ll ind;
		ll k;
		if(p+arr[p] >= n-1)
		{
			count++;
			break;
		}
		for(k=p+1;k<p+1+arr[p] && k<n;k++)
		{
			if(maxi <= arr[k])
			{
				maxi = arr[k];
				ind = k;
			}
		}
		count++;
		p = ind;
		if(maxi == 0)
		{
			count = -1;
			break;
		}
	}
	cout << count;
}

void solve() 
{ 
	ll n;
	cin >> n;
	ll arr[n];
	for(ll i=0;i<n;i++)
		cin >> arr[i];
	// cout << "Hey";
	algo1(arr,n);
} 
