#include<iostream>
using namespace std;

template<typename T>
class Queue {
    T *arr;
    int fro;
    int rear;
    int size;
    int capacity;

    public:
        Queue(int cap) {
            size = 0;
            fro = -1;
            rear = -1;
            capacity = cap;
            arr = new T[cap];
        }

        bool isFull() {
            return (size == capacity);
        }

        bool isEmpty() {
            return (size == 0);
        }
        
        void enqueue(T data) {
            if(isFull()) {
                cout << "Queue Overflow\n";
                return;
            }
            if(isEmpty()) {
                fro++;
                arr[fro] = data;
            }
            size++;
            rear++;
            arr[rear] = data;
        }

        T dequeue() {
            if(isEmpty()) {
                cout << "Stack Underflow\n";
                return (T)(0);
            }
            size--;
            int data = arr[fro];
            fro++;
            if(isEmpty()) {
                fro = -1;
                rear = -1;
            }
            return data;
        }

        T front() {
            if(isEmpty()) {
                cout << "Stack is Empty\n";
                return (T)(0);
            }
            return arr[fro];
        }

        T back() {
            if(isEmpty()) {
                cout << "Stack is Empty\n";
                return (T)(0);
            }
            return arr[rear];
        }
};

int main() {

    freopen("inp.txt","r",stdin);
    freopen("out.txt","w",stdout);

    Queue<int> q(10);
    q.enqueue(50);
    q.enqueue(150);
    q.enqueue(200);
    q.enqueue(250);
    cout << q.front() << endl;
    cout << q.back() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    return 0;
}