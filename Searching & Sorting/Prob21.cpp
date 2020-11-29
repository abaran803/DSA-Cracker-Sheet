#include<bits/stdc++.h> 
#define int long long
#define endl '\n'

using namespace std; 
void solve(); 

int32_t main() 
{ 
	ios_base::sync_with_stdio(false);cin.tie(NULL); 

	// #ifndef ONLINE_JUDGE 
	// 	freopen("inp.txt", "r", stdin); 
	// 	freopen("err.txt", "w", stderr); 
	// 	freopen("out.txt", "w", stdout); 
	// #endif 

	int t=1; 
	// cin>>t; 
	while(t--) 
	{ 
		solve(); 
		cout<<"\n"; 
	} 
	// cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
	return 0; 
} 

bool isTrue(int arr[],int n,int m,int res)
{
	int sum = 0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]-res>0)
			sum += (arr[i]-res);
		if(sum >= m)
			return true;
	}
	return false;
}

int algo(int arr[],int n,int m)
{
	int s=0,e=INT_MIN;
	for(int i=0;i<n;i++)
		e = max(arr[i],e);
	int ans = -1;
	// cout << s << ' ' << e << " --\n";
	while(s <= e)
	{
		int mid = (s+e)/2;
		// cout << mid << " ~~\n";
		if(isTrue(arr,n,m,mid))
		{
			ans = max(mid,ans);
			// cout << ans << " ~~~~~~~~~~~\n";
			s = mid+1;
		}
		else
			e = mid-1;
		// cout << s << ' ' << e << " --\n";
	}
	return ans;
}

void solve() 
{ 
	int n,m;
	cin >> n >> m;
	int arr[n];
	for(int i=0;i<n;i++)
		cin >> arr[i];
	cout << algo(arr,n,m);
} 