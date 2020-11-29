// Error

// // #include<bits/stdc++.h> 
// // #define int long long
// // #define endl '\n'

// // using namespace std; 
// // void solve(); 

// // int32_t main() 
// // { 
// // 	ios_base::sync_with_stdio(false);cin.tie(NULL); 

// // 	#ifndef ONLINE_JUDGE 
// // 		freopen("inp.txt", "r", stdin); 
// // 		freopen("err.txt", "w", stderr); 
// // 		freopen("out.txt", "w", stdout); 
// // 	#endif 

// // 	int t=1; 
// // 	// cin>>t; 
// // 	while(t--) 
// // 	{ 
// // 		solve(); 
// // 		cout<<"\n"; 
// // 	} 
// // 	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
// // 	return 0; 
// // } 

// // int best = -1;

// // void algo(int *arr,int l,int r,int n,int m)
// // {
// // 	if(l > r)
// // 		return;
// // 	int mid = (l+r)/2;
// // 	int val = 0;
// // 	int maxi = INT_MIN;
// // 	for(int i=0;i<n && val <= m;)
// // 	{
// // 		int sum = 0;
// // 		val++;
// // 		if(arr[i] > mid)
// // 		{
// // 			sum = arr[i++];
// // 			maxi = max(sum,maxi);
// // 			continue;
// // 		}
// // 		while(sum + arr[i] <= mid && i<n)
// // 		{
// // 			sum += arr[i];
// // 			i++;
// // 		}
// // 		maxi = max(sum,maxi);
// // 	}
// // 	// cout << mid << ' ' << maxi << ' ' << val << ' ' << m << " ~~\n";
// // 	if(val <= m)
// // 	{
// // 		best = mid;
// // 		algo(arr,l,mid-1,n,m);
// // 	}
// // 	else if(val > m)
// // 		algo(arr,mid+1,r,n,m);
// // }

// // void solve() 
// // { 
// // 	int n,m;
// // 	cin >> n >> m;
// // 	int *arr = new int[n];
// // 	for(int i=0;i<n;i++)
// // 		cin >> arr[i];
// // 	int maxi = 0;
// // 	for(int i=0;i<n;i++)
// // 		maxi += arr[i];
// // 	sort(arr,arr+n);
// // 	algo(arr,0,maxi,n,m);
// // 	cout << best;
// // } 

// #include<iostream>
// #include<algorithm>
// using namespace std;

// #define ll long long int

// bool isValidConfig(ll books[],ll n,ll k,ll ans){
        
//     int students=1;
//     ll current_pages = 0;
    
//     for(int i=0;i<n;i++){
        
//         if(current_pages+books[i]>ans){
//             current_pages = books[i];
//             students++;
//             if(students>k){
//                 return false;
//             }
            
//         }
//         else{
//             current_pages += books[i];
            
//         }
//     }
//     return true;
// }

// ll binarySearchBooks(ll books[],ll n,ll k){
    
//     ll total_pages = 0;
//     ll s=0,e=0;
//     for(int i=0;i<n;i++){
//         total_pages += books[i];
//     }
//     s = books[n-1];
    
//     e = total_pages;
//     int finalAns = s;
    
//     while(s<=e){
//         ll mid = (s+e)/2;
        
//         if(isValidConfig(books,n,k,mid)){
//             ///true
//             finalAns = mid;
//             e = mid-1;
            
//         }
//         else{
//             //FALSE
//             s = mid + 1;
//         }
        
//         cout << s << ' ' << e << ' ' << mid << " ~~\n";
//     }
    
//     return finalAns;
    
// }

// int main(){
    
// 	#ifndef ONLINE_JUDGE 
// 		freopen("inp.txt", "r", stdin); 
// 		freopen("err.txt", "w", stderr); 
// 		freopen("out.txt", "w", stdout); 
// 	#endif 
//     ll n;
//     ll k;
    
//     cin>>n>>k;
    
//     ll books[100005];
    
//     for(int i=0;i<n;i++){
//         cin>>books[i];
//     }
//     sort(books,books+n);
//     cout<<binarySearchBooks(books,n,k)<<endl; 
//     // cout << "Heu";
// }