#include<iostream>
using namespace std;
#define MAX 1000

template<typename T>
class Stack {
    T arr[MAX];
    int pos = -1;
    public:
        T top() {
            if(pos == -1) {
                cout << "Stack is Empty\n";
                return -1;
            }
            return arr[pos];
        }
        bool isEmpty() {
            return (pos == -1);
        }
        bool isFull() {
            return (pos == MAX);
        }
        void push(T data) {
            if(isFull()) {
                cout << "Stack Overflow\n";
            }
            arr[++pos] = data;
        }
        T pop() {
            if(isEmpty()) {
                cout << "Stack Underflow\n";
                return -1;
            }
            T data = arr[pos--];
            return data;
        }
        int size() {
            return pos+1;
        }
};

int main() {

    freopen("inp.txt","r",stdin);
    freopen("out.txt","w",stdout);

    Stack<char> st;
    st.push('A');
    st.push('Y');
    st.push('U');
    st.push('S');
    st.push('H');
    cout << st.size() << endl;
    cout << st.top() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.size() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.top() << endl;
    cout << st.size() << endl;
    
    return 0;
}