#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "LblShape.h"

namespace sdds
{
    class Rectangle : public LblShape {
    private:
        int m_width;
        int m_height;

    public:
        Rectangle();
        Rectangle(const char* label, int width, int height);

        virtual void draw(std::ostream& os) const;
        virtual void getSpecs(std::istream& is);
    };
}

#endif // RECTANGLE_H
