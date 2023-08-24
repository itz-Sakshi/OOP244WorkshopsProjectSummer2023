/*
Full Name : Sakshi Sakshi
Student ID#  : 112602222
Email : ssakshi7@myseneca.ca
Date : 17 - 06 - 2023
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
* **********************************************************************/
#ifndef SDDS_MARK_H
#define SDDS_MARK_H

namespace sdds 
{
    class Mark 
    {
        int m_mark;
    public:
        Mark();
        Mark(int mark);
        operator int() const;
        Mark& operator+=(int value);
        Mark& operator=(int mark);
        operator double() const;
        operator char() const;
        int returnMark() const; // Extra function used for helper function
    };

    int operator+=(int& value, const Mark& mark);
}

#endif

