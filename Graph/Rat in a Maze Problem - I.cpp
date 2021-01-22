#include<iostream>
#include<vector>
#define MAX 5
using namespace std;

bool isSafe(int row,int col,int n) {
    if(row < 0 || row >= n || col < 0 || col >= n) {
        return false;
    } return true;
}

void findPathUtils(int arr[MAX][MAX],int row,int col,int n,string curr,vector<string> &vec) {
    if(!isSafe(row,col,n) || !arr[row][col]) {
        return;
    }
    if(row == n-1 && col == n-1) {
        vec.push_back(curr);
        return;
    }
    arr[row][col] = 0;
    findPathUtils(arr,row+1,col,n,curr+'D',vec);
    findPathUtils(arr,row,col+1,n,curr+'R',vec);
    findPathUtils(arr,row-1,col,n,curr+'U',vec);
    findPathUtils(arr,row,col-1,n,curr+'L',vec);
    arr[row][col] = 1;
}

vector<string> findPath(int m[MAX][MAX], int n) {
    vector<string> vec;
    findPathUtils(m,0,0,n,"",vec);
    return vec;
}

int main() {

    freopen("inp.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int n;
    cin >> n;

    int arr[MAX][MAX];

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> arr[i][j];
        }
    }

    vector<string> vec = findPath(arr, n);
    for(int i=0;i<vec.size();i++) {
        cout << vec[i] << ' ';
    }

    return 0;

}