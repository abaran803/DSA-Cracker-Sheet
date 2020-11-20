// Error

// #include<bits/stdc++.h> 
// #define int long long
// #define endl '\n'

// using namespace std; 
// void solve(); 

// int32_t main() 
// { 
// 	ios_base::sync_with_stdio(false);cin.tie(NULL); 

// 	#ifndef ONLINE_JUDGE 
// 		freopen("inp.txt", "r", stdin); 
// 		freopen("err.txt", "w", stderr); 
// 		freopen("out.txt", "w", stdout); 
// 	#endif 

// 	int t=1; 
// 	//cin>>t; 
// 	while(t--) 
// 	{ 
// 		solve(); 
// 		cout<<"\n"; 
// 	} 
// 	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
// 	return 0; 
// } 

// // Recursive Approach
// int RecCount(char **arr,int x,int y,string str,int c,int n)
// {
// 	int count = 0;
// 	if(x >= 0 && x < n && y >= 0 && y < n && arr[x][y] == str[c])
// 	{
// 		char m = str[c];
// 		arr[x][y] = 0;
// 		c++;
// 		if(str[c] == 0)
// 		{
// 			count = 1;
// 			cout << x << ' ' << y << endl << endl;
// 		}
// 		else
// 		{
// 			cout << x << ' ' << y << endl;
// 			// Top Direction
// 			count += RecCount(arr,x-1,y,str,c,n);
// 			// Down Direction
// 			count += RecCount(arr,x+1,y,str,c,n);
// 			// Left Direction
// 			count += RecCount(arr,x,y-1,str,c,n);
// 			// Right Direction
// 			count += RecCount(arr,x,y+1,str,c,n);
// 		}
// 		arr[x][y] = m;
// 	}
// 	return count;
// }

// // Iterative Approach
// int countTimes(char **arr,int x,int y,string str,int n)
// {
// 	if(arr[x][y] == str[0])
// 	{

// 		// Top traversal
// 		int i, j = 0 , count = 0;
// 		for(i=x-1,j=1;i>=0 && j<str.length();i--,j++)
// 			if(arr[i][y] != str[j])
// 				break;
// 		if(j == str.length())
// 			count++;
// 		j = 0;

// 		// Down Traversal
// 		for(i=x+1,j=1;i<n && j<str.length();i++,j++)
// 			if(arr[i][y] != str[j])
// 				break;
// 		if(j == str.length())
// 			count++;
// 		j = 0;

// 		// Left Traversal
// 		for(i=y-1,j=1;i>=0 && j<str.length();i--,j++)
// 			if(arr[x][i] != str[j])
// 				break;
// 		if(j == str.length())
// 			count++;
// 		j = 0;

// 		// Right Traversal
// 		for(i=y+1,j=1;i<n && j<str.length();i++,j++)
// 			if(arr[x][i] != str[j])
// 				break;
// 		if(j == str.length())
// 			count++;

// 		// Right Traversal
// 		for(i=y+1,j=1;i<n && j<str.length();i++,j++)
// 			if(arr[x][i] != str[j])
// 				break;
// 		if(j == str.length())
// 			count++;

// 		// Right Traversal
// 		for(i=y+1,j=1;i<n && j<str.length();i++,j++)
// 			if(arr[x][i] != str[j])
// 				break;
// 		if(j == str.length())
// 			count++;

// 		// Right Traversal
// 		for(i=y+1,j=1;i<n && j<str.length();i++,j++)
// 			if(arr[x][i] != str[j])
// 				break;
// 		if(j == str.length())
// 			count++;

// 		// Right Traversal
// 		for(i=y+1,j=1;i<n && j<str.length();i++,j++)
// 			if(arr[x][i] != str[j])
// 				break;
// 		if(j == str.length())
// 			count++;

// 		return count;
// 	}
// 	return 0;
// }

// int algo(char **arr, string str, int n)
// {
// 	int count = 0;
// 	for(int i=0;i<n;i++)
// 		for(int j=0;j<n;j++)
// 		{
// 			// count += countTimes(arr,i,j,str,n);
// 			count += RecCount(arr,i,j,str,0,n);
// 		}
// 	return count;
// }

// void solve() 
// { 
// 	int n;
// 	cin >> n;
// 	char **arr = new char*[n];
// 	for(int i=0;i<n;i++)
// 		arr[i] = new char[n];
// 	for(int i=0;i<n;i++)
// 		for(int j=0;j<n;j++)
// 			cin >> arr[i][j];
// 	string q;
// 	cin >> q;
// 	cout << algo(arr,q,n);
// } 