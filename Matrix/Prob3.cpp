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

int algo(int **arr,int m,int n)
{
	int mini = INT_MAX,maxi = INT_MIN;
	for(int i=0;i<m;i++)
	{
		mini = min(mini,arr[i][0]);
		maxi = max(mini,arr[i][n-1]);
	}
	while(mini<maxi)
	{
		// +1 is used b/c in upper bound we skip the required element
		// so during traversal upper bound we get all number before it and +1
		// and due to odd we get 0.5 and after adding 1 we get 0.5+0.5=1
		int des = (m*n+1)/2;
		// To get element at the middle of mini and maxi
		int mid = (maxi+mini)/2;
		int val = 0;
		// Getting no. of element before mid, it should (m*n+1)/2
		for(int i=0;i<m;i++)
			val += upper_bound(arr[i],arr[i]+n,mid)-arr[i];
		if(val<des)
			mini = mid+1;
		else
			maxi = mid;
	}
	return mini;
}

void solve() 
{ 
	int m,n;
	cin >> m >> n;
	int **arr = new int*[m];
	for(int i=0;i<m;i++)
		arr[i] = new int[n];
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin >> arr[i][j];
	cout << algo(arr,m,n);
} 