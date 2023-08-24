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
#include "Bill.h"
using namespace std;
namespace sdds {
    double Bill::totalTax()const
    {
        double taxSum = 0;
        for (int i = 0; i < m_noOfItems; i++)
        {
            taxSum += m_items[i].tax();
        }
        return taxSum;

    }
    double Bill::totalPrice()const
    {
        double priceSum = 0;
        for (int i = 0; i < m_noOfItems; i++)
        {
            priceSum += m_items[i].price();
        }
        return priceSum;
    }
    void Bill::Title() const
    {
        cout << "+--------------------------------------+" << endl;
        if (isValid())
        {
            cout << "| ";
            cout.width(36);
            cout.setf(ios::left);
            cout << m_title;
            cout.unsetf(ios::left);
            cout << " |" << endl;
        }
        else
        {
            cout << "| Invalid Bill                         |" << endl;
        }
        cout << "+----------------------+---------+-----+" << endl;
        cout << "| Item Name            | Price   + Tax |" << endl;
        cout << "+----------------------+---------+-----+" << endl;

    }
    void Bill::footer()const
    {
        cout << "+----------------------+---------+-----+" << endl;
        if (isValid())
        {
            cout << "|                Total Tax: ";
            cout.width(10);
            cout.precision(2);
            cout.setf(ios::right);
            cout << fixed << totalTax() << " |" << endl;
            cout << "|              Total Price: ";
            cout.width(10);
            cout << fixed << totalPrice() << " |" << endl;
            cout << "|          Total After Tax: ";
            cout.width(10);
            cout << fixed << totalPrice() + totalTax() << " |" << endl;
            cout.unsetf(ios::right);
            cout.precision(6);
            cout << "+--------------------------------------+" << endl;
        }
        else
        {
            //cout << "+--------------------------------------+" << endl;
            cout << "| Invalid Bill                         |" << endl;
            cout << "+--------------------------------------+" << endl;
        }
    }
    void Bill::setEmpty()
    {
        m_title[0] = '\0';
        deallocate();
    }

    bool Bill::isValid()const
    {
        bool valid = true;
        if (m_title[0] != '\0' && m_title[0] != '\n' && m_items != nullptr)
        {
            for (int i = 0; i < m_noOfItems; i++)
            {
                if (!(m_items[i].isValid()))
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
    void Bill::init(const char* title, int noOfItems)
    {
        if (title == nullptr || noOfItems <= 0)
        {
            setEmpty();
        }
        else
        {
            m_noOfItems = noOfItems;
            m_itemsAdded = 0;
            strnCpy(m_title, title, 36);
            m_items = new Item[m_noOfItems];
            for (int i = 0; i < noOfItems; i++)
            {
                m_items[i].setEmpty();
            }
        }
    }
    bool Bill::add(const char* item_name, double price, bool taxed)
    {
        bool added = false;
        if (m_itemsAdded < m_noOfItems)
        {
            m_items[m_itemsAdded++].set(item_name, price, taxed);
            added = true;
        }
        return added;
    }
    void Bill::display()const
    {
        Title();
        for (int i = 0; i < m_noOfItems; i++)
        {
            m_items[i].display();
        }
        footer();

    }
    void Bill::deallocate()
    {
        delete[] m_items;
        m_items = nullptr;
    }
}