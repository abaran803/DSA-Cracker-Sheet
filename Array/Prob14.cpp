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

ll Merge(ll *arr,ll *temp,ll l,ll mid,ll r)
{
	ll i = l;
	ll j = mid+1;
	ll k = l;
	ll inv = 0;
	while(i <= mid && j <= r)
	{
		if(arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else
		{
			inv += (mid+1-i);
			temp[k++] = arr[j++];
		}
	}
	while(i <= mid)
		temp[k++] = arr[i++];
	while(j <= r)
		temp[k++] = arr[j++];
	return inv;
}

ll MergeSort(ll *arr,ll *temp,ll l,ll r)
{
	ll inv = 0;
	if(l >= r)
		return inv;
	ll mid = (l+r)/2;
	inv += MergeSort(arr,temp,l,mid);
	inv += MergeSort(arr,temp,mid+1,r);
	inv += Merge(arr,temp,l,mid,r);
	for(ll i=l;i<=r;i++)
		arr[i] = temp[i];
	return inv;
}

void solve() 
{ 
	ll n;
	cin >> n;
	ll *arr = new ll[n];
	for(ll i=0;i<n;i++)
		cin >> arr[i];
	ll *temp = new ll[n];
	ll count = MergeSort(arr,temp,0,n-1);
	arr = temp;
	// for(ll i=0;i<n;i++)
	// 	cout << arr[i] << " ";
	// cout << endl;
	cout << count;
}