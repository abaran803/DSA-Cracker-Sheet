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

int best = -1;

void algo(int arr[],int l,int h,int n,int c)
{
	if(h<l)
		return;
	int mid = (h+l)/2;
	int prev = arr[0];
	int val = 1;
	for(int i=1;i<n && val<c;i++)
	{
		if(arr[i]>=prev+mid)
		{
			val++;
			prev = arr[i];
		}
	}
	if(val < c)
		algo(arr,l,mid-1,n,c);
	else
	{
		if(val == c)
			best = mid;
		algo(arr,mid+1,h,n,c);
	}
}

void solve() 
{ 
	int n,c;
	cin >> n >> c;
	int arr[n];
	for(int i=0;i<n;i++)
		cin >> arr[i];
	sort(arr,arr+n);
	algo(arr,0,arr[n-1]-arr[0],n,c);
	cout << best;
} 