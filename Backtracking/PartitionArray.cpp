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

// bool isTrue(int arr[],int n,int k) {
//     int cnt = 0;
//     int sum = 0;
//     for(int i=0;i<n;i++) {
//         sum += arr[i];
//         if((float)sum == n/(float)k){
//             cnt++;
//             sum = 0;
//         }
//     }
//     if(cnt == k) {
//         return true;
//     }
//     return false;
// }

// void isKPartitionPossibleUtils(int arr[],int x,int n,int k,bool &isCorr) {
//     if(isTrue(arr,n,k)) {
//         isCorr = true;
//         return;
//     }
//     if(x >= n) {
//         return;
//     }
//     if(!isCorr) {
//         for(int i=x;i<n;i++) {
//             swap(arr[x],arr[i]);
//             isKPartitionPossibleUtils(arr,i+1,n,k,isCorr);
//             swap(arr[x],arr[i]);
//         }
//     }
// }

// bool isKPartitionPossible(int arr[],int n,int k) {
//     bool isCorr = false;
//     isKPartitionPossibleUtils(arr,0,n,k,isCorr);
//     return isCorr;
// }

// void solve() 
// { 
//     int n;
//     cin >> n;
//     int arr[n];
//     int sum = 0;
//     int count = 0;
//     for(int i=0;i<n;i++)
//     {
//         cin >> arr[i];
//         sum += arr[i];
//         count++;
//     }
//     int k;
//     cin >> k;
//     cout << isKPartitionPossible(arr,n,k);
// } 