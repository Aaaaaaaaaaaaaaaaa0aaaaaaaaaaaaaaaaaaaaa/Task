// ������ ������� - ��������� �������������
#include "code.h"

// ��������������� ������� ��� �������� �����������, ���������� ��� node.x
int return_var(char a) {
	if (a == 'x')
		return 1;
	if (a == 'y')
		return 2;
	if (a == 'z')
		return 3;
	if (a == 't')
		return 4;
}
// ��������������� ������� ��� �������� �����������
bool is_var(char a)
{
	return(a == 'x' || a == 'y' || a == 'z' || a == 't');
}
// �����������: ���������� ���, �������� ������ � �����
// � �������� ���������� ���������� ������, � ������� ����� ���������� ��� � ��������� ����� �����
// ������� ���������� ����� ����������� � ���� �������� ���������
void code(List*b, ifstream &in) {

	char a;
	do										// 
	{
		in.get(a);							
		DNF* temp = new DNF;				// ��������������� ���������, �������� � ��� ��������� ���������
		while (a != '+' && !in.eof())		// � ����� ������ ������ �� ����������
		{
			if (in.eof())					
				return;
			if (a == '-')					// ������������� ������������� ���������� ����������
			{
				in.get(a);
				if (is_var(a))				// ������ ���������� � ����������
				{
					temp->dnf[temp->size_dnf].inv = false;
					temp->dnf[temp->size_dnf].x = return_var(a);
					temp->size_dnf++;
					in.get(a);
				}
			}
			else
				if (is_var(a))			// ������ ���������� � ����������(�� �������������)
				{
					temp->dnf[temp->size_dnf].inv = true;
					temp->dnf[temp->size_dnf].x = return_var(a);
					temp->size_dnf++;
					in.get(a);
				}
		}

		b->add(*temp);  // � �������, ����� � ������� ����������� '+', ������������� ����������, �� � ��������� � ������
		delete temp;	// ������� ��������������� ����������
	} while (!in.eof());
}
// �������������, �������� ������� �����������, �������������� ��� � ������� � ��������� ����
// ��������� ������� - ������������ ������ � �������� ��������� �����
void decode(List*a, ofstream&out)
{
	DNF *i = new DNF;							
	for (i = a->head; i != NULL; i = i->next)
	{
		// ������� ������������� ���������� 
		for (int j = 0; j < i->size_dnf; j++) {
			if (!i->dnf[j].inv)
				out << '-';
			if (i->dnf[j].x == 1)
				out << 'x';
			if (i->dnf[j].x == 2)
				out << 'y';
			if (i->dnf[j].x == 3)
				out << 'z';
			if (i->dnf[j].x == 4)
				out << 't';
		}
		out << ' ';
		if (i->next != NULL)
			out << '+';
		out << ' ';

	}
	delete i;
	a->~List(); // ������������ ������
}