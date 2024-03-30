#include "Point.h"

Point::Point(int x, int y)
{
	this->m_x = x;
	this->m_y = y;
}

Point::Point(const Point& other)  // נתאחל את הדאטא של המחלקה בעזרת אובייקא אטהר
{
	this->m_x = other.m_x;
	this->m_y = other.m_y;
}

Point::~Point()  //לא צריך למחוק מכיוון שלא עשינו במחלקה שום הקצאה דינמית וגם אין דאטה במחקלה עם הקצאה דינמית
{
	// m_x=NULL;
	// m_y = NULL;
	 // nullptr נשים רק בהקצאות ריקות או מערכים ריקים במידה ויש במחקלה - כאן אין
}

int Point::getX() const
{
	return m_x;
}

int Point::getY() const
{
	return m_y;
}

void Point::setX(int x)
{
	this->m_x = x;
}

void Point::setY(int y)
{
	this->m_y = y;
}

void Point::setPoint(int x, int y)
{
	this->m_x = x;
	this->m_y = y;
}

void Point::setPoint(const Point& other)
{
	this->m_x = other.m_x;
	this->m_y = other.m_y;
}

bool Point::operator==(const Point& other) const
{
	if (this->m_x==other.m_x && this->m_y==other.m_y) //   בתוך איף תמיד == פעמיים
	{
		return true;
	}
	return false;
}

bool Point::operator!=(const Point& other) const
{
	if (this->m_x!=other.m_x || this->m_y!= other.m_y)  //  זה או זה ,לא שווים
	{
		return true;
	}
	return false;
}

Point Point::operator+(int num) const   // נחזיר פוינט חדש לפי צד שמאל
{
	Point p;
	p.m_x = this->m_x + num;
	p.m_y = this->m_y + num;
	//Point p(m_x + num, m_y + num);  אפשר גם ככה
	return p;
}

const Point& Point::operator+=(int num)  // נחזיר מצביע לפי צד שמאל
{
	this->m_x = m_x + num;
	this->m_y = m_y + num;
	return *this;
}

Point::operator int() const
{
	return (m_x + m_y);
}

Point Point::operator+(const Point& other) const  // נחזיר פוינט חדש לפי צד שמאל
{
	Point p;
	p.m_x = other.m_x+this->m_x;
	p.m_y = other.m_y+this->m_y;
	return p;
}

Point Point::operator++(int)  //   נחזיר פוינט חדש
{  
	// קודם להחזיר ואז לקדם- postfix
	Point p;
	p.m_x = m_x ;
	p.m_y = m_y ;
	this->m_x++;
	this->m_y++;
	return p;
}

const Point& Point::operator++()  // נחזיר מצביע לפוינט 
{
	// קודם לקדם ונחזיר חדש - prefix
	this->m_x++;
	this->m_y++;
	return *this;
}

Point operator*(int num, const Point& other)  // נחזיר פוניט חדש
{
	Point p;
	p.m_x = other.m_x * num;
	p.m_y = other.m_y * num;
	return p;
}
