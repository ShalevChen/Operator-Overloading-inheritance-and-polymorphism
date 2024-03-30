#include "Quad.h"
 // מרובע
Quad::Quad(double up, double down, double right, double left, const char* sn): Shape(sn)  // נאתחל קודם אבא - לפני משהו שמקבל הבנאי של האבא : מאתחל לי את הסנטר וגם את השם במחלקה צורה-אבא
{
	this->m_up = up;
	this->m_down = down;
	this->m_right = right;
	this->m_left = left;
}

Quad::Quad(const Quad& other) :Shape(other)  // נאתחל את הבנאי של האבא לפי שליחת ערך שמתאים לבנאי של האבא - צורה ושם נטפל באתחול של כל הדאטא של מחלקה זו
{
	// נאתחל את הדאטא של מחלקה שלנו - מרובע
	this->m_up = other.m_up;
	this->m_down = other.m_down;
	this->m_right = other.m_right;
	this->m_left = other.m_left; 
}

Quad::~Quad()
{
	// אין צורך מכייון שבמחלקה שלנו  של מרובע אין הקצאות דינמיות
}

int Quad::calcArea() const // שטח מרובע = גובה כפול רוחב
{
	return (m_right * m_up);
}

int Quad::calcPerimeter() const  // היקף מרובע = סכום כל הצלעות
{
	return (m_down+m_left+m_right+m_up);
}
