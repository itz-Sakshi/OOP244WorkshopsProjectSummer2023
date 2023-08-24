/*
Full Name : Sakshi Sakshi
Student ID# : 112602222
Email : ssakshi7@myseneca.ca
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************/
#include "HtmlText.h"
#include <iostream>
#include "cstring.h"

namespace sdds {
    HtmlText::HtmlText(const char* filename, const char* title) : Text(filename)
    {
        m_title = nullptr;
        if (title != nullptr)
        {
            m_title = new char[strLen(title) + 1];
            strCpy(m_title, title);
        }
    }
    //Rule of three
    HtmlText::HtmlText(const HtmlText& otherHtml) : Text(otherHtml) //copy constructor
    {
        m_title = nullptr;
        *this = otherHtml;
    }
    HtmlText& HtmlText::operator=(const HtmlText& otherHtml)
    {
        if (this != &otherHtml) {
            Text::operator=(otherHtml);
            delete[] m_title;
            if (otherHtml.m_title) 
            {
                m_title = new char[strLen(otherHtml.m_title) + 1];
                strCpy(m_title, otherHtml.m_title);
            }
            else {
                m_title = nullptr;
            }
        }
        return *this;
    }
    HtmlText::~HtmlText()
    {
        delete[] m_title;
    }

    void HtmlText::write(std::ostream& os)const
    {
        os << "<html><head><title>";
        if (m_title) {
            os << m_title;
        }
        else {
            os << "No Title";
        }
        os << "</title></head>\n<body>\n";
        if (m_title) {
            os << "<h1>" << m_title << "</h1>\n";
        }
        bool multipleSpaces = false;
        for (int i = 0; this->operator[](i); i++) {
            char ch = this->operator[](i);
            if (ch == ' ') {
                if (!multipleSpaces) {
                    os << ' ';
                    multipleSpaces = true;
                }
                else {
                    os << "&nbsp;";
                }
            }
            else if (ch == '<') {
                os << "&lt;";
                multipleSpaces = false;
            }
            else if (ch == '>') {
                os << "&gt;";
                multipleSpaces = false;
            }
            else if (ch == '\n') {
                os << "<br />\n";
                multipleSpaces = false;
            }
            else {
                os << ch;
                multipleSpaces = false;
            }
        }
        os << "</body>\n</html>";
    }
}