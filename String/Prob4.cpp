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

bool subs(string str1,string str2)
{
	for(int i=0;i<str1.length();i++)
	{
		int j=0;
		if(str2[j] == str1[i] && j<str2.length())
		{
			for(j=1;j<str2.length() && i+j<str1.length();j++)
				if(str2[j]!=str1[i+j])
					break;
			if(j==str2.length())
				return true;
		}
	}
	return false;
}

bool algo(string str1,string str2)
{
	if(str1.length() != str2.length())
		return false;
	str1 += str1;
	return subs(str1,str2);
}

void solve() 
{ 
	string str1,str2;
	cin >> str1 >> str2;
	cout << algo(str1,str2);
} 