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

bool Palindrome(string str)
{
	for(int i=0,j=str.length()-1;i<j;i++,j--)
		if(str[i] != str[j])
			return false;
	return true;
}

int algo(string str)
{
	int count = 0;
	string res;
	while(!Palindrome(str))
	{
		count++;
		res += str[str.length()-1];
		str.pop_back();
	}
	return count;
}

void solve() 
{ 
	string str;
	cin >> str;
	cout << algo(str);
} 