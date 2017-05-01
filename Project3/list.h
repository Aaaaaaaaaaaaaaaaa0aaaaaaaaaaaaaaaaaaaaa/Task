// ������ �����������
#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
using namespace std;

//��������� ����������, �������� � ���; inv - ���� (+ ��� -)�, x  ��������� �������� �� 1 �� 4
// � ������������ ����� �� ���������� � ������� ���
//1 - x
//2 - y
//3 - z
//4 - t ������������� 
struct node {
	int x;     
	bool inv;
};

// ���������, �������������� ����� ���������� ���, ������� ������; 
//��� �������� ����������� � ��������� �������� ������  ���������
//(�.�. ���� � ���������, ��������, ��� ����������, �� �� ������ - 2, ���� ������ ����������, �� ������ - 4)
struct DNF {
	int size_dnf = 0;
	node dnf[4];
	DNF* next;
};

// ��� � ���� ������, ���������� �������� ����������
class List
{
public:
	DNF *head;
	List() :head(NULL) {}; 
	~List();			
	void del(int j);
	void insert(DNF &a, int j);
	void add(DNF &x);
	void show();
	
};
