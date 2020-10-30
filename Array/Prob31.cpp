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

int algo(int arr[],int n)
{
	int i=0,j=n-1,count=0;
	while(i<j)
	{
		if(arr[i]<arr[j])
		{
			i++;
			arr[i] = arr[i]+arr[i-1];
			count++;
		}
		else if(arr[i]>arr[j])
		{
			j--;
			arr[j] = arr[j]+arr[j+1];
			count++;
		}
		else
		{
			i++;
			j--;
		}
		// cout << arr[i] << ' ' << arr[j] << endl;
	}
	return count;
}

void solve() 
{ 
	int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin >> arr[i];
	cout << algo(arr,n);
} 