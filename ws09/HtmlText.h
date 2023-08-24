/*
Full Name : Sakshi Sakshi
Student ID# : 112602222
Email : ssakshi7@myseneca.ca
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef SDDS_HTMLTEXT_H__
#define SDDS_HTMLTEXT_H__
#include "Text.h"
namespace sdds {
   class HtmlText :  public Text {
      char* m_title;
   public:
      HtmlText(const char* filename=nullptr, const char* title = nullptr);
      //Rule of three
      HtmlText(const HtmlText& otherHtml);//copy constructor
      HtmlText& operator=(const HtmlText& otherHtml);
      ~HtmlText();

      virtual void write(std::ostream& os)const;



   };
}
#endif // !SDDS_HTMLTEXT_H__
