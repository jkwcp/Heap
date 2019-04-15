//
// Created by Jackie Wang on 2019-04-10.
//

#ifndef HEAP_HEAP_HPP
#define HEAP_HEAP_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

//using singleton design pattern
template<typename T, typename C>
class heap {
private:
    //use vector to store data
    vector<T> vec;

    //A private method called heapify which accepts no parameters and returns nothing, which
    //ensures the elements in the heap are in heap form
    void heapify();

    //To use singleton pattern, hides a private constructor
    heap() {};

public:

    //To use singleton pattern, public constructor is not allowed, use a normal method instead
    void constructor(C c);

    //A method called push which accepts an element and pushes it into the heap.
    void push(T t);

    //A method called pop which accepts no parameters and removes and returns the root (max) element from the heap
    T pop();

    //A method called size which returns the number of elements in the heap.
    int size();

    //A method called is_empty which returns true if the heap is empty, else false.
    bool is_empty();

    // A method called clear( ) which delete the elements in the heap, ensuring no memory leaks
    //remain.
    void clear();

    //To use singleton pattern, reveals a public getInstance function that returns a
    //reference to a static instance of the class
    static heap &get_instance() {
        static heap instance; // Guaranteed to be destroyed.
        return instance; // Instantiated on first use.
    }

    //To use singleton pattern, disables the copy constructor
    heap(heap const &) = delete;

    //To use singleton pattern, disables the assignment operator
    void operator=(heap const &) = delete;

    //An overloaded insertion operator so we can print the heap to standard output.
    friend ostream &operator<<(std::ostream &os, const heap &obj) {
        int count = 0;
        int p = 1;
        int i = 0;
        os << "heap output:" << endl;
        while (i < obj.vec.size()) {
            os << obj.vec[i];
            if (i == count) {
                os << endl;
                count += pow(2, p);
                p++;
            } else {
                os << "  ";
            }
            i++;

        }

    }
};


template<typename T, typename C>
void heap<T, C>::push(T t) {
    vec.push_back(t);
    heapify();
}

template<typename T, typename C>
T heap<T, C>::pop() {
    T r = vec[0];
    vec.erase(vec.begin());
    heapify();
    return r;
}

template<typename T, typename C>
void heap<T, C>::heapify() {
    make_heap(vec.begin(), vec.end());
}

template<typename T, typename C>
int heap<T, C>::size() {
    return vec.size();
}

template<typename T, typename C>
bool heap<T, C>::is_empty() {
    return vec.empty();
}

template<typename T, typename C>
void heap<T, C>::clear() {
    vec.clear();
}

template<typename T, typename C>
void heap<T, C>::constructor(C c) {
    auto it = c.begin();
    for (; it != c.end(); it++) {
        vec.push_back(*it);
    }
    heapify();
}

#endif
//HEAP_HEAP_HPP
