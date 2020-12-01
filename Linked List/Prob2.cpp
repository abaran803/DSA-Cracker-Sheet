#include<bits/stdc++.h> 
#define int long long
#define endl '\n'

using namespace std; 
void solve(); 

struct Node
{
	int data;
	Node* next;
};

Node* head = NULL;

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
		cout<<"\n"; 
	} 
	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
	return 0; 
} 

void insert(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->next = NULL;
	Node* temp1 = head;
	if(head == NULL)
		head = temp;
	else
	{
		Node* temp1 = head;
		while(temp1->next != NULL)
			temp1 = temp1->next;
		temp1->next = temp;
	}
}

void traverse()
{
	Node* temp = head;
	while(temp != NULL)
	{
		cout << temp->data << ' ';
		temp = temp->next;
	}
	cout << endl;
}

int size()
{
	Node* temp = head;
	int cnt = 0;
	while(temp)
	{
		cnt++;
		temp = temp->next;
	}
	return cnt;
}

Node* ReverseByPart(Node* h,int k)
{
	if(h == NULL)
		return NULL;
	int m = k;
	Node* next;
	Node* prev = NULL;
	Node* curr = h;
	while(m-- && curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	if(m == -1)
		h->next = ReverseByPart(next,k);
	else
		h->next = NULL;
	return prev;
}

void solve() 
{ 
	int n,k;
	cin >> n >> k;
	for(int i=0;i<n;i++)
	{
		int a;
		cin >> a;
		insert(a);
	}
	traverse();
	head = ReverseByPart(head,k);
	traverse();
} 