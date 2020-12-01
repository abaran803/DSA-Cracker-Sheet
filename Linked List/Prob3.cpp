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

Node* newNode(int data)
{
	Node* temp = new Node();
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void traverse(Node* head)
{
	Node* temp = head;
	map<Node*,bool> mp;
	while(mp[temp] != 1 && temp != NULL)
	{
		mp[temp] = 1;
		temp = temp->next;
	}
	if(temp)
		cout << temp->data;
	else
		cout << -1;
}

void solve() 
{ 
	int n;
	cin >> n;
	Node* head = NULL;
	Node* n1 = newNode(1);
	Node* n2 = newNode(2);
	Node* n3 = newNode(3);
	Node* n4 = newNode(4);
	Node* n5 = newNode(5);
	head = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n2;
	traverse(head);
} 