/*
Full Name : Sakshi Sakshi
Student ID#  : 112602222
Email : ssakshi7@myseneca.ca
Date : 12 - 07 - 2023
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
* **********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include "Utils.h"
#include "Menu.h"
#include <cstring>

namespace sdds
{
	MenuItem::MenuItem() {
		m_text = nullptr;
	}

	MenuItem::MenuItem(const char* item) {
		if (item != nullptr) {
			m_text = new char[strlen(item) + 1];
			strcpy(m_text, item);
		}
		else
			m_text = nullptr;
	}

	MenuItem::~MenuItem() {
		if (m_text != nullptr) {
			delete[] m_text;
			m_text = nullptr;
		}
	}

	MenuItem::operator bool() const {
		return m_text != nullptr;
	}

	MenuItem::operator const char* () const {
		return m_text;
	}

	void MenuItem::display() const {
		if (m_text != nullptr) {
			std::cout << m_text;
		}
	}

	MenuItem::MenuItem(MenuItem&& item)noexcept
	{
		if (item != nullptr)
		{
			delete[] m_text;
			m_text = new char[strLen(item.m_text) + 1];
			strCpy(m_text, item.m_text);
			delete[] item.m_text;
			item.m_text = nullptr;
		}
	}

	MenuItem& MenuItem::operator=(MenuItem&& item)noexcept
	{
		if (item != nullptr)
		{
			delete[] m_text;
			m_text = new char[strLen(item.m_text) + 1];
			strCpy(m_text, item.m_text);
			delete[] item.m_text;
			item.m_text = nullptr;
		}
		return *this;
	}

	Menu::Menu() {
		m_title = std::move(MenuItem());
		m_count = 0;
	}

	Menu::Menu(const char* title) {
		if (title != nullptr)
			m_title = std::move(MenuItem(title));
		m_count = 0;
	}

	Menu::~Menu() {
		for (int i = 0; i < m_count; i++)
			if (m_items[i] != NULL)
				delete m_items[i];
	}

	void Menu::displayTitle(std::ostream& os) const {
		if (m_title != nullptr && m_title.m_text != nullptr)
			os << m_title.m_text;
	}

	void Menu::displayMenu(std::ostream& os) const {
		displayTitle(os);
		if (m_title != nullptr && m_title.m_text != nullptr)
			os << std::endl;
		for (int i = 0; i < m_count; i++)
			os << std::right << std::setfill(' ') << std::setw(2) << (int)(i + 1) << "- " << (*m_items[i]).m_text << std::endl;
		os << std::right << std::setw(2) << " 0- Exit" << std::endl << "> ";
	}

	unsigned int Menu::run() const {
		displayMenu(std::cout);
		int userInput;
		while (true) {
			std::cin >> userInput;
			if (std::cin.good() && userInput >= 0 && userInput <= m_count)
			{
				return userInput;
			}
			std::cin.clear();
			std::cin.ignore(INT32_MAX, '\n');
			std::cout << "Invalid Selection, try again: ";
		};
	}

	unsigned int Menu::operator~() const {
		return run();
	}

	Menu& Menu::operator<<(const char* menuitemConent) {
		if (m_count == MAX_MENU_ITEMS)
			return *this;
		m_items[m_count++] = new MenuItem(menuitemConent);
		return *this;
	}

	Menu::operator int() const {
		return m_count;
	}

	Menu::operator unsigned int() const {
		return m_count;
	}

	Menu::operator bool() const {
		return m_count > 0;
	}

	std::ostream& operator<<(std::ostream& os, const Menu& m) {
		m.displayTitle(os);
		return os;
	}

	const char* Menu::operator[](int i) const {
		return m_items[i]->m_text;
	}

	Menu::Menu(Menu&& m)noexcept
	{
		m_count = std::move(m.m_count);
		m_title = std::move(m.m_title);
		for (int i = 0; i < m_count; i++)
			m_items[i] = std::move(m.m_title[m_items]);
		for (int i = 0; i < m_count; i++)
			if (m.m_items[i] != NULL)
				delete m.m_items[i];
	}

	Menu& Menu::operator=(Menu&& m)noexcept
	{
		m_count = std::move(m.m_count);
		m_title = std::move(m.m_title);
		for (int i = 0; i < m_count; i++)
			m_items[i] = std::move(m.m_title[m_items]);
		for (int i = 0; i < m_count; i++)
			if (m.m_items[i] != NULL)
				delete m.m_items[i];
		return *this;
	}
}