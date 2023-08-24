/*
Full Name : Sakshi Sakshi
Student ID# : 112602222
Email : ssakshi7@myseneca.ca
Date : 03 - 06 - 2023
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************/
#include <iostream>
#include "cstring.h"
#include "CalorieList.h"
using namespace std;
namespace sdds {
    int CalorieList::totalCal()const
    {
        double calSum = 0;
        for (int i = 0; i < m_noOfItems; i++)
        {
            calSum += m_foodItems[i].calorie();
        }
        return calSum;

    }
    void CalorieList::Title() const
    {
        cout << "+----------------------------------------------------+" << endl;
        if (isValid())
        {
            cout << "|  ";
            cout.width(49);
            cout.fill(' ');
            cout.unsetf(ios::right);
            cout.setf(ios::left);
            cout << "Daily Calorie Consumption";
            //cout.unsetf(ios::left);
            cout << " |" << endl;
        }
        else
        {
            cout << "| Invalid Calorie Consumption list                   |" << endl;
        }
        cout << "+--------------------------------+------+------------+" << endl;
        cout << "| Food name                      | Cals | When       |" << endl;
        cout << "+--------------------------------+------+------------+" << endl;

    }
    void CalorieList::footer()const
    {
        cout << "+--------------------------------+------+------------+" << endl;
        if (isValid())
        {
            cout << "|    Total Calories for today: ";
            cout.setf(ios::fixed);
            cout.setf(ios::right);
            //cout.precision(2);
            cout.fill(' ');
            cout.width(8);
            //cout.setf(ios::right);
            cout << totalCal() << " |" << "            |" << endl;
            //cout.unsetf(ios::right);
            //cout.precision(6);
            cout << "+----------------------------------------------------+" << endl;
        }
        else
        {
            //cout << "+--------------------------------+------+------------+" << endl;
            cout << "|    Invalid Calorie Consumption list                |" << endl;
            cout << "+----------------------------------------------------+" << endl;
        }
    }
    void CalorieList::setEmpty()
    {
        m_noOfItems = 0;
        m_itemsAdded = 0;
        deallocate();
    }

    bool CalorieList::isValid()const
    {
        bool valid = true;
        if (m_foodItems != nullptr)
        {
            for (int i = 0; i < m_noOfItems; i++)
            {
                if (!(m_foodItems[i].isValid()))
                {
                    valid = false;
                }
            }
        }
        else
        {
            valid = false;
        }
        return valid;
    }
    void CalorieList::init(int size)
    {
        if (size <= 0)
        {
            setEmpty();
        }
        else
        {
            m_noOfItems = size;
            m_itemsAdded = 0;
            m_foodItems = new Food[m_noOfItems];
            for (int i = 0; i < size; i++)
            {
                m_foodItems[i].setEmpty();
            }
        }
    }
    bool CalorieList::add(const char* item_name, int calories, int when)
    {
        bool added = false;
        if (m_itemsAdded < m_noOfItems)
        {
            m_foodItems[m_itemsAdded++].set(item_name, calories, when);
            added = true;
        }
        return added;
    }
    void CalorieList::display()const
    {
        Title();
        for (int i = 0; i < m_noOfItems; i++)
        {
            m_foodItems[i].display();
        }
        footer();

    }
    void CalorieList::deallocate()
    {
        delete[] m_foodItems;
        m_foodItems = nullptr;
    }
}