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

bool algo(int n,string str,string query)
{
	int j = 0;
    for(int i=0;i<str.length();i++)
    {
    	int k = i;
        while(query[j] == str[k])
        {
            j++;
            k++;
        }
        if(j == query.length())
        {
        	return 1;
        }
        else
            j = 0;
    }
    if(j == query.length())
    	return 1;
    return 0;
}

void solve() 
{ 
	int n;
	cin >> n;
	string str,query;
	while(n--)
	{
		string temp;
		cin >> temp;
		str += temp;
	}
	cin >> query;
	cout << algo(n,str,query);
}