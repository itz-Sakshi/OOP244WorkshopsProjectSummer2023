/*
Full Name : Sakshi Sakshi
Student ID#  : 112602222
Email : ssakshi7@myseneca.ca
Date : 16 - 06 - 2023
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
* **********************************************************************/
#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
   class Account {
      int m_number;
      double m_balance; 
      void setEmpty();
   public:
      Account();
      Account(int number, double balance);
      std::ostream& display()const;
      operator bool()const;
      operator int()const;
      operator double()const;
      bool operator ~()const;
      Account& operator=(int);
      Account& operator=(Account&);
      Account& operator<<(Account&);
      Account& operator>>(Account&);
      Account& operator+=(double deposit);
      Account& operator-=(double withdrawal);
   };
   double operator+(const Account& left, const Account& right);

   double operator+=(double& left, const Account& right);
   
}
#endif // SDDS_ACCOUNT_H_