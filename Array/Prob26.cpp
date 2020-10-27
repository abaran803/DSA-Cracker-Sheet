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

int algo1(int arr[],int n)
{
	int maxLeft[n] = {0};
	int maxRight[n] = {0};
	maxLeft[0] = arr[0];
	maxRight[n-1] = arr[n-1];
	for(int i=1;i<n;i++)
		maxLeft[i] = max(maxLeft[i-1],arr[i]);
	for(int i=n-2;i>=0;i--)
		maxRight[i] = max(maxRight[i+1],arr[i]);
	int tot = 0;
	for(int i=0;i<n;i++)
		if(arr[i] < maxLeft[i] && arr[i] < maxRight[i])
			tot += min(maxLeft[i]-arr[i],maxRight[i]-arr[i]);
	return tot;
}

int algo2(int arr[],int n)
{
	int i=0,j=n-1,ans=0;
	int lMax = 0,rMax = 0;
	while(i<=j)
	{
		if(arr[i]<arr[j])
		{
			if(arr[i]>lMax)
				lMax = arr[i];
			else
				ans += (lMax-arr[i]);
			i++;
		}
		else
		{
			if(arr[j]>rMax)
				rMax = arr[j];
			else
				ans += (rMax-arr[j]);
			j--;
		}
	}
	return ans;
}

int algo3(int arr[],int n)
{
	pair<int,int> prev;
	int tempWater = 0,totWater = 0;
	prev = {arr[0],0};
	for(int i=1;i<n;i++)
	{
		if(arr[i]>=prev.first)
		{
			prev = {arr[i],i};
			tempWater = 0;
		}
		else
		{
			totWater += (prev.first-arr[i]);
			tempWater += (prev.first-arr[i]);
		}
	}
	if(prev.second < n-1)
	{
		totWater -= tempWater;
		prev.first = arr[n-1];
		for(int i=n-1;i>=prev.second;i--)
		{
			if(arr[i] >= prev.first)
				prev.first = arr[i];
			else
				totWater += (prev.first-arr[i]);
		}
	}
	return totWater;
}

int algo4(int arr[],int n)
{
	stack<int> st;
	int res = 0;
	for(int i=0;i<n;i++)
	{
		while((!st.empty()) && (arr[i] > arr[st.top()]))
		{
			int ht = st.top();
			st.pop();
			if(st.empty())
				break;
			res += (i-st.top()-1)*(min(arr[st.top()],arr[i])-arr[ht]);
		}
		st.push(i);
	}
	return res;
}

void solve() 
{ 
	int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin >> arr[i];
	cout << algo4(arr,n);
}