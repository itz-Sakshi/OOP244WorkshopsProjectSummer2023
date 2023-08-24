/*
Full Name : Sakshi Sakshi
Student ID#  : 112602222
Email : ssakshi7@myseneca.ca
Date : 7 - 07 - 2023
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
* **********************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
#include "cstring.h"
using namespace std;
namespace sdds {
    Line::operator const char* () const {
        return (const char*)m_value;
    }
    Line& Line::operator=(const char* lineValue) {
        delete[] m_value;
        m_value = new char[strLen(lineValue) + 1];
        strCpy(m_value, lineValue);
        return *this;
    }
    Line::~Line() {
        if (m_value != nullptr)
        {
            delete[] m_value;
            m_value = nullptr;
        }
    }
    Line::Line() {
        m_value = nullptr;
    }
    void TextFile::setEmpty()
    {
        if (m_filename != nullptr)
        {
            delete[] m_textLines;
            m_textLines = nullptr;
            delete[] m_filename;
            m_filename = nullptr;
            m_noOfLines = 0;
        }
    }
    void TextFile::setFilename(const char* fname, bool isCopy)
    {
        if (m_filename != nullptr) {
            delete[] m_filename;
            m_filename = nullptr;
        }
        if (!isCopy)
        {
            m_filename = new char[strLen(fname) + 1];
            strCpy(m_filename, fname);
        }
        else
        {
            m_filename = new char[strLen(fname) + 3];
            strCpy(m_filename, "C_");
            strCat(m_filename, fname);
        }
    }
    void TextFile::setNoOfLines()
    {
        std::ifstream file(m_filename);
        if (file.is_open())
        {
            m_noOfLines = 0;
            char ch = '\0';
            while (file.get(ch))
            {
                if (ch == '\n') {
                    m_noOfLines++;
                }
            }
            // Increment m_noOfLines by 1 in case the last line doesn't have a newline
            m_noOfLines++;

            file.close();

            if (m_noOfLines == 0) {
                // No lines found, delete the filename and set it to nullptr
                delete[] m_filename;
                m_filename = nullptr;
            }
        }
    }
    void TextFile::loadText()
    {
        if (m_filename != nullptr)
        {
            // Delete previously allocated memory to prevent memory leaks
            delete[] m_textLines;
            m_textLines = nullptr;

            std::ifstream file(m_filename);
            if (file.is_open())
            {
                // Allocate memory for m_textLines
                m_textLines = new Line[m_noOfLines];
                std::string line;
                unsigned lineIndex = 0;
                while (getline(file, line))
                {
                    m_textLines[lineIndex] = line.c_str();
                    lineIndex++;
                }

                file.close();

                // Update the actual number of lines read
                m_noOfLines = lineIndex;
            }
        }
    }
    void TextFile::saveAs(const char* fileName)const
    {
        std::ofstream fout(fileName);
        if (fout)
        {
            for (unsigned i = 0; i < m_noOfLines; i++) {
                fout << m_textLines[i].m_value << '\n';
            }

            fout.close();
        }
    }
    TextFile::TextFile(unsigned pageSize)
    {
        m_textLines = nullptr;
        m_filename = nullptr;
        m_noOfLines = 0;
        m_pageSize = pageSize;
    }
    TextFile::TextFile(const char* filename, unsigned pageSize)
    {
        std::ifstream file(filename);
        m_textLines = nullptr;
        m_filename = nullptr;
        m_noOfLines = 0;
        m_pageSize = pageSize;
        if (filename != nullptr && file.is_open())
        {
            setFilename(filename);
            setNoOfLines();
            loadText();

        }
    }
    TextFile::TextFile(const TextFile& txtFile)
    {
        m_pageSize = txtFile.m_pageSize;
        m_textLines = nullptr;
        m_filename = nullptr;
        m_noOfLines = 0;
        if (txtFile.m_filename != nullptr)
        {
            m_noOfLines = txtFile.m_noOfLines;
            setFilename(txtFile.m_filename, true);
            std::ofstream fout(m_filename);
            if (fout)
            {
                for (unsigned i = 0; i < txtFile.m_noOfLines; i++) {
                    fout << txtFile.m_textLines[i].m_value << '\n';
                }

                fout.close();
            }
            setNoOfLines();
            loadText();
        }
    }

    TextFile& TextFile::operator=(const TextFile& otherFile)
    {
        if (this != &otherFile && this)
        {
            delete[] m_textLines;
            m_textLines = nullptr;
            if (otherFile.m_textLines && otherFile.m_noOfLines > 0) {
                m_noOfLines = otherFile.m_noOfLines;
                m_textLines = new Line[m_noOfLines];
                for (unsigned i = 0; i < m_noOfLines; i++)
                {

                    m_textLines[i].m_value = new char[strLen(otherFile.m_textLines[i].m_value) + 1];
                    strCpy(m_textLines[i].m_value, otherFile.m_textLines[i].m_value);

                }
                saveAs(m_filename);
            }
            
        }
        return *this;
    }

    TextFile::~TextFile() {
        if (m_filename != nullptr)
        {
            setEmpty();
        }
    }
    unsigned TextFile::lines()const
    {
        return m_noOfLines;
    }
    std::ostream& TextFile::view(std::ostream& ostr)const
    {
        if (m_filename != nullptr)
        {
            ostr << m_filename << std::endl;
            for (int i = 0; i < strLen(m_filename); i++) {
                cout << "=";
            }
            cout << endl;
            for (unsigned i = 0; i < m_noOfLines; i++) {
                ostr << m_textLines[i].m_value << std::endl;
                if ((i + 1) % m_pageSize == 0) {
                    std::cout << "Hit ENTER to continue...";
                    ostr.flush();
                    std::cin.get();
                }
            }
        }
        return ostr;
    }
    std::istream& TextFile::getFile(std::istream& istr)
    {
        char buffer[100] = { '\0' };
        istr.getline(buffer, sizeof(buffer));
        setFilename(buffer);
        setNoOfLines();
        loadText();
        return istr;
    }
    const char* TextFile::operator[](unsigned index)const
    {
        if (m_noOfLines != 0)
        {
            if (index >= m_noOfLines) {
                index %= m_noOfLines;
            }
            return m_textLines[index].m_value;
        }
        return nullptr;
    }
    TextFile::operator bool() const {
        return m_filename != nullptr;
    }
    const char* TextFile::name() const {
        return m_filename;
    }

    std::ostream& operator<<(std::ostream& ostr, const TextFile& text)
    {
        return text.view(ostr);
    }
    std::istream& operator>>(std::istream& istr, TextFile& text)
    {
        return text.getFile(istr);
    }

}