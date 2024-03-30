#include "Shape.h"
//צורה 
int Shape::s_totalNumOfShapes=0 ;  // נקודת התחלה - נקרא למשתנה מהמחלקה ונאתחל באפס
Shape::Shape(const char* sn)
{
	this->m_centerPoint.setX(0) ;
	this->m_centerPoint.setY(0);
	//this->m_centerPoint.setPoint(0, 0);   אפשר גם ככה 

	this->m_shapeName = _strdup(sn);  // מקצה מקום וגם מעביר את המילה החדשה

	this->s_totalNumOfShapes++; // במידה ויהיה שימור בבנאי זה - נעלה את כמות הצורות
}

Shape::Shape(const Shape& other)
{
	this->m_shapeName = _strdup(other.m_shapeName);
	this->m_centerPoint.setPoint(other.m_centerPoint.getX(), other.m_centerPoint.getY());
	this->s_totalNumOfShapes++;
}

Shape::~Shape()
{
	if (m_shapeName)
	{
		delete m_shapeName;
	}
	s_totalNumOfShapes--;// נוריד את כמות הצורות
}

void Shape::setName(const char* name)
{
	if (m_shapeName)  // קודם למחוק כי הקצאה
	{
		delete m_shapeName;
	}
	this->m_shapeName = _strdup(name);
}

void Shape::setCenter(const Point& p)
{
	this->m_centerPoint.setPoint(p.getX(), p.getY());
}

const char* Shape::getName() const
{
	return m_shapeName;
}

Point Shape::getCenter() const
{
	return this->m_centerPoint;
}

void Shape::setShape(const char* sn, const Point& other)
{
	this->m_shapeName = _strdup(sn);
	this->m_centerPoint.setPoint(other.getX(), other.getY());
	 //this->setCenter(other);   אפשר גם ככה מכיוון שאפשר להשתמש בפונ שעשינו
}

int Shape::numOfShapes()
{
	return s_totalNumOfShapes;
}

const Shape& Shape::operator=(const Shape& other)   // נחזיר מצביע לאובייקט שלנו לי פצד שמאל
{

	if (this != & other)
	{
		setName(other.m_shapeName);  // נאתחל את הדאטא של מחלקה שלנו בעזרת פונ שכבר עשינו
		setCenter(other.m_centerPoint);  //  נאתחל את הדאטא של מחלקה שלנו בעזרת פונ שכבר עשינו 
	}
	return (* this);
}
