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

Node* AddTwo(Node* hd1,Node* hd2,int diff,int ty)
{
	if(!hd1)
		return hd2;
	if(!hd2)
		return hd1;
	Node* temp = new Node();
	if(!(hd1->next) && !(hd2->next))
	{
		temp->data = hd1->data + hd2->data;
		temp->next = NULL;
		return temp;
	}
	if(diff > 0)
	{
		if(ty == 1)
		{
			temp->next = AddTwo(hd1->next,hd2,diff-1,ty);
			temp->data = hd1->data;
			if(temp->next->data > 9)
			{
				temp->data += ((temp->next->data)/10);
				temp->next->data %= 10;
			}
		}
		else
		{
			temp->next = AddTwo(hd1,hd2->next,diff-1,ty);
			temp->data = hd2->data;
			if(temp->next->data > 9)
			{
				temp->data += ((temp->next->data)/10);
				temp->next->data %= 10;
			}
		}
	}
	else
	{
		temp->next = AddTwo(hd1->next,hd2->next,diff-1,ty);
		temp->data = hd1->data + hd2->data;
		if(temp->next->data > 9)
		{
			temp->data += ((temp->next->data)/10);
			temp->next->data %= 10;
		}
	}
	return temp;
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
	traverse(h1);
	traverse(h2);
	int s1 = size(h1);
	int s2 = size(h2);
	Node* h3 = NULL;
	// cout << s1 << ' ' << s2 << endl;
	if(s1>s2)
		h3 = AddTwo(h1,h2,s1-s2,1);
	else
		h3 = AddTwo(h1,h2,s2-s1,2);
	traverse(h3);
} 