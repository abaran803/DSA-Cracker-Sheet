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

vector<vector<ll>> merge(vector<vector<ll>> intervals) 
{
	vector<vector<ll>> vec;
	ll initials = intervals[0][0];
	ll finals = intervals[0][1];
	for(ll i=1;i<intervals.size();i++)
	{
	    if(intervals[i][0] <= intervals[i-1][1])
	        finals = intervals[i][1];
	    else
	    {
	    	vec.push_back({initials,finals});
	        initials = intervals[i][0];
	        finals = intervals[i][1];
	    }
	}
	vec.push_back({initials,finals});
	return vec;
}

void solve() 
{ 
	ll n;
	cin >> n;
	vector<vector<ll>> vec;
	for(ll i=0;i<n;i++)
	{
		ll a,b;
		cin >> a >> b;
		vec.push_back({a,b});
	}
	vec = merge(vec);
	for(ll i=0;i<n;i++)
		cout << vec[i][0] << " " << vec[i][1] << endl;
}