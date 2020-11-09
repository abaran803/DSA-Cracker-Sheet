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

void algo(string str,string s)
{
	if(str.length() == 0)
	{
		cout << s << ' ';
		return;
	}
	algo(str.substr(1),s);
	algo(str.substr(1),s+str[0]);
}

unordered_set<string> st;

void algo2(string str)
{
	for(int i=0;i<str.length();i++)
	{
		for(int j=str.length();j>i;j--)
		{
			string sb = str.substr(i,j);
			st.insert(sb);
			for(int k=1;k<sb.length()-1;k++)
			{
				string sub = sb;
				sub.erase(sub.begin()+k);
				algo2(sub);
			}
		}
	}
}

void solve() 
{ 
	string str;
	cin >> str;
	// algo(str,"");
	algo2(str);
	for(auto i:st)
		cout << i << ' ';
} 