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

string algo(int n)
{
	if(n == 1)
		return "1";
	string arr = algo(n-1);
	string str1;
	int count=1;
	string temp;
	for(int i=1;i<arr.length();i++)
	{
		if(arr[i] == arr[i-1])
			count++;
		else
		{
			str1 += char(count+'0');
			str1 += arr[i-1];
			count = 1;
		}
	}
	str1 += char(count+'0');
	str1 += arr[arr.length()-1];
	return str1;
}

void solve() 
{ 
	int n;
	cin >> n;
	cout << algo(n);
} 