#include<bits/stdc++.h> 
#define ll long long

using namespace std; 
void solve(); 
int main() 
{ 
ios_base::sync_with_stdio(false);cin.tie(NULL); 

#ifndef ONLINE_JUDGE 
freopen("inp.txt", "r", stdin); 
freopen("err.txt", "w", stderr); 
freopen("out.txt", "w", stdout); 
#endif 

ll t=1; 
//cin>>t; 
while(t--) 
{ 
	solve(); 
	cout<<"\n"; 
} 

cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
return 0; 
} 

void algo1(ll arr1[],ll arr2[],ll n, ll m)
{
	for(int i=0;i<n;i++)
	{
		if(arr1[i] > arr2[0])
		{
			swap(arr1[i],arr2[0]);
			int temp = arr2[0];
			int j;
			for(j=1;j<m;j++)
			{
			    if(arr2[j] < temp)
			        arr2[j-1] = arr2[j];
			    else
			    {
			        arr2[j-1] = temp;
			        break;
			    }
			}
			if(j == m)
				arr2[m-1] = temp;
		}
	}
}

void algo2(ll arr1[],ll arr2[],ll n, ll m)
{
	int x = n;
	    int y = m;
	    int i=x-1;
	    int j=0;
	    
	    for(;i>=0 && j<y; i--,j++){
	        
	        if(arr1[i]>=arr2[j]){
	            swap(arr1[i],arr2[j]);
	        }
	        else{
	            break;
	        }
	    }
	    
	    sort(arr1,arr1+x);
	    sort(arr2,arr2+y);
}

void solve() 
{ 
	ll n,m;
	cin >> n >> m;
	ll arr[n];
	for(ll i=0;i<n;i++)
		cin >> arr[i];
	ll arr1[m];
	for(ll i=0;i<m;i++)
		cin >> arr1[i];
	algo1(arr,arr1,n,m);
	for(ll i=0;i<n;i++)
		cout << arr[i] << " ";
	for(ll i=0;i<m;i++)
		cout << arr1[i] << " ";
} 
