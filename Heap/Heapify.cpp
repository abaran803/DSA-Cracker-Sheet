#include<bits/stdc++.h>
#define int long long
#define vi vector<int>
#define vs vector<string>
#define F first
#define S second
#define mii map<int,int>
#define mci map<char,int>

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
    //cin>>t; 
    while(t--) 
    { 
        solve(); 
        cout<<endl; 
    } 
    cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
    return 0; 
} 

int Lchild(int i,int pos) {
    int LC = 2*i+1;
    if(LC > pos) {
        return -1;
    }
    return LC;
}

int Rchild(int i,int pos) {
    int RC = 2*i+2;
    if(RC > pos) {
        return -1;
    }
    return RC;
}

void CorrectTopToBottom(int arr[],int pos,int curr) {
    if(Lchild(curr,pos) == -1) {
        return;
    }
    int maxInd = curr;
    if(arr[maxInd]<arr[Lchild(curr,pos)]) {
        maxInd = Lchild(curr,pos);
    }
    if(Rchild(curr,pos) != -1 && arr[maxInd]<arr[Rchild(curr,pos)]) {
        maxInd = Rchild(curr,pos);
    }
    if(curr != maxInd) {
        swap(arr[curr],arr[maxInd]);
        CorrectTopToBottom(arr,pos,maxInd);
    }
}

void Heapify(int arr[],int pos) {
    for(int i=pos;i>=0;i--) {
        if(Lchild(i,pos) != -1) {
            CorrectTopToBottom(arr,pos,i);
        }
    }
}

void solve() 
{ 
    int m,n;
    cin >> m >> n;
    int arr1[m+n];
    for(int i=0;i<m+n;i++) {
        cin >> arr1[i];
    }
    Heapify(arr1,m+n-1);
    for(int i=0;i<m+n;i++) {
        cout << arr1[i] << ' ';
    }
} 