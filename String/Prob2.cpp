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

bool isPal(string S,int l,int r)
{
    if(l<r)
    {
        if(S[l] != S[r])
            return false;
        return isPal(S,l+1,r-1);
    }
    return true;
}

int algo(string S)
{
   int l=0,r=S.length()-1;
   return isPal(S,l,r);
}

int algo2(string S)
{
	for(int i=0,j=S.length()-1;i<j;i++,j--)
        if(S[i] != S[j])
            return false;
   return true;
}

void solve() 
{ 
	string str;
	cin >> str;
	cout << algo2(str);
} 