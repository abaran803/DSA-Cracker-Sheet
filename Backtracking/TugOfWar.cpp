// Error

// #include<bits/stdc++.h> 
// #define int long long
// #define vi vector<int>
// #define vs vector<string>
// #define F first
// #define S second
// #define mii map<int,int>
// #define mci map<char,int>

// using namespace std;
// void solve(); 

// int32_t main() 
// { 
//     ios_base::sync_with_stdio(false);cin.tie(NULL); 

//     #ifndef ONLINE_JUDGE 
//         freopen("inp.txt", "r", stdin); 
//         freopen("err.txt", "w", stderr); 
//         freopen("out.txt", "w", stdout); 
//     #endif 

//     int t=1; 
//     //cin>>t; 
//     while(t--) 
//     { 
//         solve(); 
//         cout<<endl; 
//     } 
//     cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
//     return 0; 
// } 

// int minDiff = INT_MAX;

// void TOW(int arr[],int currSum,int i,int nSel,int sum,int n,vi &vec) {
//     if(nSel > ceil(n/2.0) || i>= n) {
//         return;
//     }
//     if(nSel == (n/2) || nSel == ceil(n/2.0)) {
//         if(abs(sum/2 - currSum) < minDiff) {
//             for(int i=0;i<vec.size();i++) {
//                 cout << vec[i] << ' ';
//             }
//             cout << endl;
//             minDiff = abs((sum/2-currSum));
//         }
//         return;
//     }
//     TOW(arr,currSum,i+1,nSel,sum,n,vec);
//     if(i+1 <= ceil(n/2.0)) {
//         vec.push_back(arr[i+1]);
//         TOW(arr,currSum+arr[i+1],i+1,nSel+1,sum,n,vec);
//         vec.pop_back();
//     }
// }

// void solve() 
// { 
//     int n;
//     cin >> n;
//     int arr[n];
//     int sum = 0;
//     for(int i=0;i<n;i++) {
//         cin >> arr[i];
//         sum += arr[i];
//     }
//     vi vec;
//     TOW(arr,0,-1,0,sum,n,vec);
//     cout << minDiff;
// } 