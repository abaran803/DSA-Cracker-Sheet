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
	for(int i=0;i<str.length();i++)
	{
		if(str[i] >= 'A' && str[i] <= 'C')
		{
			int k = str[i]-'A'+1;
			while(k--)
				cout << 2;
		}
		else if(str[i] <= 'F')
		{
			int k = str[i]-'D'+1;
			while(k--)
				cout << 3;
		}
		else if(str[i] <= 'I')
		{
			int k = str[i]-'G'+1;
			while(k--)
				cout << 4;
		}
		else if(str[i] <= 'L')
		{
			int k = str[i]-'J'+1;
			while(k--)
				cout << 5;
		}
		else if(str[i] <= 'O')
		{
			int k = str[i]-'M'+1;
			while(k--)
				cout << 6;
		}
		else if(str[i] <= 'S')
		{
			int k = str[i]-'P'+1;
			while(k--)
				cout << 7;
		}
		else if(str[i] <= 'V')
		{
			int k = str[i]-'T'+1;
			while(k--)
				cout << 8;
		}
		else if(str[i] <= 'Z')
		{
			int k = str[i]-'W'+1;
			while(k--)
				cout << 9;
		}
		else
		{
			cout << "Error";
			return;
		}
	}
}

void algo2(string str)
{
	int str1[] = {2,22,222,
				3,33,333,
				4,44,444,
				5,55,555,
				6,66,666,
				7,77,777,7777,
				8,88,888,
				9,99,999,9999};

	int n = str.length();
	for(int i=0;i<n;i++)
	{
		if(str[i] == ' ')
			cout << 0;
		else
			cout << str1[str[i]-'A'];
	}
}

void solve() 
{ 
	string str;
	getline(cin,str);
	algo2(str);
} 