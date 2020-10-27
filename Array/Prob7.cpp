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
	ll temp = arr[n-1];
    for(ll i=n-1;i>0;i--)
        arr[i] = arr[i-1];
    arr[0] = temp;
    for(ll i=0;i<n;i++)
        cout << arr[i] << ' ';
}

void solve() 
{ 
	ll n;
	cin >> n;
	ll arr[n];
	for(ll i=0;i<n;i++)
	    cin >> arr[i];
	algo1(arr,n);
}