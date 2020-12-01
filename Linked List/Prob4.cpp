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
	Node* temp = new Node();
	temp->data = data;
	temp->next = NULL;
	if(!head)
	{
		head = temp;
		return;
	}
	Node* temp1 = head;
	while(temp1->next)
		temp1 = temp1->next;
	temp1->next = temp;
}

void traverse()
{
	Node* temp = head;
	while(temp)
	{
		cout << temp->data << ' ';
		temp = temp->next;
	}
}

Node* removeDup(Node* temp)
{
	if(temp == NULL)
		return NULL;
	if(temp->next == NULL)
		return temp;
	Node* t1 = temp;
	Node* t2 = temp->next;
	while(t2)
	{
		if(t1->data == t2->data)
		{
			t1->next = t2->next;
			t2 = t2->next;
		}
		else
		{
			t1 = t2;
			t2 = t2->next;
		}
	}
	return temp;
}

void solve() 
{ 
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		int a;
		cin >> a;
		insert(a);
	}
	head = removeDup(head);
	traverse();
} 