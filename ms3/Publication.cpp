/*
Full Name : Sakshi Sakshi
Student ID# : 112602222
Email : ssakshi7@myseneca.ca
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************/
#include "Publication.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS

namespace sdds {
    Publication::Publication() {
        setDefault();
    }

    Publication::Publication(const Publication& publication) {
        *this = publication;
    }

    Publication& Publication::operator=(const Publication& publication) {
        set(publication.m_membership);
        setRef(publication.m_libRef);
        strcpy(m_shelfId, publication.m_shelfId);
        m_date = publication.m_date;

        if (m_title)
        {
            delete[] m_title;
            m_title = nullptr;
        }

        if (publication.m_title != nullptr) {
            m_title = new char[strlen(publication.m_title) + 1];
            strcpy(m_title, publication.m_title);
        }
        else {
            m_title = nullptr;
        }

        return *this;
    }

    Publication::~Publication() {
        delete[] m_title;
    }

    void Publication::setDefault() {
        m_title = nullptr;
        m_shelfId[0] = '\0';
        m_membership = 0;
        m_libRef = -1;
        resetDate();
    }

    void Publication::set(int member_id) {
        m_membership = member_id;
    }

    void Publication::setRef(int value) {
        m_libRef = value;
    }

    void Publication::resetDate() {
        m_date = Date();
    }

    char Publication::type() const {
        return 'P';
    }

    bool Publication::onLoan() const {
        return (m_membership != 0);
    }

    Date Publication::checkoutDate() const {
        return m_date;
    }

    bool Publication::operator==(const char* title) const {
        return strstr(m_title, title) != nullptr;
    }

    Publication::operator const char* () const {
        return m_title;
    }

    int Publication::getRef() const {
        return m_libRef;
    }

    bool Publication::conIO(std::ios& io) const {
        return &io == &std::cin || &io == &std::cout;
    }

    std::ostream& Publication::write(std::ostream& os) const {
        if (conIO(os)) {
            os << "| " << m_shelfId << " | " << std::setw(30) << std::left << std::setfill('.') << m_title << " | ";
            (m_membership != 0) ? os << m_membership : os << " N/A ";
            os << " | " << m_date << " |";
        }
        else {
            os << type() << "\t";
            os << "\t" << m_libRef << "\t" << m_shelfId << "\t" << m_title << "\t";
            (m_membership != 0) ? os << m_membership : os << " N/A ";
            os << "\t" << m_date;
        }

        return os;
    }

    std::istream& Publication::read(std::istream& is) {
        char t_title[SDDS_TITLE_WIDTH + 1]{}, t_shelfId[SDDS_SHELF_ID_LEN + 1]{};
        int t_libRef = -1, t_membership = 0;
        Date t_date;

        if (m_title) {
            delete[] m_title;
            m_title = nullptr;
        }
        setDefault();

        if (conIO(is)) {
            std::cout << "Shelf No: ";
            is.getline(t_shelfId, SDDS_SHELF_ID_LEN + 1);

            if (strlen(t_shelfId) != SDDS_SHELF_ID_LEN) {
                is.setstate(std::ios::failbit);
            }

            std::cout << "Title: ";
            is.getline(t_title, SDDS_TITLE_WIDTH + 1);

            std::cout << "Date: ";
            is >> t_date;
        }

        else {
            is >> t_libRef;
            is.ignore();
            is.getline(t_shelfId, SDDS_SHELF_ID_LEN + 1, '\t');
            is.getline(t_title, SDDS_TITLE_WIDTH + 1, '\t');
            is >> t_membership;
            is.ignore();
            is >> t_date;
        }

        if (!t_date) {
            is.setstate(std::ios::failbit);
        }

        if (is) {
            m_title = new char[strlen(t_title) + 1];
            strcpy(m_title, t_title);
            strcpy(m_shelfId, t_shelfId);
            m_membership = t_membership;
            m_date = t_date;
            m_libRef = t_libRef;
        }

        return is;
    }

    Publication::operator bool() const {
        bool result = false;
        if (m_title != nullptr && m_shelfId[0] != '\0') {
            result = true;
        }

        return result;
    }
}