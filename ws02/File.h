/*
Workshop 2 - Part 2
Full Name : Sakshi Sakshi
Student ID# : 112602222
Email : ssakshi7@myseneca.ca
Date : 25 - 05 - 2023
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
   bool read(char pCode[]);
   bool read(int & population);

}
#endif // !SDDS_FILE_H_
