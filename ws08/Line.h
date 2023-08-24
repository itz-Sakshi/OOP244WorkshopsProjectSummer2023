#ifndef LINE_H
#define LINE_H

#include "LblShape.h"

namespace sdds
{
    class Line : public LblShape {
    private:
        int m_length;

    public:
        Line();
        Line(const char* label, int length);

        virtual void draw(std::ostream& os) const;
        virtual void getSpecs(std::istream& is);
    };
}

#endif // LINE_H
