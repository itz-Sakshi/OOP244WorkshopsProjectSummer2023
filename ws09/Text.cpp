/*
Full Name : Sakshi Sakshi
Student ID# : 112602222
Email : ssakshi7@myseneca.ca
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************/
#include <fstream>
#include "Text.h"
#include "cstring.h"
using namespace std;
namespace sdds {
   int Text::getFileLength() const {
      int len = 0;
      ifstream fin(m_filename);
      while (fin) {
         fin.get();
         len += !!fin;
      }
      return len;
   }

   const char& Text::operator[](int index)const
   {
       return m_content[index];
   }
   Text::Text(const char* filename) : m_filename(nullptr), m_content(nullptr)
   {
       if (filename != nullptr)
       {
           m_filename = new char[strLen(filename) + 1];
           strCpy(m_filename, filename);
           read();
       }
   }
    //Rule of three
   Text::Text(const Text& otherText)//copy constructor
   {
       m_filename = nullptr;
       m_content = nullptr;
       *this = otherText;
   }
   Text& Text::operator=(const Text& otherText)
   {
       if (this != &otherText)
       {
           delete[] m_filename;
           delete[] m_content;
           if (otherText.m_filename)
           {
               m_filename = new char[strLen(otherText.m_filename) + 1];
               strCpy(m_filename, otherText.m_filename);
           }
           else
           {
               m_filename = nullptr;
           }
           if (otherText.m_content)
           {
               m_content = new char[strLen(otherText.m_content) + 1];
               strCpy(m_content, otherText.m_content);
           }
           else
           {
               m_content = nullptr;
           }
       }
       return *this;
   }
   Text::~Text()
   {
       delete[] m_filename;
       delete[] m_content;
   }

   void Text::read()
   {
       int length = getFileLength();
       if (length > 0) 
       {
           //delete[] m_content;
           m_content = new char[length + 1];
           std::ifstream file(m_filename);
           file.read(m_content, length);
           m_content[length] = '\0';
       }
   }
   void Text::write(std::ostream& os)const
   {
       if (m_content != nullptr) 
       {
           os << m_content;
       }
   }
   std::ostream& operator<<(std::ostream& os, const Text& text)
   {
       text.write(os);
       return os;
   }
}