#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int rowM[8] = {-2,-2,+2,+2,-1,+1,-1,+1};
    int colM[8] = {-1,+1,-1,+1,-2,-2,+2,+2};
    
    bool isSafe(int row,int col,int n) {
        return (row>0 && row<=n && col>0 && col<=n);
    }

	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    // Code here
	    vector<int> vec1(N+1,0);
	    vector<vector<int>> vec(N+1,vec1);
        queue<pair<int,int>> q;
        q.push({KnightPos[0],KnightPos[1]});
        vec[KnightPos[0]][KnightPos[1]] = 1;
        int cnt = 0;
        q.push({-1,-1});
        while(!q.empty()) {
            pair<int,int> s = q.front();
            q.pop();
            // cout << s.first << ' ' << s.second << ' ' << cnt << " ~~\n";
            if(s.first == -1 && s.second == -1) {
                cnt++;
                q.push({-1,-1});
            } else if(s.first == TargetPos[0] && s.second == TargetPos[1]) {
                break;
            } else {
                for(int i=0;i<8;i++) {
                    if(isSafe(s.first+rowM[i],s.second+colM[i],N) && !vec[s.first+rowM[i]][s.second+colM[i]]) {
                        q.push({s.first+rowM[i],s.second+colM[i]});
                        vec[s.first+rowM[i]][s.second+colM[i]] = 1;
                    }
                }
            }
        }
        return cnt;
	}
};

int main() {

    freopen("inp.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int tc;
    cin >> tc;
    while(tc--) {
        vector<int>KnightPos(2);
        vector<int>TargetPos(2);
        int N;
        cin >> N;
        cin >> KnightPos[0] >> KnightPos[1];
        cin >> TargetPos[0] >> TargetPos[1];
        Solution obj;
        int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
        cout << ans << endl;
    }
}