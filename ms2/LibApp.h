/*
Full Name : Sakshi Sakshi
Student ID#  : 112602222
Email : ssakshi7@myseneca.ca
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
* **********************************************************************/

#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H

#include <iostream>
#include "Menu.h"

namespace sdds {
   class LibApp {
   private:
       bool m_changed;
       Menu m_mainMenu;
       Menu m_exitMenu;
       
       bool confirm(const char* message);       
       void load();
       void save();
       void search();
       void returnPub();
       void newPublication();
       void removePublication();
       void checkOutPub();

   public:
       LibApp();
       void run();
   };
}
#endif // !SDDS_LIBAPP_H



