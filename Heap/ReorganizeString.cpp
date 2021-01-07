#include<iostream>
#include<queue>
using namespace std;

string reorganizeString(string S) {
    
}

int main() {

    freopen("inp.txt","r",stdin);
    freopen("out.txt","w",stdout);

    string str;
    cin >> str;
    int arr[26];
    priority_queue<pair<int,char>> pq;
    for(int i=0;i<26;i++) {
        arr[i] = 0;
    }
    for(int i=0;i<str.length();i++) {
        arr[str[i]-'a']++;
    }
    for(int i=0;i<26;i++) {
        pq.push({arr[i],(char)(i+'a')});
    }
    for(int i=0;i<26;i++) {
        cout << (pq.top()).first << ' ' << (pq.top()).second << ' ' << endl;
        pq.pop();
    }
    // str = reorganizeString(str);
    // cout << str;
}