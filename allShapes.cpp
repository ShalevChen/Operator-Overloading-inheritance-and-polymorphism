#include "allShapes.h"
#include "Circle.h"	
#include "Square.h"
allShapes::allShapes()
{
	this->m_arr = nullptr;; // ����� ���� ����� ����� ���� ������
	this->m_size = 0;
}

allShapes::allShapes(const allShapes& other) 
{
	this->m_size = other.m_size; // ���� �����
	this->m_arr = new Shape * [m_size];  // �����  ���� ����� ������ �� ����� �������� ��� ����
	for (int i = 0; i < m_size; i++)
	{
		if (typeid(*other.m_arr[i]) == typeid(Circle))  // �� �� ���� �����
		{
			this->m_arr[i] = new Circle(*((Circle*)other.m_arr[i]));    // ����  ��� ����� ����, �������� �������� �� �������  �� ������ ����� ��� ���� ����� ��� ��� �� �������� ���� 
		}
		else if (typeid(*other.m_arr[i]) == typeid(Quad)) // �� �� ���� �����
		{
			this->m_arr[i] = new Quad(*((Quad*)other.m_arr[i]));// ����  ��� ����� ����, �������� �������� �� �������  �� ������ ����� ��� ���� ����� ��� ��� �� �������� ����
		}
		else if (typeid(*other.m_arr[i]) == typeid(Square)) // �� ���� ���� - �����
		{
			this->m_arr[i] = new Square(*((Square*)other.m_arr[i]));// ����  ��� ����� ����, �������� �������� �� �������  �� ������ ����� ��� ���� ����� ��� ��� �� �������� ����
		}
	}
}

allShapes::~allShapes()
{
	
	
		for (int i = 0; i < m_size; i++)
		{
			delete m_arr[i];   // ����� ���� ���� �����
		}
		delete[] m_arr;   // ���� �� �� ���� ��������

}

int allShapes::getSize() const
{
	return this->m_size;   // ���� ����� ��������
}

void allShapes::addShape(Shape* newShape)   // �� ���� ������ ����
{
	Shape** my = new Shape * [m_size + 1]; // ���� ���� ��� �� ���� ���� ���� �������
	for (int i = 0; i < m_size; i++)
	{
		my[i] = m_arr[i];     // ����� ����� ���� �� �� ����
	}
	delete[] m_arr; // ���� �� ����� ����

	m_arr = my; // ����� �� ���� ����� ���� ���� ������� ����

	if (typeid(*newShape)==typeid(Circle))  // �� ���� �����
	{
		m_arr[m_size ++] = new Circle(*((Circle*)newShape));  // ����� ���� ����� ������ ���� ����� ��� -�������� �������� �� ������� ����� ��� ��� ������� ������� �� ����� �������� ����
	}
	else if (typeid(*newShape)==typeid(Quad))  // �� �� �����
	{
		m_arr[m_size ++] = new Quad(*((Quad*)newShape)); // ����� ���� ����� ������ ���� ����� ��� �������� �������� �� ������� ����� ��� ��� ������� ������� �� ����� �������� ����
	
	}
	else if (typeid(*newShape)==typeid(Square)) // �� �� ����-�����
	{
		m_arr[m_size ++] = new Square(*((Square*)newShape));// ����� ���� ����� ������ ���� ���� -����� ��� �������� �������� �� ������� ����� ��� ��� ������� ������� �� ����� �������� ����
	
	}
	
}

void allShapes::removeShape(int index)  // �� ���� ������ ����
{
	if (index < 0 || index >= m_size)  // �� ������� ��� ����� ����� �� ������ , ��� �� ���� � ���� �� ����� ���� ��� �����
		return;
	
	Shape** my = new Shape * [m_size - 1 ];  //���� ���� ��� ��� ����� ������� ���� �����
	int x = 0;
	for (int i = 0; i < m_size; i++,x++)
	{
		if (index == i)  // �� ����� ����� ���� ����� �����
		{
			i++; //����� ����� ����� ��� ������ 
		}
      my[x] = m_arr[i];

	}
	//delete[]m_arr;  // ���� �� ����� ����
	m_arr = my;    // ����� �� ����� ���� ����� ����
    m_size--;   // ����� �� �����
}

int allShapes::totalArea() const  // int �����
{
	int total = 0;
	for (int i = 0; i < m_size; i++)
	{
		total += m_arr[i]->calcArea();   // ���� �� �� ���� ����� ����� ������ ��� ������� ���� ������
	}
	return total;
}

int allShapes::totalPerimeter() const// int �����
{
	int total = 0;
	for (int i = 0; i < m_size; i++)
	{
		total+=m_arr[i]->calcPerimeter(); // ���� �� �� ���� ����� ����� ������ ��� ������� ���� ������
	}
	return total;
}

int allShapes::totalCircleArea() const
{
	int total = 0;
	for (int i = 0; i < m_size; i++)  // ����� �� �����
	{
		if (typeid(*m_arr[i])==typeid(Circle))  // �� ����� ����� ��� �����- ���� ������
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
		if (typeid(*m_arr[i])==typeid(Square)) // �� ����� ����� ��� ����� - ���� ������
		{
			total += m_arr[i]->calcPerimeter();
		}
	}
	return total;
}

const allShapes& allShapes::operator+=(Shape* newS)  // ����� ����� �� ������ - ��� �� ����
{
	addShape(newS);  // ����� ������ ������ ����� - ����� ���� ����
	return (*this);  // ����� ����� �� ������
}

Shape* allShapes::operator[](int ind) const  //����� ���� ���� �����  
{
	return m_arr[ind]; // ����� �� ����� ����� ����� �� ����� ������� ����
}

allShapes allShapes::operator+(const allShapes& other) const  // ����� ������� �� ����� ��� - ��� �� ����
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
