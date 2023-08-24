/*
Full Name : Sakshi Sakshi
Student ID#  : 112602222
Email : ssakshi7@myseneca.ca
Date : 12 - 07 - 2023
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
* **********************************************************************/
#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include <iostream>
namespace sdds
{
	const unsigned int MAX_MENU_ITEMS = 20;
	class MenuItem
	{
		friend class Menu;
		char* m_text;
	private:
		MenuItem();
		MenuItem(const char*);
		~MenuItem();
		operator bool() const;
		operator const char* () const;
		void display() const;
		MenuItem(MenuItem&&)noexcept;
		MenuItem& operator=(MenuItem&&)noexcept;
		MenuItem(const MenuItem&) = delete;
		MenuItem& operator=(const MenuItem&) = delete;
	};

	class Menu
	{
	private:
		MenuItem m_title;
		MenuItem* m_items[MAX_MENU_ITEMS]{};
		int m_count;
	public:
		Menu();
		Menu(const char*);
		~Menu();
		void displayTitle(std::ostream&) const;
		void displayMenu(std::ostream&) const;
		unsigned int run() const;
		unsigned int operator~() const;
		operator int() const;
		operator unsigned int() const;
		operator bool() const;
		Menu& operator<<(const char* menuitemConent);
		const char* operator[](int) const;
		Menu(Menu&&)noexcept;
		Menu& operator=(Menu&&)noexcept;
		Menu(const Menu&) = delete;
		Menu& operator=(const Menu&) = delete;
		friend std::ostream& operator<<(std::ostream&, const Menu&);
	};
}
#endif