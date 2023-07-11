#include "../include/MinPriorityQueue.hpp"
#include <iostream>

using namespace std;

int MinPriorityQueue::parent(int i) {
    return (i - 1) / 2;
}

int MinPriorityQueue::leftChild(int i) {
    return 2 * i + 1;
}

int MinPriorityQueue::rightChild(int i) {
    return 2 * i + 2;
}

void MinPriorityQueue::resize(int newCapacity) {
    No** newHeap = new No*[newCapacity];
    for (int i = 0; i < size; i++) {
        newHeap[i] = heap[i];
    }
    heap = newHeap;
    capacity = newCapacity;
}

void MinPriorityQueue::heapifyUp(int i) {
    while (i > 0 && heap[parent(i)]->freq > heap[i]->freq) {
        swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}

void MinPriorityQueue::heapifyDown(int i) {
    int smallest = i;
    int left = leftChild(i);
    int right = rightChild(i);

    if (left < size && heap[left]->freq < heap[smallest]->freq)
        smallest = left;

    if (right < size && heap[right]->freq < heap[smallest]->freq)
        smallest = right;

    if (smallest != i) {
        swap(heap[i], heap[smallest]);
        heapifyDown(smallest);
    }
}

MinPriorityQueue::MinPriorityQueue() : heap(nullptr), capacity(0), size(0),aux(0) {}

MinPriorityQueue::~MinPriorityQueue() {
    //não é necessário liberar, pois a própria árvore libera a memória
}

bool MinPriorityQueue::empty() {
    return size == 0;
}

void MinPriorityQueue::insert(No* no) {
    if (size == capacity) {
        int newCapacity = (capacity == 0) ? 1 : 2 * capacity;
        resize(newCapacity);
    }
    heap[size] = no;
    size++;
    heapifyUp(size - 1);
}

No* MinPriorityQueue::getMin() {
    if (empty()) {
        cerr << "Priority queue is empty!" << endl;
        return nullptr; // or throw an exception
    }
    return heap[0];
}

No* MinPriorityQueue::removeMin() {
    if (empty()) {
        cerr << "Priority queue is empty!" << endl;
        return NULL; // or throw an exception
        }
    No * p = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
    return p;
}

int MinPriorityQueue::Get_size(){
    return size;
}


