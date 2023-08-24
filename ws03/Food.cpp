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
#include "Food.h"
using namespace std;
namespace sdds {
    void Food::setName(const char* name)
    {
        strnCpy(m_foodName, name, 30);
        m_foodName[30] = '\0';
    }
    void Food::setEmpty()
    {
        m_foodName[0] = '\0';
        m_cal = 0;
        m_time_of_consumption = 0;
    }
    void Food::set(const char* name, int cal, int mealTime)
    {
        if (m_cal < 0 || m_cal > 3000 || name == nullptr || (mealTime != 1 && mealTime != 2 && mealTime != 3 && mealTime != 4))
        {
            setEmpty();
        }
        else
        {
            setName(name);
            m_cal = cal;
            m_time_of_consumption = mealTime;
        }
    }
    void Food::display()const
    {
        if (isValid())
        {
            cout << "| ";
            cout.width(30);
            cout.unsetf(ios::right);
            cout.setf(ios::left);
            cout.fill('.');
            cout << m_foodName;
            cout.fill(' ');
            //cout.unsetf(ios::left);
            cout << " | ";
            cout.width(4);
            cout.setf(ios::fixed);
            //cout.precision(2);
            cout.unsetf(ios::left);
            cout.setf(ios::right);
            cout << m_cal;
            //cout.unsetf(ios::fixed);
            cout << " | ";
            if (m_time_of_consumption == 1)
            {
                cout << "Breakfast  |";
            }
            else if (m_time_of_consumption == 2)
            {
                cout << "Lunch      |";
            }
            else if (m_time_of_consumption == 3)
            {
                cout << "Dinner     |";
            }
            else
            {
                cout << "Snack      |";
            }
            cout << endl;
            //cout.precision(6);

        }

        else
        {
            cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
        }
    }
    bool Food::isValid() const
    {
        bool valid1 = true;
        if (m_foodName[0] == '\0' || m_cal == 0 || m_time_of_consumption == 0)
        {
            valid1 = false;
        }
        return valid1;
    }
    int Food::calorie() const
    {
        return m_cal;
    }
    int Food::consumptionTime() const
    {
        return m_time_of_consumption;
    }
    
}