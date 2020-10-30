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
	int *arr1 = new int[n*n];
	int k=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			arr1[k++] = arr[i][j];
	sort(arr1,arr1+n*n);
	for(int i=0;i<n*n;i++)
		cout << arr1[i] << ' ';
}

void youngify(int **arr,int i,int j,int n)
{
	int down = (i+1<n)?arr[i+1][j]:INT_MAX;
	int right = (j+1<n)?arr[i][j+1]:INT_MAX;
	if(down==INT_MAX && right==INT_MAX)
		return;
	if(down<right)
	{
		arr[i][j]=arr[i+1][j];
		arr[i+1][j]=INT_MAX;
		youngify(arr,i+1,j,n);
	}
	else	
	{
		arr[i][j]=arr[i][j+1];
		arr[i][j+1]=INT_MAX;
		youngify(arr,i,j+1,n);
	}
}

int getMin(int **arr,int n)
{
	int data = arr[0][0];
	arr[0][0] = INT_MAX;
	youngify(arr,0,0,n);
	return data;
}

void algo2(int **arr,int n)
{
	for(int i=0;i<n*n;i++)
		cout << getMin(arr,n) << ' ';
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
	algo2(arr,n);
} 