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

void insert(Node **head,int data)
{
	Node* temp = new Node();
	temp->data = data;
	temp->next = NULL;
	if(!(*head))
	{
		*head = temp;
		return;
	}
	Node* temp1 = (*head);
	while(temp1->next)
		temp1 = temp1->next;
	temp1->next = temp;
}

void traverse(Node* head)
{
	Node* temp = head;
	while(temp)
	{
		cout << temp->data << ' ';
		temp = temp->next;
	}
	cout << endl;
}

int size(Node* head)
{
	int count = 0;
	while(head)
	{
		count++;
		head = head->next;
	}
	return count;
}

vector<int> vec;

int CommonPoint(Node* hd1,Node* hd2)
{
	map<int,int> mp;
	while(hd1)
	{
		mp[hd1->data] = 1;
		hd1 = hd1->next;
	}
	while(hd2)
	{
		if(mp[hd2->data] == 1)
			return hd2->data;
		hd2 = hd2->next;
	}
	return -1;
}

void solve() 
{ 
	int n;
	cin >> n;
	Node* h1 = NULL;
	Node* h2 = NULL;
	for(int i=0;i<n;i++)
	{
		int a;
		cin >> a;
		insert(&h1,a);
	}
	int m;
	cin >> m;
	for(int i=0;i<m;i++)
	{
		int a;
		cin >> a;
		insert(&h2,a);
	}
	cout << CommonPoint(h1,h2);
} 