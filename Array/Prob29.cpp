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

void algo1(int arr[],int n,int a,int b)
{
	int p1 = 0,p2 = n-1;
	for(int i=0;i<=p2;)
	{
		if(arr[i] < a)
			swap(arr[p1++],arr[i++]);
		else if(arr[i]>b)
			swap(arr[i],arr[p2--]);
		else
			i++;
	}
}

void solve() 
{ 
	int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin >> arr[i];
	int a,b;
	cin >> a >> b;
	algo1(arr,n,a,b);
} 