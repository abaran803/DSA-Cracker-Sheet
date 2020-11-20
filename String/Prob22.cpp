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

string compere(string left,string right)
{
	for(int i=0;i<min(left.size(),right.size());i++)
		if(left[i] != right[i])
			return right.substr(0,i);
	return left.substr(0,min(left.size(),right.size()));
}

string LCP(vector<string> vec,int l,int r)
{
	if(l == r)
		return vec[l];
	int mid = (l+r)/2;
	string left = LCP(vec,l,mid);
	string right = LCP(vec,mid+1,r);
	return compere(left,right);
}

string algo2(vector<string> vec)
{
	if(vec.empty())
		return "";
	return LCP(vec,0,vec.size()-1);
}

string algo(vector<string> vec)
{
	if(!vec.empty())
	{
		for(int i=0;i<vec[0].size();i++)
		{
			char t = vec[0][i];
			int j;
			for(j=1;j<vec.size();j++)
				if(i>=vec[j].size() || vec[j][i] != t)
					return vec[0].substr(0,i);
		}
        return vec[0];
	}
	return "";
}

void solve() 
{ 
	vector<string> str;
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		string str1;
		cin >> str1;
		str.push_back(str1);
	}
	cout << algo2(str);
} 