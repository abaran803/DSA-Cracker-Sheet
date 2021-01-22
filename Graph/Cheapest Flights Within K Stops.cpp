#include<bits/stdc++.h>
using namespace std;

map<int,vector<int>> adj;
map<pair<int,int>,int> wt;
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K)     {
    for(int i=0;i<flights.size();i++) {
        int a = flights[i][0];
        int b = flights[i][1];
        int c = flights[i][2];
        adj[a].push_back(b);
        adj[b].push_back(a);
        wt[{a,b}] = c;
        wt[{b,a}] = c;
    }
}

int main() {
    int n,e;
    cin >> n >> e;
    vector<vector<int>> vec;
    for(int i=0;i<e;i++) {
        int a,b,c;
        vector<int> vec1;
        vec1.push_back(a);
        vec1.push_back(b);
        vec1.push_back(c);
        vec.push_back(vec1);
    }
    int src,dest,k;
    cin >> src >> dest >> k;
    cout << findCheapestPrice(n,vec,src,dest,k);
}