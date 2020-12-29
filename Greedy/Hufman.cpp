#include<bits/stdc++.h> 
#define int long long

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

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data)
{
    Node* temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

Node* insert(int arr[],int l,int r,vector<Node*> vec)
{
    Node* temp;
    if(l > r)
        return NULL;
    if(l == r)
    {
        Node* temp = NULL;

    }
    Node* min1;
    Node* min2;
    min1 = min2 = NULL;
    for(auto it: vec)
    {
        if(!min1)
            min1 = it;
        if(it->data < min1->data)
        {
            min2 = min1;
            min1 = it;
        }
    }
    int loopPos = l-1;
    for(int i=l;i<=r;i++)
    {
        if(!min1)
            min1 = newNode(arr[i]);
        if(arr[i] < min1->data)
        {
            min2 = min1;
            min1 = newNode(arr[i]);
            loopPos = i;
        }
    }
    temp = newNode(min1->data + min2->data);
    temp->left = min1;
    temp->right = min2;
    return temp;
}

void solve() 
{ 
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];
    vector<Node*> vec;
    Node* root = insert(arr,0,n-1,vec);
} 