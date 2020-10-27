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

void algo1(int arr[],int n)
{
	int pro[n] = {0};
	int maxi = arr[0];
	int mini = arr[0];
	for(int i=0;i<n;i++)
	{
		mini = min(mini,arr[i]);
		maxi = arr[i];
		pro[i] = maxi-mini;
	}
	for(int i=n-1;i>=0;i--)
	{
		mini = arr[i];
		maxi = max(maxi,arr[i]);
		pro[i] = max(pro[i-1],maxi-mini);
	}
	for(int i=0;i<n;i++)
		cout << pro[i] << " ";
}

void solve() 
{ 
	int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin >> arr[i];
	algo1(arr,n);
} 