// ������ �����������
#include "list.h"
#include <iostream>
// ����������
List::~List()
{
	while (head != NULL)
	{
		DNF *temp = head;
		head = head->next;
		delete temp;

	}
}

// ��������� ������� ������� � ������ � ������ ������������� ��������� ��������
void List::insert(DNF &x, int j)
{
	bool f = 0;
	DNF *i = new DNF;
		for (i = this->head; i != NULL; i = i->next)
		{
				if (i == &x)
				{
					f = 1;
					break;
				}
		}
		
		if (f == 0)
		{
			DNF *temp = new DNF;
			temp = head;
			int i = 0;
			while (temp != NULL && i != j-1) {
				temp = temp->next;
				i++;
			}
			DNF *t = new DNF;
			DNF *a = new DNF;
			a->dnf = x.dnf;
			a->size_dnf = x.size_dnf;
			t = temp->next;
			a->next = t;
			temp->next = a;

		}
}
// �������� ���������� �������� � ������
// ���������������� ��������� ����������� ���, ��� ����������� ������, ��� � ������� insert,
//� ����� �� ����� ����� ������� � ������������� ��������� �������� �������� ������������ ��� �������
void List::add(DNF &x)
{
	DNF *temp = new DNF;
	temp->dnf = x.dnf;
	temp->size_dnf = x.size_dnf;
	temp->next = head;
	head = temp;
}
// ��������� ������ ������ �� ������� (� ������������ ����)
void List::show()
{
	DNF* t = head;
	while (t != NULL)
	{
		for (int i = 0; i <t->size_dnf; i++)
		{
			cout << ' ' << t->dnf[i].inv << ' ' << t->dnf[i].x << endl;
		}
		t = t->next;
		cout << endl;
	}
	delete t;
}
// �������� ��������, ������������ �� j-�� �������
void List::del(int j)
{

	DNF *top = head;
	DNF *temp = new DNF;
	int i = 0;
	while (i != j) 
	{
		temp = top->next; 
		top = temp;
		i++;
	}
	top->next = temp->next; 
	delete temp; 
}