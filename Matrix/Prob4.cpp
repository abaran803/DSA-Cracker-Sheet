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

// Using upper bound
int algo(int **arr,int m,int n)
{
	int maxi = 0;
	int count;
	int ind = 0;
	for(int i=0;i<n;i++)
	{
	    count = m-(lower_bound(arr[i],arr[i]+n,1)-arr[i]);
	    // or we can use
	    // count = m-(upper_bound(arr[i],arr[i]+n,0)-arr[i]);
        if(maxi<count)
        {
            maxi = count;
            ind = i;
        }
	}
	return ind;
}

// Using binary search
int firstOne(int *arr,int left,int right)
{
	if(left>right)
		return right+1;
	int mid = (left+right)/2;
	if((mid == 0 || arr[mid-1] == 0) && arr[mid] == 1)
		return mid;
	else if(arr[mid] == 0)
		return firstOne(arr,mid+1,right);
	else
		return firstOne(arr,left,mid-1);
}

int algo2(int **arr,int m,int n)
{
	if(m == 0 || n == 0)
		return -1;
	int k = firstOne(arr[0],0,n-1);
	int ind=0;
	for(int i=1;i<m;i++)
	{
        if(k-1>=0 && arr[i][k-1]==1)
        {
            k = firstOne(arr[i],0,k);
            ind = i;
        }
	}
    if(k == m)
        return -1;
    return ind;
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
	cout << algo2(arr,m,n);
} 