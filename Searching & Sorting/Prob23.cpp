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

int isFound(int arr[],int mid,int totRot,int n) 
{
	int sum = 0;
	for(int i=0;i<n;i++)
	{
		int sum1 = 0;
		int j = 1;
		int count = 0;
		while(sum1+(j*arr[i]) <= mid)
		{
			count++;
			sum1 += (j*arr[i]);
			j++;
		}
		sum += count;
	}
	return sum;
}

int algo(int arr[],int l,int h,int totRot,int n)
{
	int best = -1;
	while(l<=h)
	{
		int mid = (l+h)/2;
		int p = isFound(arr,mid,totRot,n);
		if(p >= totRot)
		{
			best = mid;
			h = mid-1;
		}
		else
			l = mid+1;
	}
	return best;
}

void solve() 
{ 
	int totRot;
	cin >> totRot;
	int n;
	cin >> n;
	int arr[n];
	int maxi = INT_MIN;
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
		maxi = max(arr[i],maxi);
	}
	int sum = 0;
	int count = 0;
	int i = 1;
	while(count < totRot)
	{
		count++;
		sum += (i*maxi);
		i++;
	}
	cout << algo(arr,0,sum,totRot,n);
} 