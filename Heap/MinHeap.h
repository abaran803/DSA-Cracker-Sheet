#include<iostream>
#include<math.h>
using namespace std;

class MinHeap {
    int *arr;
    int pos;
    int maxSize;
    int size;

    int Lchild(int i) {
        int LC = 2*i+1;
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
        if(arr[maxInd]>arr[Lchild(curr)]) {
            maxInd = Lchild(curr);
        }
        if(Rchild(curr) != -1 && arr[maxInd]>arr[Rchild(curr)]) {
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
        if(arr[curr]<arr[par]) {
            swap(arr[curr],arr[par]);
        } else {
            curr = Parent(curr);
        }
        CorrectBottomToTop(par);
    }

    public:

        MinHeap(int);
        void push(int);
        int pop();
        void TraverseHeapSort();
};

MinHeap::MinHeap(int sz) {
    arr = new int[sz];
    pos = -1;
    maxSize = 0;
    size = sz;
}

void MinHeap::push(int data) {
    if(pos >= size-1) {
        cout << "Heap is Full\n";
        return;
    }
    pos++;
    maxSize++;
    arr[pos] = data;
    CorrectBottomToTop(pos);
}

int MinHeap::pop() {
    if(pos == -1) {
        cout << "Heap is Empty\n";
        return -1;
    }
    int data = arr[0];
    swap(arr[0],arr[pos--]);
    CorrectTopToBottom(0);
    return data;
}

void MinHeap::TraverseHeapSort() {
    for(int i=0;i<maxSize;i++) {
        cout << arr[i] << ' ';
    }
}