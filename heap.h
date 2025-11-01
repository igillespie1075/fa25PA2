//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        // TODO: insert index at end of heap, restore order using upheap()
        data[size] = idx;
        upheap(size, weightArr);
        size++;
    }

    int pop(int weightArr[]) {
        if (size == 0)
            return -1;

        int top = data[0];
        size --;
        if (size > 0) {
            top = data[size];
            downheap(0, weightArr);
        }
        return top;
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()
        return -1; // placeholder
    }

    void upheap(int pos, int weightArr[]) {
        while (pos > 0) {
            int parent = (pos -1) /2;
            if (weightArr[data[pos]] < weightArr[data[parent]]){
                swap (data[pos], data[parent]);
                pos = parent;
            }
            else break;
        }
        // TODO: swap child upward while smaller than parent
    }

    void downheap(int pos, int weightArr[]) {
        while (true) {
            int left = 2 * pos + 1;
            int right = 2 * pos + 2;
            int smallest = pos;

            if ()
        }
        // TODO: swap parent downward while larger than any child
    }
};

#endif