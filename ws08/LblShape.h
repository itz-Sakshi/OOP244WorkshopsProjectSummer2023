#ifndef SDDS_LBLSHAPE_H__
#define SDDS_LBLSHAPE_H__
 
#include "Shape.h"

namespace sdds
{
	class LblShape : public Shape
	{
		char* m_label = nullptr;
	protected:
		const char* label() const;
	public:
		virtual void draw(std::ostream& os) const = 0;
		virtual void getSpecs(std::istream& in);
		LblShape();
		LblShape(const char * labelStr);
		virtual ~LblShape();
		LblShape(const LblShape&) = delete;
		LblShape& operator=(const LblShape&) = delete;
	};

	
}
#endif // SDDS_LBLSHAPE_H__