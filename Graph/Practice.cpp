//Error

// #include<iostream>
// #include<vector>
// using namespace std;


// void DFS(int x,int n, vector<vector<int>>& connections,bool vis[]) {
//     vis[x] = true;
//     for(int i=0;i<connections[x].size();i++) {
//         if(!vis[connections[x][i]]) {
//             DFS(connections[x][i],n,connections,vis);
//         }
//     }
// }

// int makeConnected(int n, vector<vector<int>>& connections) {
//     bool vis[n];
//     int sz = 0;
//     for(int i=0;i<connections.size();i++) {
//         for(int j=0;j<connections[i].size();j++) {
//             sz++;
//         }
//     }
//     sz /= 2;
//     for(int i=0;i<n;i++) {
//         vis[i] = false;
//     }
//     if(sz < n-1) {
//         return -1;
//     }
//     int cnt = 0;
//     for(int i=0;i<n;i++) {
//         if(!vis[i]) {
//             DFS(i,n,connections,vis);
//             cnt++;
//         }
//     }
//     return cnt-1;
// }

// void insert(vector<vector<int>> &vec,int a,int b) {
//     vec[a].push_back(b);
//     vec[b].push_back(a);
// }

// int main() {

//     freopen("inp.txt","r",stdin);
//     freopen("out.txt","w",stdout);

//     int n,e;
//     cin >> n >> e;

//     vector<int> vec1;
//     vector<vector<int>> vec(n,vec1);

//     for(int i=0;i<e;i++) {
//         int a,b;
//         cin >> a >> b;
//         insert(vec,a,b);
//     }

//     int k = makeConnected(n,vec);
//     cout << k << endl;

//     return 0;

// }