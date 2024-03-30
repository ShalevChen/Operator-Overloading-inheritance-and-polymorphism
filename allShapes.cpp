#include "allShapes.h"
#include "Circle.h"	
#include "Square.h"
allShapes::allShapes()
{
	this->m_arr = nullptr;; // נאתחל מערך הקצאה דינמי בנאל פיטיאר
	this->m_size = 0;
}

allShapes::allShapes(const allShapes& other) 
{
	this->m_size = other.m_size; // גודל המערך
	this->m_arr = new Shape * [m_size];  // אתחול  כמות המערך במחלקה של רשימת המצביעים לפי נתון
	for (int i = 0; i < m_size; i++)
	{
		if (typeid(*other.m_arr[i]) == typeid(Circle))  // אם זה מסוג עיגול
		{
			this->m_arr[i] = new Circle(*((Circle*)other.m_arr[i]));    // נפתח  חדש במערך שלנו, בסוגריים הפנימיים זה קאסטינג  של המחלקה ונשים בצד שמאל מצביע לפי סוג של האובייקט עצמו 
		}
		else if (typeid(*other.m_arr[i]) == typeid(Quad)) // אם זה מסוג מרובע
		{
			this->m_arr[i] = new Quad(*((Quad*)other.m_arr[i]));// נפתח  חדש במערך שלנו, בסוגריים הפנימיים זה קאסטינג  של המחלקה ונשים בצד שמאל מצביע לפי סוג של האובייקט עצמו
		}
		else if (typeid(*other.m_arr[i]) == typeid(Square)) // אם מסוג כיכר - מרובע
		{
			this->m_arr[i] = new Square(*((Square*)other.m_arr[i]));// נפתח  חדש במערך שלנו, בסוגריים הפנימיים זה קאסטינג  של המחלקה ונשים בצד שמאל מצביע לפי סוג של האובייקט עצמו
		}
	}
}

allShapes::~allShapes()
{
	
	
		for (int i = 0; i < m_size; i++)
		{
			delete m_arr[i];   // נמחוק איבר איבר במערך
		}
		delete[] m_arr;   // נמחק את כל מערך המצביעים

}

int allShapes::getSize() const
{
	return this->m_size;   // גודל המערך המצביעים
}

void allShapes::addShape(Shape* newShape)   // לא צריך להחזיר כלום
{
	Shape** my = new Shape * [m_size + 1]; // נקצה מערך חדש עם מקום נוסף לחדש שיתווסף
	for (int i = 0; i < m_size; i++)
	{
		my[i] = m_arr[i];     // נעתיק למערך החדש את כל הישן
	}
	delete[] m_arr; // נמחק את המערך הישן

	m_arr = my; // נעתיק את החדש בחזרה לישן לאחר שאיפסנו אותו

	if (typeid(*newShape)==typeid(Circle))  // אם מסוג עיגול
	{
		m_arr[m_size ++] = new Circle(*((Circle*)newShape));  // במערך שלנו במקום האחרון נקצה עיגול חדש -בסוגריים הפנימיים זה קאסטינג לאיזה סוג ואז הכוכבית השמאלית זה מצביע לאובייקט עצמו
	}
	else if (typeid(*newShape)==typeid(Quad))  // אם זה מרובע
	{
		m_arr[m_size ++] = new Quad(*((Quad*)newShape)); // במערך שלנו במקום האחרון נקצה מרובע חדש בסוגריים הפנימיים זה קאסטינג לאיזה סוג ואז הכוכבית השמאלית זה מצביע לאובייקט עצמו
	
	}
	else if (typeid(*newShape)==typeid(Square)) // אם זה כיכר-מרובע
	{
		m_arr[m_size ++] = new Square(*((Square*)newShape));// במערך שלנו במקום האחרון נקצה כיבר -מרובע חדש בסוגריים הפנימיים זה קאסטינג לאיזה סוג ואז הכוכבית השמאלית זה מצביע לאובייקט עצמו
	
	}
	
}

void allShapes::removeShape(int index)  // לא צריך להחזיר כלום
{
	if (index < 0 || index >= m_size)  // אם האינדקס קטן מגודל המערך לא הגיוני , וגם אם גדול מ גודל של המערך פשוט נצא מהפונ
		return;
	
	Shape** my = new Shape * [m_size - 1 ];  //נקצה מערך חדש לפי הכמות העדכנית לאחר הפחתה
	int x = 0;
	for (int i = 0; i < m_size; i++,x++)
	{
		if (index == i)  // אם הגענו לאיבר שאנו רוצים למחוק
		{
			i++; //נעבור לאיבר במקום הבא ונעתיק 
		}
      my[x] = m_arr[i];

	}
	//delete[]m_arr;  // נמחק את המערך הישן
	m_arr = my;    // נעביר את המערך החדש למערך הישן
    m_size--;   // נוריד את הכמות
}

int allShapes::totalArea() const  // int נחזיר
{
	int total = 0;
	for (int i = 0; i < m_size; i++)
	{
		total += m_arr[i]->calcArea();   // נחשב על כל צורה במערך נעבור למחלקה שלה ובמטודה נחשב ונסכום
	}
	return total;
}

int allShapes::totalPerimeter() const// int נחזיר
{
	int total = 0;
	for (int i = 0; i < m_size; i++)
	{
		total+=m_arr[i]->calcPerimeter(); // נחשב על כל צורה במערך נעבור למחלקה שלה ובמטודה נחשב ונסכום
	}
	return total;
}

int allShapes::totalCircleArea() const
{
	int total = 0;
	for (int i = 0; i < m_size; i++)  // נעבור על המערך
	{
		if (typeid(*m_arr[i])==typeid(Circle))  // אם האיבר במערך הוא עיגול- נכנס ונסכום
		{
			total += m_arr[i]->calcArea(); 
		}
	}
	return total;
}

int allShapes::totalSquarePerimeter() const
{
	int total = 0;
	for (int i = 0; i < m_size; i++)
	{
		if (typeid(*m_arr[i])==typeid(Square)) // אם האיבר במערך הוא ריבוע - נכנס ונסכום
		{
			total += m_arr[i]->calcPerimeter();
		}
	}
	return total;
}

const allShapes& allShapes::operator+=(Shape* newS)  // נחזיר מצביע של המחלקה - לפי צד שמאל
{
	addShape(newS);  // בעזרת המטודה שעשינו מקודם - נוסיף צורה חדשה
	return (*this);  // נחזיר מצביע של המחלקה
}

Shape* allShapes::operator[](int ind) const  //נחזיר מערך במקו האינד  
{
	return m_arr[ind]; // נחזיר את הצורה במערך במקום של האינט שקיבלנו בפונ
}

allShapes allShapes::operator+(const allShapes& other) const  // נחזיר אובייקט של צורות חדש - לפי צד שמאל
{
	allShapes my;
	for (int i = 0; i < this->getSize(); i++)
	{
		my.addShape((*this)[i]);
	}

	for (int i = 0; i < other.m_size; i++)
	{
		my.addShape(other[i]);
	}
	return my;
}

allShapes::operator int() const
{
	return m_size;
}
