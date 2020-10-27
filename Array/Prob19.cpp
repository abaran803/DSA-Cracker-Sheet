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

void solve() 
{ 
	int n;
	cin >> n;
	int arr[n];
	int k = 0;
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
		k += arr[i];
		arr[i] = k;
	}
	bool isCorr = false;
	for(int i=0;i<n;i++)
	    if(arr[i] == 0)
	    {
	        isCorr = true;
	        break;
	    }
	if(!isCorr)
	{
    	for(int i=0;i<n-1;i++)
    	{
    		for(int j=i+1;j<n;j++)
    			if(abs(arr[j]-arr[i]) == 0)
    			{
    				isCorr = true;
    				break;
    			}
    		if(isCorr)
    		    break;
    	}
	}
	if(isCorr)
		cout << "Yes";
	else
		cout << "No";
} 