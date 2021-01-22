#include<iostream>
#include<limits.h>
using namespace std;

int n;

void Floyd(int **G) {
    int Dist[n][n];
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            Dist[i][j] = G[i][j];
        }
    }

    for(int k=0;k<n;k++) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if((Dist[i][k] != INT_MAX && Dist[k][j] != INT_MAX) && Dist[i][j] > Dist[i][k]+Dist[k][j]) {
                    Dist[i][j] = Dist[i][k]+Dist[k][j];
                }
            }
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(Dist[i][j] == INT_MAX) {
                cout << 'I';
            } else {
                cout << Dist[i][j];
            } cout << ' ';
        }
        cout << endl;
    }
}

int main() {

    freopen("inp.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int e;
    cin >> n >> e;
    
    int **G = new int*[n];
    for(int i=0;i<n;i++) {
        G[i] = new int[n];
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(i == j) {
                G[i][j] = 0;
            } else {
                G[i][j] = INT_MAX;
            }
        }
    }

    for(int i=0;i<e;i++) {
        int a,b,w;
        cin >> a >> b >> w;
        G[a][b] = w;
    }

    // int G[4][4] = {{0, 5, 9999, 10},
    //         {9999, 0, 3, 9999},
    //         {9999, 9999, 0, 1},
    //         {9999, 9999, 9999, 0}};

    Floyd(G);

    return 0;

}