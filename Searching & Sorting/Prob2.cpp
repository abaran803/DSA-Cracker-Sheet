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

int piv(vector<int> vec,int target,int low,int high)
{
	if(low>high)
		return -1;
	if(low==high)
		return low;
	int mid = (low+high)/2;
	if(mid<high && vec[mid+1]<vec[mid])
		return mid;
	if(mid>low && vec[mid-1]>vec[mid])
		return mid-1;
	if(vec[low]>vec[mid])
		return piv(vec,target,low,mid-1);
	return piv(vec,target,mid+1,high);
}

int binary_search(vector<int> arr,int low,int high,int target)
{
	if(high < low)
		return -1;
	int mid = (low+high)/2;
	if(arr[mid] == target)
		return mid;
	if(arr[mid]>target)
		return binary_search(arr,low,mid-1,target);
	return binary_search(arr,mid+1,high,target);
}

int pivSearch(vector<int> vec,int target)
{
	int pivot = piv(vec,target,0,vec.size()-1);
	if(pivot == -1)
		binary_search(vec,0,vec.size()-1,target);
	if(vec[pivot] == target)
		return pivot;
	if(vec[0]<=target)
		return binary_search(vec,0,pivot-1,target);
	return binary_search(vec,pivot+1,vec.size()-1,target);
}

void solve() 
{ 
	vector<int> vec;
	int n,q;
	cin >> n >> q;
	for(int i=0;i<n;i++)
	{
		int a;
		cin >> a;
		vec.push_back(a);
	}
	cout << pivSearch(vec,q);
} 