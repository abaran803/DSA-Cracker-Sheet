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

void algo(int **arr,int n)
{
	int i=0;
	int p1=i+1,p2=i+1;
	while(i<n && (p1<n || p2<n))
	{
		if(arr[i][p1]<=arr[p2][i] || (p1<n && p2>=n))
			cout << arr[i][p1++] << ' ';
		if(arr[i][p1]>arr[p2][i] || (p2<n && p1>=n))
			cout << arr[p2++][i] << ' ';
		// else
		// {
			i++;
			p1 = i+1;
			p2 = i+1;
		// }
	}
}

void solve() 
{ 
	int n;
	cin >> n;
	int **arr = new int*[n];
	for(int i=0;i<n;i++)
		arr[i] = new int[n];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin >> arr[i][j];
	algo(arr,n);
} 