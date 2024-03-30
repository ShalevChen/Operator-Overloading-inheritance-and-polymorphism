#include "Shape.h"
//���� 
int Shape::s_totalNumOfShapes=0 ;  // ����� ����� - ���� ������ ������� ������ ����
Shape::Shape(const char* sn)
{
	this->m_centerPoint.setX(0) ;
	this->m_centerPoint.setY(0);
	//this->m_centerPoint.setPoint(0, 0);   ���� �� ��� 

	this->m_shapeName = _strdup(sn);  // ���� ���� ��� ����� �� ����� �����

	this->s_totalNumOfShapes++; // ����� ����� ����� ����� �� - ���� �� ���� ������
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
	s_totalNumOfShapes--;// ����� �� ���� ������
}

void Shape::setName(const char* name)
{
	if (m_shapeName)  // ���� ����� �� �����
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
	 //this->setCenter(other);   ���� �� ��� ������ ����� ������ ���� ������
}

int Shape::numOfShapes()
{
	return s_totalNumOfShapes;
}

const Shape& Shape::operator=(const Shape& other)   // ����� ����� �������� ���� �� ��� ����
{

	if (this != & other)
	{
		setName(other.m_shapeName);  // ����� �� ����� �� ����� ���� ����� ��� ���� �����
		setCenter(other.m_centerPoint);  //  ����� �� ����� �� ����� ���� ����� ��� ���� ����� 
	}
	return (* this);
}
