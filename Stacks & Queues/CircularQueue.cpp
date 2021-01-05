#include<iostream>
using namespace std;

class CircularQueue {
    int *arr;
    int size;
    int front;
    int rear;

    public:

        CircularQueue(int sz) {
            arr = new int[sz];
            size = sz;
            front = -1;
            rear = -1;
        }

        void enQueue(int data) {
            if(isFull()) {
                cout << "Queue Overflow\n";
                return;
            }
            if(front == -1) {
                front++;
            }
            rear++;
            rear %= size;
            arr[rear] = data;
        }

        int deQueue() {
            if(isEmpty()) {
                cout << "Queue Underflow\n";
                return -1;
            }
            int data = arr[front];
            arr[front] = -1;
            if(front == rear) {
                front = rear = -1;
            }
            else {
                front++;
                front %= size;
            }
            return data;
        }

        bool isEmpty() {
            return (front == -1);
        }

        bool isFull() {
            return ((rear == size-1 && front == 0) || (rear == (front-1)));
        }

        void displayQueue() {
            if(isEmpty()) {
                cout << "Queue is Empty\n";
                return;
            }
            if(front <= rear) {
                for(int i=front;i<=rear;i++) {
                    cout << arr[i] << ' ';
                }
            } else {
                for(int i=front;i<size;i++) {
                    cout << arr[i] << ' ';
                }
                for(int i=0;i<rear;i++) {
                    cout << arr[i] << ' ';
                }
            }
            cout << endl;
        }
};

int main() {

    freopen("out.txt","w",stdout);

    CircularQueue q(5);

    q.enQueue(14); 
    q.enQueue(22); 
    q.enQueue(13); 
    q.enQueue(-6); 

    q.displayQueue();

    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;
    
    q.displayQueue(); 
  
    q.enQueue(9); 
    q.enQueue(20); 
    q.enQueue(5); 
  
    q.displayQueue(); 
  
    q.enQueue(20); 

    return 0;
}