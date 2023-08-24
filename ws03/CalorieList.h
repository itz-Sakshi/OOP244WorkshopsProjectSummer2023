/*
Full Name : Sakshi Sakshi
Student ID# : 112602222
Email : ssakshi7@myseneca.ca
Date : 03 - 06 - 2023
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef SDDS_CALORIELIST_H_
#define SDDS_CALORIELIST_H_
#include "Food.h"
namespace sdds {
    class CalorieList {
        Food* m_foodItems;
        int m_noOfItems;
        int m_itemsAdded;
        int totalCal()const;
        void Title()const;
        void footer()const;
        void setEmpty();
        bool isValid()const;
    public:
        void init(int size);
        bool add(const char* item_name, int calorie, int when);
        void display()const;
        void deallocate();
    };
}
#endif // !SDDS_CALORIELIST_H