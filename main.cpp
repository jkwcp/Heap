#include <iostream>
#include <list>
#include "heap.hpp"

//use case:
//Sometimes we want to store some data in a heap,
//and make sure all data is in same type and only one heap exists,
//then we can use singleton pattern.

int main() {
// Instantiates the singleton heap object on its first use
    cout << "Construct:" << endl;
    list<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    heap<int, list<int>>::get_instance().constructor(v);
    cout << heap<int, list<int>>::get_instance();
    cout << endl;

//test push method
    cout << "Push 10 , 11 , 12: " << endl;
    heap<int, list<int>>::get_instance().push(10);
    heap<int, list<int>>::get_instance().push(11);
    heap<int, list<int>>::get_instance().push(12);
    cout << heap<int, list<int>>::get_instance();
    cout << endl;

//test pop method
    cout << "Pop:" << heap<int, list<int>>::get_instance().pop() << endl;
    cout << heap<int, list<int>>::get_instance();
    cout << endl;
    cout << "Pop:" << heap<int, list<int>>::get_instance().pop() << endl;
    cout << heap<int, list<int>>::get_instance();
    cout << endl;

//test size method
    cout << "Size: " << heap<int, list<int>>::get_instance().size() << endl;

//test is_empty method
    cout << "Is empty? " << heap<int, list<int>>::get_instance().is_empty() << endl;

//test clear method
    cout << "Clear" << endl;
    heap<int, list<int>>::get_instance().clear();
    cout << heap<int, list<int>>::get_instance();
    cout << endl;

//test is_empty method
    cout << "Is empty? " << heap<int, list<int>>::get_instance().is_empty() << endl;

    return 0;
}