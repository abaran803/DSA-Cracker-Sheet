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

void algo(int* arr,int n)
{
	int temp;
	int i = 0;
	int k = 0;
	for(i=n-2;i>=0;i--)
		if(arr[i]<arr[i+1])
			break;
	if(i == -1)
		sort(arr,arr+n);
	else
	{
		int j;
		for(j=n-1;j>i;j--)
			if(arr[j]>arr[i])
				break;
		swap(arr[i],arr[j]);
		sort(arr+i+1,arr+n);
	}
	for(int i=0;i<n;i++)
		cout << arr[i] << ' ';
}

void solve() 
{ 
	int n;
	cin >> n;
	int *arr = new int[n];
	for(int i=0;i<n;i++)
		cin >> arr[i];
	algo(arr,n);
} 