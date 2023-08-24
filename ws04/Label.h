/*
Full Name : Sakshi Sakshi
Student ID# : 112602222
Email : ssakshi7@myseneca.ca
Date : 11 - 06 - 2023
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef SDDS_Label_H
#define SDDS_Label_H


namespace sdds
{
	class Label
	{
		char frameString[9];
		char* textString;
	public:
		Label();
		Label(const char* frameArg);
		Label(const char* frameArg, const char* content);
		~Label();
		void readLabel();
		std::ostream& printLabel()const;
	};
}


#endif