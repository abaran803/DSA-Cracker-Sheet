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

bool algo1(int **arr,int lR,int rR,int lC,int rC,int key)
{
	for(int i=lR;i<=rR;i++)
		for(int j=lC;j<=rC;j++)
			if(arr[i][j] == key)
				return true;
	return false;
}

bool algo2(int **arr,int m,int n,int key)
{
    if(m == 0)
        return false;
	int left = 0,right = m*n-1;
	int mid;
	while(left >= 0 && right < m*n && left<=right)
	{
		mid = (left+right)/2;
		if(arr[mid/n][mid%n] == key)
			return true;
		else if(arr[mid/n][mid%n] > key)
			right = mid-1;
		else
			left = mid+1;
	}
	return false;
}

bool algo3(int **arr,int m,int n,int key)
{
    if(m == 0)
        return false;
	pair<int,int> pos = {0,n-1};
	while(pos.second>=0 && pos.first<m)
	{
		if(arr[pos.first][pos.second] == key)
			return true;
		else if(arr[pos.first][pos.second] > key)
			pos.second--;
		else if(arr[pos.first][pos.second] < key)
			pos.first++;
	}
	return false;
}

void solve() 
{ 
	int m,n;
	cin >> m >> n;
	int **arr = new int*[m];
	for(int i=0;i<n;i++)
		arr[i] = new int[n];
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin >> arr[i][j];
	int key;
	cin >> key;
	// if(algo1(arr,0,m-1,0,n-1,key))
	if(algo2(arr,m,n,key))
		cout << "true";
	else
		cout << "false";
} 