/*
Full Name : Sakshi Sakshi
Student ID# : 112602222
Email : ssakshi7@myseneca.ca
Date : 09 - 06 - 2023
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef SDDS_BOX_H
#define SDDS_BOX_H
#include <iostream>
namespace sdds {
   const double PI = 3.14159265;
   class Canister {
      char* m_contentName;
      double m_diameter; // in centimeters 
      double m_height;   // in centimeters
      double m_contentVolume;  // in CCs
      bool m_usable;
      void setToDefault();
      void setName(const char* Cstr);
      bool isEmpty()const;
      bool hasSameContent(const Canister& C)const;
   public:
      Canister();
      Canister(const char* contentName);
      Canister(double height, double diameter,
         const char* contentName = nullptr);
      ~Canister();
      Canister& setContent(const char* contentName);
      Canister& pour(double quantity);
      Canister& pour(Canister&);
      double volume()const;
      std::ostream& display()const;
      double capacity()const;
      void clear();
   };
}

#endif // !SDDS_BOX_H
