#include<iostream>
using namespace std;

class nStack {
    public:
        int *top;
        int *arr;
        int *next;
        int free;

        nStack(int n,int sz) {
            arr = new int[sz];
            next = new int[sz];
            for(int i=0;i<sz;i++) {
                next[i] = i+1;
            }
            next[sz-1] = -1;
            top = new int[n];
            for(int i=0;i<n;i++) {
                top[i] = -1;
            }
            free = 0;
        }

        void push(int n,int data) {
            if(free == -1) {
                cout << "All stacks are full\n";
                return;
            }
            int j = top[n];
            arr[free] = data;
            top[n] = free;
            int i = free;
            free = next[free];
            next[i] = j;
        }

        int pop(int n) {
            if(top[n] == -1) {
                cout << "All stacks are empty\n";
                return -1;
            }
            int data = arr[top[n]];
            next[top[n]] = free;
            free = top[n];
            top[n] = next[top[n]];
            return data;
        }
};

int main() {

    freopen("inp.txt","r",stdin);
    freopen("out.txt","w",stdout);

    nStack ns(3,10);
    ns.push(2,15);
    ns.push(2,45);
    ns.push(1,17);
    ns.push(1,49);
    ns.push(1,39);
    ns.push(0,11);
    ns.push(0,9);
    ns.push(0,7);

    cout << "Popped element from stack 2 is " << ns.pop(2) << endl; 
    cout << "Popped element from stack 1 is " << ns.pop(1) << endl; 
    cout << "Popped element from stack 0 is " << ns.pop(0) << endl; 

    return 0;
}