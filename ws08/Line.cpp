#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Line.h"
#include <limits>

using namespace std;
namespace sdds
{
    Line::Line() : LblShape(), m_length(0) {}
    Line::Line(const char* label, int length) : LblShape(label), m_length(length) {}

    void Line::draw(std::ostream& os) const
    {
        if (m_length > 0 && label() != nullptr)
        {
            os << label() << std::endl;
            for (int i = 0; i < m_length; ++i)
            {
                os << "=";
            }
            //os << std::endl;
        }
    }

    void Line::getSpecs(std::istream& is)
    {
        LblShape::getSpecs(is);
        is >> m_length;
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}
