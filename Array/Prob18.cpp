#include<bits/stdc++.h> 
#define int long long
#define endl '\n'

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
		cout<<"\n"; 
	} 
	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
	return 0; 
} 


void rotateByOne(int arr[],int l,int r)
{
	if(l == r)
		return;
	int temp = arr[r];
	for(int i=r;i>l;i--)
		arr[i] = arr[i-1];
	arr[l] = temp;
}

void algo(int arr[],int n)
{
	// Hold the index of incorrect element
	// -1 means correct till given index
	int notCorrect = -1;
	for(int i=0;i<n;i++)
	{
		// Work if any index before it have any incorrect element
		if(notCorrect >= 0)
		{
			// Work when an element at i is opposite in sign of incorrect element
			if((arr[i]>=0 && arr[notCorrect]<0) || (arr[i]<0 && arr[notCorrect]>=0))
			{
				// rotate from incorrect to i
				rotateByOne(arr,notCorrect,i);
				// if element i is greater than or equal to 2 means that element after incorrect element index + 2 is also incorrect
				// As -1 -2 -3 -4 6 for index 1 we will pick 6 and rotate -1 6 -2 -3 -4 and found element 1+2=3 is also incorrect
				if(i - notCorrect >= 2)
					notCorrect += 2;
				else
					notCorrect = -1;
			}
		}
		// Work if no previous element is incorrect in sequence
		if(notCorrect == -1)
		{
			if((arr[i]>=0 && !(i&1)) || (arr[i]<0 && (i&1)))
				notCorrect = i;
		}
	}
}

void solve() 
{ 
	int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin >> arr[i];
	// Apply algorithm
	algo(arr,n);
	for(int i=0;i<n;i++)
		cout << arr[i] << ' ';
} 