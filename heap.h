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
        upheap(size , weightArr);   //move up to restore order
        size++;               //heap size increases


    }

    int pop(int weightArr[]) {
        if (size == 0)
            return -1;
                            //Saving root and heap size decreases
        int top = data[0];
        size --;             //Last element gets moved to root and then restore order moving down
        if (size > 0) {
            data[0] = data[size];
            downheap(0, weightArr);
        } //index of smallest element
        return top;
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()
        return -1; // placeholder
    }

    void upheap(int pos, int weightArr[]) {
        while (pos > 0) {
            int parent = (pos -1) /2;       //Swap if smaller than parent
            if (weightArr[data[pos]] < weightArr[data[parent]]){
                swap (data[pos], data[parent]);
                pos = parent;            //Move to position of parent
            }
            else {
                break;            //restore heap property
            }
        }

        // TODO: swap child upward while smaller than parent
    }

    void downheap(int pos, int weightArr[]) { //
        while (true) {
            int left = 2 * pos + 1;
            int right = 2 * pos + 2;
            int smallest = pos;
                     //Find smallest child
            if (left < size && weightArr[data[left]] < weightArr[data[smallest]])
                smallest = left;
            if (right < size && weightArr[data[right]] < weightArr[data[smallest]])
                smallest = right;
                //Swap if parent is larger
            if (smallest != pos) {
                swap (data[pos], data[smallest]);
                pos = smallest;         //Continue down
            }
            else {
                break;
            }
        }



        // TODO: swap parent downward while larger than any child
    }
};

#endif