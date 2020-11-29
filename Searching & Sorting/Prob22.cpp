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

int algo(int a,int b,int c)
{
    if(c == 0)
    {
        if(a == b)
            return 1;
        return 0;
    }
	if((b-a)%c != 0)
		return 0;
	if((b-a)/c < 0)
	    return 0;
	return 1;
}

void solve() 
{ 
	int a,b,c;
	cin >> a >> b >> c;
	cout << algo(a,b,c);
} 