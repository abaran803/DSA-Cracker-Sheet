#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    set<string> s;
    for(string it: wordList) {
        s.insert(it);
    }
    queue<string> q;
    q.push(beginWord);
    q.push("-1");
    int level = 0;
    while(!q.empty()) {
        if(q.size() == 1 && q.front() == "-1") {
            break;
        }
        string str = q.front();
        // cout << str << " ~~\n";
        q.pop();
        if(str == "-1") {
            level++;
            q.push("-1");
            continue;
        }
        if(str == endWord) {
            return level+1;
        }
        for(int i=0;i<str.length();i++) {
            char temp = str[i];
            for(int j=0;j<26;j++) {
                if((char)('a'+j) == temp) {
                    continue;
                }
                str[i] = (char)('a'+j);
                if(s.find(str) != s.end()) {
                    s.erase(str);
                    q.push(str);
                }
            }
            str[i] = temp;
        }
    }
    return 0;
}

int main() {

    freopen("inp.txt","r",stdin);
    freopen("out.txt","w",stdout);

    string begWord,endWord;
    cin >> begWord >> endWord;
    vector<string> wordList;
    int n;
    cin >> n;
    for(int i=0;i<n;i++) {
        string str;
        cin >> str;
        wordList.push_back(str);
    }

    cout << ladderLength(begWord,endWord,wordList);

    return 0;

}