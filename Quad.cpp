#include "Quad.h"
 // �����
Quad::Quad(double up, double down, double right, double left, const char* sn): Shape(sn)  // ����� ���� ��� - ���� ���� ����� ����� �� ���� : ����� �� �� ����� ��� �� ��� ������ ����-���
{
	this->m_up = up;
	this->m_down = down;
	this->m_right = right;
	this->m_left = left;
}

Quad::Quad(const Quad& other) :Shape(other)  // ����� �� ����� �� ���� ��� ����� ��� ������ ����� �� ���� - ���� ��� ���� ������ �� �� ����� �� ����� ��
{
	// ����� �� ����� �� ����� ���� - �����
	this->m_up = other.m_up;
	this->m_down = other.m_down;
	this->m_right = other.m_right;
	this->m_left = other.m_left; 
}

Quad::~Quad()
{
	// ��� ���� ������ ������� ����  �� ����� ��� ������ �������
}

int Quad::calcArea() const // ��� ����� = ���� ���� ����
{
	return (m_right * m_up);
}

int Quad::calcPerimeter() const  // ���� ����� = ���� �� ������
{
	return (m_down+m_left+m_right+m_up);
}
