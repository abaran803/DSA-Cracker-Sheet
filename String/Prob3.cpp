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

void algo(string str)
{
	int arr[26] = {0};
	for(int i=0;i<str.length();i++)
		arr[str[i]-'a']++;
	for(int i=0;i<26;i++)
		if(arr[i] > 1)
			cout << char(i+'a') << ' ' << arr[i] << endl;
}

void solve() 
{ 
	string str;
	getline(cin,str);
	algo(str);
} 