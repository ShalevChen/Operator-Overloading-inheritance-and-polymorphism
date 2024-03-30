#include "Circle.h"
//�����
Circle::Circle(double r, const char* sn) : Shape(sn) // ���� ���� ������  �� ��� - ��� ���� ����� �� ���  �� ��� ������ �����  ���� ���� ���� ������ �� ���� �� ����� �� �� ��� ��� ����� ����� ���� ���� �� ���� ����� 
{ // ����� ����� �� ���� ��� ���� ���� ����� ��� ��� ���� ����� �� ������ �����
	this->m_radius = r;
}

Circle::Circle(const Circle& other) : Shape (other) //���� ����� �� ���� ��� ��� ����� �� ����� ���
{
	this->m_radius = other.m_radius; // ���� ��� ����� �� ���� �� ������ ������� �����
}

Circle::~Circle()
{
	// ��� ������ ���� ������ ������� ��� ��� �� �����
}

double Circle::getRadius() const
{
	return m_radius;
}

void Circle::setRadius(double r)
{
	this->m_radius = r;
}

int Circle::calcArea() const // ��� ���� = ����� ���� ����� ���� ���
{
	return (m_radius*m_radius*PI);
}

int Circle::calcPerimeter() const  // ���� �����= ����� ���� 2 ���� ���
{
	return (m_radius*2*PI);
}

const Circle& Circle::operator=(const Circle& other)  // ����� ����� ����� ��� �� ����
{
	Shape::operator=(other);  // ����� �� ���� �� �� ����� �� ������ ����� ������ ����� ���
	this->m_radius = other.m_radius;  // ����� �� ����� �� ����� 
	return *this;
}

const Circle& Circle::operator=(const char* name) //  ����� ����� �������� ����  : ���� - ��� �� ����
{   
	Shape::setName(name);
	return *this;

}

Circle operator+(int r, const Circle& other)   // ����� ����� ��� -��� �� ����
{
	Circle c;
	c.m_radius = other.m_radius+r;
	c.setName(other.getName());
	c.setCenter(other.m_centerPoint);
	// Circle newC( other );    ������ ����� 2 ����� ���� : ����� ����� ���� ���� ��� ���� �� �� ��������
	return c;
}
