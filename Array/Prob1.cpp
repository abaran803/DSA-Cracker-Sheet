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

void Reverse(ll arr[],ll s,ll e)
{
	for(ll i=s,j=e;i<j;i++,j--)
		swap(arr[i],arr[j]);
}

void ReverseRecursive(ll arr[],ll s,ll e)
{
	if(s<e)
	{
		swap(arr[s],arr[e]);
		ReverseRecursive(arr,s+1,e-1);
	}
}

void Print(ll arr[],ll n)
{
	for(ll i=0;i<n;i++)
		cout << arr[i] << " ";
}

void solve() 
{ 
	ll n;
	cin >> n;
	ll arr[n];
	for(ll i=0;i<n;i++)
		cin >> arr[i];
	// Reverse(arr,0,n-1);
	ReverseRecursive(arr,0,n-1);
	Print(arr,n);
} 
