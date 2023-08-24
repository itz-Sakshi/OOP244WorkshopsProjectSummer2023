/*
Full Name : Sakshi Sakshi
Student ID# : 112602222
Email : ssakshi7@myseneca.ca
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef SDDS_SEARCHNLIST_H_
#define SDDS_SEARCHNLIST_H_

#include "Collection.h"

namespace sdds {


    template <typename T, typename U>
    bool search(Collection<T>& col, const T* arr, int arrSize, const U& key) {
        bool found = false;
        for (int i = 0; i < arrSize; i++) {
            if (arr[i] == key) {
                col.add(arr[i]);
                found = true;
            }
        }
        return found;
    }

    template <typename T>
    void listArrayElements(const char* title, const T* arr, int arrSize) {
        std::cout << title << std::endl;
        for (int i = 0; i < arrSize; i++) {
            std::cout << i + 1 << ": " << arr[i] << std::endl;
        }
    }
}

#endif // SDDS_SEARCHNLIST_H_
