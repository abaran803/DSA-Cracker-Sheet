#include<bits/stdc++.h> 
#define int long long
#define N 9

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
    cout<<endl; 
    } 
    cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
    return 0; 
} 

bool isSafeRow(int grid[N][N],int row,int num) {
    for(int col=0;col<N;col++) {
        if(grid[row][col] == num) {
            return false;
        }
    }
    return true;
}

bool isSafeCol(int grid[N][N],int col,int num) {
    for(int row=0;row<N;row++) {
        if(grid[row][col] == num) {
            return false;
        }
    }
    return true;
}

bool isSafeBlock(int grid[N][N],int row,int col,int num) {
    row = (row/3)*3;
    col = (col/3)*3;
    for(int i=row;i<row+3;i++) {
        for(int j=col;j<col+3;j++) {
            if(grid[i][j] == num) {
                return false;
            }
        }
    }
    return true;
}

bool isSafe(int grid[N][N],int row,int col,int num) {
    if(!grid[row][col] && isSafeRow(grid,row,num) && isSafeCol(grid,col,num) && isSafeBlock(grid,row,col,num)) {
        return true;
    }
    return false;
}

bool isEmptyCell(int grid[N][N],int &row,int &col) {
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(grid[i][j] == 0) {
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}

bool SolveSudoku(int grid[N][N]) {
    int row,col;
    if(!isEmptyCell(grid,row,col)) {
        return true;
    }
    for(int num=1;num<=N;num++) {
        if(isSafe(grid,row,col,num)) {
            grid[row][col] = num;
            if(SolveSudoku(grid)) {
                return true;
            }
            grid[row][col] = 0;
        }
    }
    return false;
}

void printGrid(int grid[N][N]) {
    if(!SolveSudoku(grid)) {
        cout << -1;
        return;
    }
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cout << grid[i][j] << ' ';
        }
        cout << endl;
    }
}

void solve() 
{ 
    int grid[N][N];
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> grid[i][j];
        }
    }
    printGrid(grid);
} 