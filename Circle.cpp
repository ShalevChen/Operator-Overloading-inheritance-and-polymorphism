#include "Circle.h"
//עיגול
Circle::Circle(double r, const char* sn) : Shape(sn) // קודם נטפל במחלקה  של אבא - לכן נשלח לבנאי של השם  של אחד הבנאים מצורה  והוא יטפל בפונ במחלקה של צורה של הבנאי גם את השם וגם יאתחל נקודה סנטר חדשה עם ימין ושמאל 
{ // שלחנו לבנאי של האבא והא קודם יטפל בדאטא שלו ואז נכנס לבנאי של המחלקה סירקל
	this->m_radius = r;
}

Circle::Circle(const Circle& other) : Shape (other) //נשלח לבנאי של צורה כדי ששם יאתחל את הדאטא שלו
{
	this->m_radius = other.m_radius; // לאחר מכן נתאחל את הדאט של המחלקה הנוכחית עיגול
}

Circle::~Circle()
{
	// אין במחלקה הזאת הקצאות דינמיות לכן אין מה למחוק
}

double Circle::getRadius() const
{
	return m_radius;
}

void Circle::setRadius(double r)
{
	this->m_radius = r;
}

int Circle::calcArea() const // שטח מעגל = רדיוס כפול רדיוס כפול פאי
{
	return (m_radius*m_radius*PI);
}

int Circle::calcPerimeter() const  // היקף המעגל= רדיוס כפול 2 כפול פאי
{
	return (m_radius*2*PI);
}

const Circle& Circle::operator=(const Circle& other)  // נחזיר מצביע לצורה לפי צד שמאל
{
	Shape::operator=(other);  // נאתחל את צורה את כל הדאטא של המחלקה בעזרת המטודה שעושה זאת
	this->m_radius = other.m_radius;  // נאתחל את הדאטא של עיגול 
	return *this;
}

const Circle& Circle::operator=(const char* name) //  נחזיר מצביע לאובייקט שלנו  : צורה - לפי צד שמאל
{   
	Shape::setName(name);
	return *this;

}

Circle operator+(int r, const Circle& other)   // נחזיר עיגול חדש -לפי צד שמאל
{
	Circle c;
	c.m_radius = other.m_radius+r;
	c.setName(other.getName());
	c.setCenter(other.m_centerPoint);
	// Circle newC( other );    יכולתי במקום 2 שורות מעלי : לשלחו לבנאי ולפי הפונ הוא יבצע את כל האתחולים
	return c;
}
