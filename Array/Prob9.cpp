// Error !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// #include<bits/stdc++.h> 
// #define ll long long

// using namespace std; 
// void solve(); 
// int main() 
// { 
// ios_base::sync_with_stdio(false);cin.tie(NULL); 

// #ifndef ONLINE_JUDGE 
// freopen("inp.txt", "r", stdin); 
// freopen("err.txt", "w", stderr); 
// freopen("out.txt", "w", stdout); 
// #endif 

// ll t=1; 
// //cin>>t; 
// while(t--) 
// { 
// 	solve(); 
// 	cout<<"\n"; 
// } 

// cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
// return 0; 
// } 

// ll algo1(ll arr[],ll n,ll k)
// {
// 	// First smallest element
// 	ll s = arr[0]+k;

// 	// First largest element
// 	ll l = arr[n-1]-k;

// 	if(s>l)
// 		swap(s,l);

// 	// Difference b/w first largest and smallest element
// 	ll val = arr[n-1]-arr[0];

// 	// Traversing the array
// 	for(ll i=1;i<n-1;i++)
// 	{
// 		ll sub = arr[i]-k;
// 		ll add = arr[i]+k;
// 		// cout << sub << " " << add << " ~~" << endl;
// 		if(sub >= s || add <= l)
// 			continue;
// 		if(l-sub <= add-s)
// 			s = sub;
// 		else
// 			l = add;
// 		// cout << s << " " << l << " ~~~" << endl;
// 	}
// 	return min(val,l-s);
// }

// void solve() 
// { 
// 	ll n;
// 	cin >> n;
// 	ll arr[n];
// 	for(ll i=0;i<n;i++)
// 		cin >> arr[i];
// 	ll k;
// 	cin >> k;
// 	cout << algo1(arr,n,k);
// } 
