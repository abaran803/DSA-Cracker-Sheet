// Totally Correct - Big Achievement

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
	cin>>t; 
	while(t--) 
	{ 
		solve(); 
		cout<<"\n"; 
	} 
	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
	return 0; 
} 

string Addition(string str1,string str2)
{
	int m = str1.size();
	int n = str2.size();
	string str3;
	int k = 0;
	char rem = '0';
	int i,j;
	for(i=m-1,j=n-1;i>=0 && j>=0;i--,j--)
	{
		int p = (str1[i]-'0')+(str2[j]-'0')+(rem-'0');
		str3.push_back(char((p%10)+'0'));
		rem = char((p/10)+'0');
	}
	while(i>=0)
	{
		int p = (str1[i--]-'0')+(rem-'0');
		str3.push_back(char((p%10)+'0'));
		rem = char((p/10)+'0');
	}
	while(j>=0)
	{
		int p = (str2[j--]-'0')+(rem-'0');
		str3.push_back(char((p%10)+'0'));
		rem = char((p/10)+'0');
	}
	if(rem != '0')
		str3.push_back(rem);
	reverse(str3.begin(),str3.end());
	return str3;
}

string fa[1005];

string Multiply(string str1,string str2)
{
	int n = str1.length();
	int m = str2.length();
	char rem = '0';
	string tot = "0";
	for(int i=n-1;i>=0;i--)
	{
		string temp;
		rem = '0';
		for(int j=n-1;j>i;j--)
			temp.push_back('0');
		for(int j=m-1;j>=0;j--)
		{
			int t = (str1[i]-'0')*(str2[j]-'0')+(rem-'0');
			temp.push_back(char((t%10)+'0'));
			rem = char((t/10)+'0');
		}
		if(rem != '0')
			temp.push_back(rem);
		reverse(temp.begin(),temp.end());
		tot = Addition(tot,temp);
	}
	return tot;
}

string fact(int n)
{
	if(!fa[n].empty())
		return fa[n];
	if(n == 0 || n == 1)
		return "1";
	string sum = "1";
	fa[n] = Multiply(to_string(n),fact(n-1));
	return fa[n];
}

void solve() 
{ 
	int n;
	cin >> n;
	cout << fact(n);
} 