#include<bits/stdc++.h> 
#define ll long long
#define endl "\n"

using namespace std; 
void solve(); 
int main() 
{ 
ios_base::sync_with_stdio(false);cin.tie(NULL); 

#ifndef ONLINE_JUDGE 
freopen("inp.txt", "r", stdin); 
freopen("err.txt", "w", stderr); 
freopen("out.txt", "w", stdout); 
#endif 

ll t=1; 
//cin>>t; 
while(t--) 
{ 
	solve(); 
	cout<<"\n"; 
} 
cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
return 0; 
} 

struct Pair
{
	ll mini;
	ll maxi;
};

// class MaxHeap
// {
// 	ll *arr;
// 	ll size;

// public:

// 	ll parent(ll i){ return ((i-1)/2); }
// 	ll lChild(ll i){ return ((2*i)+1); }
// 	ll rChild(ll i){ return ((2*i)+2); }

// 	MaxHeap(ll *arr,ll n)
// 	{
// 		size = n;
// 		this->arr = arr;
// 		ll i = parent(n-1);
// 		while(i >= 0)
// 		{
// 			Heapify(i);
// 			i--;
// 		}
// 	}

// 	void Heapify(ll i)
// 	{
// 		ll val = arr[i];
// 		ll lef = lChild(i);
// 		ll rig = rChild(i);
// 		ll greatest = i;
// 		if(lef < size && arr[lef] > arr[i])
// 			greatest = lef;
// 		if(rig < size && arr[rig] > arr[greatest])
// 			greatest = rig;
// 		if(greatest != i)
// 		{
// 			swap(arr[i],arr[greatest]);
// 			Heapify(greatest);
// 		}
// 	}

// 	ll pop()
// 	{
// 		size--;
// 		swap(arr[0],arr[size]);
// 		Heapify(0);
// 		return arr[size];
// 	}

// 	ll top()
// 	{
// 		return arr[0];
// 	}

// 	void traverse()
// 	{
// 		for(ll i=0;i<size;i++)
// 			cout << arr[i] << " ";
// 		cout << endl;
// 	}
// };

// class MinHeap
// {
// 	ll *arr;
// 	ll size;

// 	ll parent(ll i){ return ((i-1)/2); }
// 	ll lChild(ll i){ return ((2*i)+1); }
// 	ll rChild(ll i){ return ((2*i)+2); }

// public:
// 	MinHeap(ll *arr,ll n)
// 	{
// 		this->arr = arr;
// 		size = n;
// 		ll i = parent(n-1);
// 		while(i >= 0)
// 		{
// 			Heapify(i);
// 			i--;
// 		}
// 	}

// 	void Heapify(ll i)
// 	{
// 		ll val = arr[i];
// 		ll lef = lChild(i);
// 		ll rig = rChild(i);
// 		ll smallest = i;
// 		if(lef < size && arr[lef] < arr[i])
// 			smallest = lef;
// 		if(rig < size && arr[rig] < arr[smallest])
// 			smallest = rig;
// 		if(smallest != i)
// 		{
// 			swap(arr[i],arr[smallest]);
// 			Heapify(smallest);
// 		}
// 	}

// 	ll pop()
// 	{
// 		size--;
// 		swap(arr[0],arr[size]);
// 		Heapify(0);
// 		return arr[size];
// 	}

// 	ll top()
// 	{
// 		return size != 0 ? arr[0]:-1;
// 	}

// };

// Method 1
// Pair Check(ll arr[],ll k,ll n)
// {
// 	priority_queue<ll> pq;
// 	Pair pl = Pair();
// 	for(ll i=0;i<n;i++)
// 		pq.push(arr[i]);
// 	ll i=0;
// 	for(i=0;i<n;i++)
// 	{
// 		if(i == k-1)
// 			pl.maxi = pq.top();
// 		if(i == n-k)
// 			pl.mini = pq.top();
// 		pq.pop();
// 	}
// 	return pl;
// }

// ll partition(ll arr[],ll s,ll e)
// {
// 	ll p1 = s;
// 	ll p2 = s;
// 	ll piv = e;
// 	for(p2=s;p2<e;p2++)
// 	{
// 		if(arr[p2] < arr[piv])
// 		{
// 			swap(arr[p1],arr[p2]);
// 			p1++;
// 		}
// 	}
// 	swap(arr[p1],arr[piv]);
// 	return p1;
// }

// ll ByQuickSort(ll arr[],ll s,ll e,ll k)
// {
// 	ll pos = partition(arr,s,e);
// 	if(pos == k-1)
// 		return pos;
// 	if(pos > k-1)
// 		return ByQuickSort(arr,s,pos-1,k);
// 	return ByQuickSort(arr,pos+1,e,k);
// }

void solve() 
{ 
	ll n;
	cin >> n;
	ll *arr = new ll[n];
	for(ll i=0;i<n;i++)
		cin >> arr[i];
	ll k;
	cin >> k;
	// Pair p = Check(arr,k,n);
	// MinHeap mh1(arr,n);
	// for(ll i=0;i<k-1;i++)
	// 	cout << "Element " << mh1.pop() << " removed\n";
	// cout << "Minimum: " << mh1.top() << endl << endl;
	// MaxHeap mh(arr,n);
	// for(ll i=0;i<k-1;i++)
	// 	cout << "Element " << mh.pop() << " removed\n";
	// cout << "Maximum: " << mh.top() << endl;
	cout << k << "th Minimum: " << arr[ByQuickSort(arr,0,n-1,k)] << endl;
	for(ll i=0;i<n;i++)
		cout << arr[i] << " ";
}