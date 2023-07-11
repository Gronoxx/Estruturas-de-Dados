#ifndef MIN_PRIORITY_QUEUE_HPP
#define MIN_PRIORITY_QUEUE_HPP

#include <iostream>
#include "no.hpp"
class MinPriorityQueue {
private:
    No** heap;
    int capacity;
    int size;
    int aux;

    int parent(int i);
    int leftChild(int i);
    int rightChild(int i);
    void resize(int newCapacity);
    void heapifyUp(int i);
    void heapifyDown(int i);

public:
    MinPriorityQueue();
    ~MinPriorityQueue();
    bool empty();
    void insert(No* no);
    No* getMin();
    No* removeMin();
    int Get_size();
};

#endif
