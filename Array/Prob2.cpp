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

struct Pair
{
	ll min;
	ll max;
};

Pair findminmax(ll arr[],ll n)
{
	Pair q = Pair();
	q.max = q.min = arr[0];
	for(ll i=1;i<n;i++)
	{
		if(arr[i]>q.max)
			q.max = arr[i];
		if(arr[i]<q.min)
			q.min = arr[i];
	}
	return q;
}

Pair MaxMin(ll arr[],ll s,ll e)
{
	Pair q,r,t;
	if(s == e)
	{
		q.min = arr[s];
		q.max = arr[s];
		return q;
	}
	if(e == s+1)
	{
		if(arr[s]>arr[e])
		{
			q.max = arr[s];
			q.min = arr[e];
		}
		else
		{
			q.min = arr[s];
			q.max = arr[e];
		}
		return q;
	}
	ll mid = (s+e)/2;
	q = MaxMin(arr,s,mid);
	r = MaxMin(arr,mid+1,e);
	t.min = min(q.min,r.min);
	t.max = max(q.max,r.max);
	return t;
}

// Best Method
Pair getMinMax(ll arr[],ll n)
{
	Pair p = Pair();
	ll i;

	// when no. of element is even
	if(n%2 == 0)
	{
		if(arr[0]>arr[1])
		{
			p.max = arr[0];
			p.min = arr[1];
		}
		else
		{
			p.min = arr[0];
			p.max = arr[1];
		}
		i = 2;
	}
	// when no. of element is odd
	else
	{
		p.min = arr[0];
		p.max = arr[0];
		i = 1;
	}
	while(i < n-1)
	{
		if(arr[i] < arr[i+1])
		{
			if(arr[i] < p.min)
				p.min = arr[i];
			if(arr[i+1] > p.max)
				p.max = arr[i+1];
		}
		else
		{
			if(arr[i+1] < p.min)
				p.min = arr[i+1];
			if(arr[i] > p.max)
				p.max = arr[i];
		}
		i+=2;
	}
	return p;
}

void solve() 
{ 
	ll n;
	cin >> n;
	ll arr[n];
	for(ll i=0;i<n;i++)
		cin >> arr[i];
	// Pair q = findminmax(arr,n);
	// Pair q = MaxMin(arr,0,n-1);
	Pair q = getMinMax(arr,n);
	cout << "Minimum: " << q.min << "\n" << "Maximum: " << q.max;
} 
