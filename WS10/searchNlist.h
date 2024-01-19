#ifndef SDDS_SEARCHNLIST_H_
#define SDDS_SEARCHNLIST_H_

#include <iostream>
#include "Collection.h"

#endif // !SDDS_SEARCHNLIST_H_

using namespace std;

namespace sdds {
    // Function to list elements of an array with a title
    template <typename T>
    void listArrayElements(const char* title, const T arr[], int size) {
        cout << title << endl;
        for (int i = 0; i < size; i++) {
            cout << i + 1 << ": " << arr[i] << endl;
        }
    }

    // Function to check if an element at a specific index matches a key
    template <typename T1, typename T2>
    bool check(T1* array, int index, T2 key) {
        return array[index] == key;
    }

    // Function to search for elements matching a key in an array and add them to a Collection
    template <typename T1, typename T2>
    bool search(T1* array, int size, T2 key, Collection<T1>& ob1) {
        bool flag = false;
        for (int i = 0; i < size; i++) {
            if (check(array, i, key)) {
                ob1.add(array[i]); // Add matching element to the Collection
                flag = true;
            }
        }
        return flag;
    }

    // Function to check if the size of one Collection is greater than the size of another Collection
    template <typename T1>
    bool sizeCheck(Collection<T1>& ob1, Collection<T1>& ob2) {
        return ob1.size() > ob2.size();
    }
}
