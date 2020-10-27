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

void algo2(ll arr[],ll n)
{
	for(ll i=0,j=n-1;i <= j;)
	{
		if(arr[i] < 0 && arr[j] < 0)
			i++;
		else if(arr[i] < 0 && arr[j] > 0)
			swap(arr[i++],arr[j--]);
		else if(arr[i] > 0 && arr[j] > 0)
			j--;
	}
}

void algo1(ll arr[],ll n)
{
	ll neg = 0;
	for(ll p2 = 0;p2 < n;p2++)
		if(arr[p2] < 0)
			swap(arr[neg++],arr[p2]);
}

void solve() 
{ 
	ll n;
	cin >> n;
	ll arr[n];
	for(ll i=0;i<n;i++)
		cin >> arr[i];
	// algo1(arr,n);
	algo2(arr,n);
	for(ll i=0;i<n;i++)
		cout << arr[i] << " ";
} 