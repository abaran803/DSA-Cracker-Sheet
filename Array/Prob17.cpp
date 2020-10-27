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

void solve() 
{ 
	int n1;
	cin >> n1;
	int A[n1];
	for(int i=0;i<n1;i++)
		cin >> A[i];
	int n2;
	cin >> n2;
	int B[n2];
	for(int i=0;i<n2;i++)
		cin >> B[i];
	int n3;
	cin >> n3;
	int C[n3];
	for(int i=0;i<n3;i++)
		cin >> C[i];
	int p1=0,p2=0,p3=0;
	vector<int> vec;
	while(p1 < n1 && p2 < n2 && p3 < n3)
	{
		if(A[p1]<B[p2] && A[p1]<C[p3])
			p1++;
		else if(B[p2]<C[p3])
			p2++;
		else if(C[p3]<B[p2])
			p3++;
		else
		{
			vec.push_back(A[p1]);
			p1++;
			p2++;
			p3++;
		}
	}
	for(int i=0;i<vec.size();i++)
		cout << vec[i] << " ";
} 