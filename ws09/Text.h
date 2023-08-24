/*
Full Name : Sakshi Sakshi
Student ID# : 112602222
Email : ssakshi7@myseneca.ca
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef SDDS_TEXT_H__
#define SDDS_TEXT_H__

#include <iostream>

namespace sdds {
   class Text {
      char* m_filename ;
      char* m_content ;
      int getFileLength()const;
   protected:
      const char& operator[](int index)const;
   public:
      Text(const char* filename = nullptr);
      //Rule of three
      Text(const Text& otherText);//copy constructor
      Text& operator=(const Text& otherText);
      ~Text();

      void read();
      virtual void write(std::ostream& os)const;
   };

   std::ostream& operator<<(std::ostream& os, const Text& text);
}
#endif // !SDDS_PERSON_H__

