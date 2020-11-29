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
	// cin>>t; 
	while(t--) 
	{ 
		solve(); 
		cout<<"\n"; 
	} 
	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
	return 0; 
} 

int algo(int arr[],int n,int sum)
{
	int count = 0;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			for(int k=j+1;k<n;k++)
				if(arr[i]+arr[j]+arr[k]<sum)
					count++;
	return count;
}

int algo2(int arr[],int n,int sum)
{
	sort(arr,arr+n);
	int count = 0;
	for(int i=0;i<n;i++)
	{
		int j=i+1;
		int k=n-1;
		while(k>j)
		{
			if(arr[i]+arr[j]+arr[k]<sum)
			{
				count+=(k-j);
				j++;
			}
			else
				k--;
		}
	}
	return count;
}

void solve() 
{ 
	int n,sum;
	cin >> n >> sum;
	int arr[n];
	for(int i=0;i<n;i++)
		cin >> arr[i];
	cout << algo2(arr,n,sum);
} 