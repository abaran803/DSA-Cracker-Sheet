#include<iostream>
#include<math.h>
using namespace std;

class Heap {
    int *arr;
    int pos;
    int maxSize;
    int size;

    int Lchild(int i) {
        int LC = 2*i+2;
        if(LC > pos) {
            return -1;
        }
        return LC;
    }

    int Rchild(int i) {
        int RC = 2*i+2;
        if(RC > pos) {
            return -1;
        }
        return RC;
    }

    int Parent(int i) {
        if(i <= 0) {
            return -1;
        }
        int p = (i-1)/2;
        return p;
    }

    void CorrectTopToBottom(int curr) {
        if(Lchild(curr) == -1) {
            return;
        }
        int maxInd = curr;
        if(arr[maxInd]<arr[Lchild(curr)]) {
            maxInd = Lchild(curr);
        }
        if(Rchild(curr) != -1 && arr[maxInd]<arr[Rchild(curr)]) {
            maxInd = Rchild(curr);
        }
        if(curr != maxInd) {
            swap(arr[curr],arr[maxInd]);
            CorrectTopToBottom(maxInd);
        }
    }

    void CorrectBottomToTop(int curr) {
        int par = Parent(curr);
        if(par == -1) {
            return;
        }
        if(arr[curr]>arr[par]) {
            swap(arr[curr],arr[par]);
        } else {
            curr = Parent(curr);
        }
        CorrectBottomToTop(par);
    }

    public:

        Heap(int);
        void push(int);
        int pop();
        void TraverseHeapSort();
};

Heap::Heap(int sz) {
    arr = new int[sz];
    pos = -1;
    size = sz;
    maxSize = 0;
}

void Heap::push(int data) {
    if(pos >= size-1) {
        cout << "Heap is Full\n";
        return;
    }
    maxSize++;
    pos++;
    arr[pos] = data;
    CorrectBottomToTop(pos);
}

int Heap::pop() {
    if(pos == -1) {
        cout << "Heap is Empty\n";
        return -1;
    }
    int data = arr[0];
    swap(arr[0],arr[pos--]);
    CorrectTopToBottom(0);
    return data;
}

void Heap::TraverseHeapSort() {
    for(int i=0;i<maxSize;i++) {
        cout << arr[i] << ' ';
    }
}