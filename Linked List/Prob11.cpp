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

void merge(Node **h1,int l,int mid,int h)
{
	int i=l,j=mid;
	Node* iVal = (*h1);
	Node* jVal = (*h1);
	Node* p1 = NULL;
	Node* p2 = NULL;
	for(int k=0;k<i;k++)
	{
		p1 = iVal;
		iVal = iVal->next;
	}
	for(int k=0;k<j;k++)
	{
		p2 = jVal;
		jVal = jVal->next;
	}
	while(i<mid && j<=h)
	{
		if(iVal->data <= jVal->data)
		{
			iVal = iVal->next;
			i++;
		}
		else
		{
			p2->next = jVal->next;
			Node* temp = jVal;
			jVal = jVal->next;
			temp->next = iVal->next;
			iVal = temp;
			iVal = iVal->next;
			i++;
			j++;
			mid++;
		}
	}
}

void mergeSort(Node **h1,int l,int h)
{
	int mid = (l+h)/2;
	// mergeSort(h1,l,mid);
	// mergeSort(h1,mid+1,h);
	// merge(h1,l,mid+1,h);
}

Node* algo(Node* h1)
{
	int n = size(h1);
	mergeSort(&h1,0,n-1);
	return h1;
}

void solve() 
{ 
	int n;
	cin >> n;
	Node* h1 = NULL;
	for(int i=0;i<n;i++)
	{
		int a;
		cin >> a;
		insert(&h1,a);
	}
	h1 = algo(h1);
} 