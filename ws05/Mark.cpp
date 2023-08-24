/*
Full Name : Sakshi Sakshi
Student ID#  : 112602222
Email : ssakshi7@myseneca.ca
Date : 17 - 06 - 2023
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
* **********************************************************************/
#include "Mark.h"

namespace sdds {
    Mark::Mark()
    {
        m_mark = 0;
    }

    Mark::Mark(int mark) 
    {
        if (mark >= 0 && mark <= 100)
            m_mark = mark;
        else
            m_mark = -1; // Invalid state
    }

    Mark::operator int() const 
    {
        return (m_mark >= 0 && m_mark <= 100) ? m_mark : 0;
    }

    Mark& Mark::operator+=(int value) 
    {
        if (m_mark >= 0 && m_mark <= 100) 
        {
            m_mark += value;
            if (m_mark > 100 || m_mark < 0)
            {
                m_mark = -1; // Invalid state
            }
        }
        return *this;
    }

    Mark& Mark::operator=(int mark) {
        if (mark >= 0 && mark <= 100)
            m_mark = mark;
        else
            m_mark = -1; // Invalid state
        return *this;
    }

    Mark::operator double() const 
    {
        if (m_mark >= 0 && m_mark < 50)
            return 0.0;
        else if (m_mark < 60 && m_mark >= 50)
            return 1.0;
        else if (m_mark < 70 && m_mark >= 60)
            return 2.0;
        else if (m_mark < 80 && m_mark >= 70)
            return 3.0;
        else if (m_mark <= 100 && m_mark >= 80)
            return 4.0;
        else
            return 0.0; // Invalid state
    }

    Mark::operator char() const 
    {
        if (m_mark >= 0 && m_mark < 50)
            return 'F';
        else if (m_mark < 60 && m_mark >=50)
            return 'D';
        else if (m_mark < 70 && m_mark >= 60)
            return 'C';
        else if (m_mark < 80 && m_mark >= 70)
            return 'B';
        else if (m_mark <= 100 && m_mark >=80)
            return 'A';
        else
            return 'X'; // Invalid state
    }

    int Mark::returnMark() const
    {        
         return m_mark;   
    }

    int operator+=(int& value, const Mark& mark) 
    {
        if (mark.returnMark() >= 0 && mark.returnMark() <= 100)
        {
            value += mark.returnMark();
        }
        return value;
    }
}
