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
	//cin>>t; 
	while(t--) 
	{ 
		solve(); 
		cout<<"\n"; 
	} 
	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
	return 0; 
} 

int cnt = 0;

void merge(int arr[],int l,int mid,int h)
{
	int i=l,j=mid+1;
	int k = 0;
	int arr1[h-l+1];
	while(i<=mid && j<=h)
	{
		if(arr[i]<=arr[j])
			arr1[k++] = arr[i++];
		else
		{
			arr1[k++] = arr[j++];
			cnt += (mid-i+1);
		}
	}
	while(i<=mid)
		arr1[k++] = arr[i++];
	while(j<=h)
		arr1[k++] = arr[j++];
	for(i=0,j=l;i<k;i++,j++)
		arr[j] = arr1[i];
}

void sortt(int arr[],int l,int h)
{
	if(l >= h)
		return;
	int mid = (l+h)/2;
	sortt(arr,l,mid);
	sortt(arr,mid+1,h);
	merge(arr,l,mid,h);
}

void algo(int arr[],int n)
{
	sortt(arr,0,n-1);
}

void solve() 
{ 
	int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin >> arr[i];
	algo(arr,n);
	cout << cnt;
} 