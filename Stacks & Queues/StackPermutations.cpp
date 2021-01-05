#include<iostream>
#include<stack>
#include<queue>
using namespace std;

bool Algo(int arr1[],int arr2[],int n) {
    queue<int> in,o;
    stack<int> s;
    for(int i=0;i<n;i++) {
        in.push(arr1[i]);
    }
    for(int i=0;i<n;i++) {
        o.push(arr2[i]);
    }
    while(!in.empty()) {
        int e = in.front();
        in.pop();
        if(o.front() == e) {
            o.pop();
            while(!s.empty()) {
                if(o.front() == s.top()) {
                    o.pop();
                    s.pop();
                } else {
                    break;
                }
            }
        } else {
            s.push(e);
        }
    }
    return (in.empty() && o.empty());
}

int main() {

    freopen("inp.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int n;
    cin >> n;
    int arr1[n],arr2[n];
    for(int i=0;i<n;i++) {
        cin >> arr1[i];
    }
    for(int i=0;i<n;i++) {
        cin >> arr2[i];
    }
    if(Algo(arr1,arr2,n)) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}