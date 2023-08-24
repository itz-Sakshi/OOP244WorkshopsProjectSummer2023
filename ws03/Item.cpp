/*
Workshop 3 - Part 1
Full Name : Sakshi Sakshi
Student ID# : 112602222
Email : ssakshi7@myseneca.ca
Date : 02 - 06 - 2023
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************/

#include <iostream>
#include "cstring.h"
#include "Item.h"
using namespace std;
namespace sdds {
    void Item::setName(const char* name)
    {
        strnCpy(m_itemName, name, 20);
        m_itemName[20] = '\0';
    }
    void Item::setEmpty()
    {
        m_itemName[0] = '\0';
        m_price = 0.0;
    }
    void Item::set(const char* name, double price, bool taxed)
    {
        if (price < 0 || name == nullptr)
        {
            setEmpty();
        }
        else
        {
            setName(name);
            m_price = price;
            m_taxed = taxed;
        }
    }
    void Item::display()const
    {
        if (isValid())
        {
            cout << "| ";
            cout.width(20);
            cout.setf(ios::left);
            cout.fill('.');
            cout << m_itemName;
            
            cout.unsetf(ios::left);
            cout << " | ";
            cout.width(7);
            cout.fill(' ');
            cout.precision(2);
            cout << fixed << m_price;
            cout.unsetf(ios::fixed);
            cout << " |";
            if (m_taxed)
            {
                cout << " Yes |";
            }
            else
            {
                cout << " No  |";
            }
            cout << endl;
            cout.precision(6);

        }
        
        else
        {
            cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
        }
    }
    bool Item::isValid() const
    {
        bool valid1 = true;
        if (m_itemName[0] == '\0' || m_price == 0.0)
        {
            valid1 = false;
        }
        return valid1;
    }
    double Item::price() const
    {
        return m_price;
    }
    double Item::tax() const
    {
        double tax1 = 0.0;
        double const taxRate = 0.13;
        if (m_taxed == true)
        {
            tax1 = (taxRate * m_price);
        }
        return tax1;
    }
}