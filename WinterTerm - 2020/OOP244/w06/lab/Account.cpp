//Name: Davi Leonardi Mathey
//Email: dleonardi-mathey@myseneca.ca
//ID: 154979199
//Section: OOP244NFF

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

   Account::operator bool() const
   {
       bool rtn = false;

       if (m_number >= 10000 && m_number <= 99999 && m_balance >= 0.00)
       {
           rtn = true;
       }

       return rtn;
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

   Account& Account::operator= (int num)
   {
       if (~*this)
       {
           if (num < 10000)
           {
               m_number = -1;
               m_balance = 0.00;
           }
           else
           {
               m_number = num;
           }
       }
     
       return *this;
   }

   Account& Account::operator= (Account& obj)
   {
       if (~(*this) && obj)
       {
           m_number = obj.m_number;
           obj.m_number = 0;

           m_balance = obj.m_balance;
           obj.m_balance = 0.00;
       }

       return *this;
   }

   Account& Account::operator+= (double value)
   {
       if (*this && value > 0.00)
       {
           m_balance += value;
       }

       return *this;
   }

   Account& Account::operator-= (double value)
   {
       if (*this && value > 0.00 && m_balance > value)
       {
           m_balance -= value;
       }
       return *this;
   }

   Account& Account::operator<< (Account& right)
   {
       if (this != &right && *this && right)
       {
           m_balance += right.m_balance;
           right.m_balance = 0.00;
       }

       return *this;
   }

   Account& Account::operator>> (Account& right)
   {
       if (this != &right && *this && right)
       {           
           right.m_balance += m_balance;
           m_balance = 0.00;
       }

       return *this;
   }

   double operator+ (const Account& right, const Account& left)
   {
       double rtn = 0.00;

       if (right && left)
       {
           rtn = double(right) + double(left);
       }

       return  rtn;
   }

   double operator+= (double& left, const Account& right)
   {
       return (left += double (right));
   }

}