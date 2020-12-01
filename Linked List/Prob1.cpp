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

void RecursiveReverse(Node *f = NULL,Node *s = head)
{
	if(s)
	{
		Node *next = s->next;
		s->next = f;
		RecursiveReverse(s,next);
	}
	else
		head = f;
}

void IterativeReverse()
{
	Node* prev = NULL;
	Node* next;
	Node* curr = head;
	while(curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	head = prev;
}

void solve() 
{ 
	insert(3);
	insert(5);
	insert(2);
	insert(9);
	traverse();
	IterativeReverse();
	traverse();
	IterativeReverse();
	traverse();
	RecursiveReverse();
	traverse();
	RecursiveReverse();
	traverse();
} 