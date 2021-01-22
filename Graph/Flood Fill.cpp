#include<iostream>
#include<vector>
using namespace std; 

int rowM[8] = {-1,0,0,1};
int colM[8] = {0,-1,1,0};

bool isSafe(int row,int col,int n,int m) {
    return (row>=0 && row<n && col>=0 && col<m);
}

void floodFillUtils(vector<vector<int>> &image,int row,int col,int newColor) {
    if(!isSafe(row,col,image.size(),image[0].size())) {
        return;
    }
    int par = image[row][col];
    image[row][col] = -1;
    for(int i=0;i<4;i++) {
        if(isSafe(row+rowM[i],col+colM[i],image.size(),image[0].size()) && image[row+rowM[i]][col+colM[i]] == par) {
            floodFillUtils(image,row+rowM[i],col+colM[i],newColor);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    floodFillUtils(image,sr,sc,newColor);
    for(int i=0;i<image.size();i++) {
        for(int j=0;j<image[0].size();j++) {
            if(image[i][j] == -1) {
                image[i][j] = newColor;
            }
        }
    }
    return image;
}

int main() {

    freopen("inp.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int n,m;
    cin >> n >> m;
    vector<int> temp(m,-1);
    vector<vector<int>> vec(n,temp);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> vec[i][j];
        }
    }

    int sr,sc,newColor;
    cin >> sr >> sc >> newColor;
    vec = floodFill(vec,sr,sc,newColor);

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cout << vec[i][j] << ' ';
        } cout << endl;
    }

    return 0;

}