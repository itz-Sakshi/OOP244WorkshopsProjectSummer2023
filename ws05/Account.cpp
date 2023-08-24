/*
Full Name : Sakshi Sakshi
Student ID#  : 112602222
Email : ssakshi7@myseneca.ca
Date : 16 - 06 - 2023
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
* **********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {
   void Account::setEmpty() {
      m_number = -1;
      m_balance = 0.0;
   }
   // New account
   Account::Account() {  
      m_number = 0;
      m_balance = 0.0;
   }
   Account::Account(int number, double balance ) {
      setEmpty();
      if (number >= 10000 && number <= 99999
         && balance > 0) {
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream& Account::display() const{
      if (*this) {  
         cout << " ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if(~*this) {
         cout << "  NEW  |         0.00 ";
      }
      else {
         cout << "  BAD  |    ACCOUNT   ";
      }
      return cout;
   }

   Account::operator bool()const
   {
       return (m_number > 0 && m_balance >= 0.0);
   }
   
   Account::operator int()const
   {
       return m_number;
   }

   Account::operator double()const
   {
       return m_balance;
   }

   bool Account::operator ~()const
   {
       return m_number == 0;
   }

   Account& Account::operator=(int number)
   {
       if (m_number == 0)
       {
           if (number >= 10000 && number <= 99999)
           {
               m_number = number;
               m_balance = 0.0;
           }
           else
           {
               setEmpty();
           }
       }
       return *this;

   }

   Account& Account::operator=(Account& source) {
       if (m_number != source.m_number && m_number == 0 && source.m_number > 0) {
           // shallow copy non-resource variables
           m_number = source.m_number;
           m_balance = source.m_balance;
           source.m_balance = 0.0;
           source.m_number = 0;
       }
       return *this;
   }

   Account& Account::operator+=(double deposit)
   {
       if (m_number > 0 && deposit > 0)
       {
           m_balance += deposit;
       }
       return *this;
   }
   Account& Account::operator-=(double withdrawal)
   {
       if (m_number > 0 && withdrawal > 0 && withdrawal <= m_balance)
       {
           m_balance -= withdrawal;
       }
       return *this;
   }
    
   Account& Account::operator>>(Account& source)
   {
       if (m_number != 0 && m_number != source.m_number)
       {
           source.m_balance += m_balance;
           m_balance = 0.0;
       }
       return *this;
   }

   Account& Account::operator<<(Account& source)
   {
      if (*this && m_number != source.m_number)
       {
           m_balance += source.m_balance;
           source.m_balance = 0;
       }
       return *this;
       /*if (*this && m_number != otherAcc.m_number) {
           m_balance += otherAcc.m_balance;
           otherAcc.m_balance = 0.0;
       }
       return *this;*/
   }

   double operator+(const Account& left, const Account& right) 
   {
       double result = 0.0;
       if (left && right)
       {
           result = double(left) + double(right);
       }
       return result;
   }

   double operator+=(double& left, const Account& right) 
   {
       if (right) {
           left += double(right);
       }
       return left;
   }
}