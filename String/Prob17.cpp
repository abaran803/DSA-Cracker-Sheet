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

int CountReverse(string str) 
{

	// If total number of brackets odd
	if(str.length() & 1)
	    return -1;

	// Num: Number of unbalanced openning bracket '{' till now
	// Count: Number of Reversals
	int num = 0,count=0;

	// Traversing the string
	for(int i=0;i<str.length();i++)
	{
		// If closing bracket occur
		if(str[i] == '}')
		{
			// Before openning
			if(num == 0)
			{
				// Increase number of reversal and unbalanced '{'
				count++;
				num++;
			}

			// After openning
			else
				num--;
		}
		// If openning bracket '{' occur
		else
			num++;
	}
	// If num != 0 means some openning bracket are unbalanced after traversal of string
	if(num)
		count = count+(num/2);
	return count;
}

void solve() 
{ 
	string str;
	cin >> str;
	cout << CountReverse(str);
} 