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

void algo1(int **arr,int m,int n)
{
	int k=0,l=0;
	// K is first row of existing rectangle
	// L is first column of existing rectangle

	// When k == m || l == n then we will traverse the same array in next round
	// So exit in this situation
	while(k<m && l<n)
	{
		// Traverse the first array
		for(int i=l;i<n;i++)
			cout << arr[k][i] << ' ';
		// Remove the row by increasing position of first row
		k++;

		// Traverse the last coloumn
		for(int i=k;i<m;i++)
			cout << arr[i][n-1] << ' ';
		// Remove last coloumn by decreasing position of last column
		n--;

		if(k<n)
		{
			// traversing last row if the row is not same as first
			for(int i=n-1;i>=l;i--)
				cout << arr[m-1][i] << ' ';
			// Removing last row by decreasing m by 1
			m--;
		}

		if(l<m)
		{
			for(int i=m-1;i>=k;i--)
				cout << arr[i][l] << ' ';
			// Removing first column by increasing l by 1
			l++;
		}
	}
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
	algo1(arr,m,n);
} 