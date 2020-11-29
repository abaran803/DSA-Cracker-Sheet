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

int algo(int arr1[],int arr2[],int n,int m,int k)
{
	int *arr3 = new int[m+n];
	int p = 0;
	int i=0,j=0;
	while(i<n && j<m)
		arr3[p++] = (arr1[i]<arr2[j]) ? arr1[i++] : arr2[j++];
	while(i<n)
		arr3[p++] = arr1[i++];
	while(j<m)
		arr3[p++] = arr2[j++];
	return arr3[k-1];
}

int algo2(int arr1[],int arr2[],int n,int m,int k)
{
	int i=n-1,j=0;
	while(i>=0 && j<m)
	{
		if(arr1[i]>arr2[j])
			swap(arr1[i],arr2[j]);
		i--,j++;
	}
	sort(arr1,arr1+n);
	sort(arr2,arr2+m);
	if((k-1)<n)
	{
		cout << k-1 << ' ' << n << endl;
		return arr1[k-1];
	}
	else
	{
		cout << k-1 << endl;
		return arr2[(k-1)-n];
	}
	return -1;
}

int algo3(int arr1[],int arr2[],int n,int m,int k)
{
	int p = 0;
	int i=0,j=0,k1=0;
	while(i<n && j<m)
	{
		k1++;
		if(arr1[i]<arr2[j])
		{
			if(k == k1)
				return arr1[i];
			i++;
		}
		else
		{
			if(k == k1)
				return arr2[j];
			j++;
		}
	}
	while(i<n)
	{
		k1++;
		if(k == k1)
			return arr1[i];
		i++;
	}
	while(j<m)
	{
		k1++;
		if(k == k1)
			return arr2[j];
		j++;
	}
	return -1;
}

void solve() 
{ 
	int n,m,k;
	cin >> n >> m >> k;
	int arr1[n];
	int arr2[m];
	for(int i=0;i<n;i++)
		cin >> arr1[i];
	for(int i=0;i<m;i++)
		cin >> arr2[i];
	cout << algo3(arr1,arr2,n,m,k);
} 