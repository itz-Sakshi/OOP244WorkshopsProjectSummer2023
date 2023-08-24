// Final Project Milestone 1
// Date Module
// File  Date.h
// Version 1.0
// Author   Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////

#ifndef SDDS_DATE_H__
#define SDDS_DATE_H__
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
namespace sdds
{
    const int NO_ERROR = 0;
    const int CIN_FAILED = 1;
    const int YEAR_ERROR = 2;
    const int MON_ERROR = 3;
    const int DAY_ERROR = 4;
    const char DATE_ERROR[5][16] = {
        "No Error",
        "cin Failed",
        "Bad Year Value",
        "Bad Month Value",
        "Bad Day Value" };
    const int MIN_YEAR = 1500;
    class Date
    {
    private:
        int m_year;
        int m_mon;
        int m_day;
        int m_ErrorCode;
        int m_CUR_YEAR;
        int daysSince0001_1_1() const;
        bool validate();
        void errCode(int);
        int systemYear() const;
        bool bad() const;
        int mdays() const;
        void setToToday();
    public:
        Date();
        Date(int year, int mon, int day);
        int errCode() const;
        const char* dateStatus() const;
        int currentYear() const;

        int getdaysSince0001_1_1() const;

        operator bool() const;

        std::istream& read(std::istream& is = std::cin);

        std::ostream& write(std::ostream& os = std::cout) const;
    };

    std::ostream& operator<<(std::ostream& os, const Date& RO);
    std::istream& operator>>(std::istream& is, Date& RO);

    int numberOfDaysInMonth(int monthByNumber, int year);

    bool operator==(const Date& date1, const Date& date2);
    bool operator!=(const Date& date1, const Date& date2);
    bool operator>=(const Date& date1, const Date& date2);
    bool operator<=(const Date& date1, const Date& date2);
    bool operator<(const Date& date1, const Date& date2);
    bool operator>(const Date& date1, const Date& date2);

    int operator-(const Date& date1, const Date& date2);

    extern bool sdds_test;
    extern int sdds_year;
    extern int sdds_mon;
    extern int sdds_day;
}
#endif