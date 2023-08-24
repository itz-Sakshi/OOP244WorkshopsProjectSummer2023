/*
Full Name : Sakshi Sakshi
Student ID# : 112602222
Email : ssakshi7@myseneca.ca
Date : 03 - 06 - 2023
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef SDDS_FOOD_H_
#define SDDS_FOOD_H_
namespace sdds {
    class Food {
        char m_foodName[31];
        int m_cal;
        int m_time_of_consumption;
        void setName(const char* name);
    public:
        void setEmpty();
        void set(const char* name, int cal, int mealTime);
        void display()const;
        bool isValid()const;
        int calorie()const;
        int consumptionTime()const;
    };
}

#endif // !SDDS_FOOD_H
