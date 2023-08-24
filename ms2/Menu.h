/*
Full Name : Sakshi Sakshi
Student ID#  : 112602222
Email : ssakshi7@myseneca.ca
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
* **********************************************************************/
#ifndef SDDS_MENU_H
#define SDDS_MENU_H

#include <iostream>

namespace sdds {
    const unsigned int  MAX_MENU_ITEMS = 20;

    class MenuItem {
    private:
        
        char* menuContent{};

        MenuItem();
        MenuItem(const char* textContent);
        ~MenuItem();

        
        MenuItem(const MenuItem& menuItem) = delete;
        void operator=(const MenuItem& MI) = delete;

        
        void setEmpty();

        
        operator bool() const;

        
        operator const char* () const;

        
        std::ostream& display(std::ostream& os = std::cout);

        friend class Menu;
    };

    class Menu {
    private:
        MenuItem menuTitle{};
        MenuItem* menuItems[MAX_MENU_ITEMS]{};
        unsigned int pointerCount = 0;

    public:
        Menu();
        Menu(const char* title);
        ~Menu();

        
        Menu(const Menu& M) = delete;
        void operator=(const Menu& M) = delete;

        
        std::ostream& displayMenuTitle(std::ostream& os);

        
        std::ostream& displayMenu(std::ostream& os = std::cout);

        
        operator int();

        
        operator unsigned int();

        
        operator bool();

        
        int run();

        
        int operator~();

        
        Menu& operator<<(const char* menuitemContent);

        
        const char* operator[](unsigned int index) const;
    };
    
    std::ostream& operator<<(std::ostream& os, Menu& menu);
}

#endif