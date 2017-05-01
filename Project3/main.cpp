// �������� ��������� 
#include "task.h"
using namespace std;

int main()
{
	ifstream in1("in1.txt");
	ifstream in2("in2.txt");
	ofstream out("out.txt");

	cout << "Put number of task" << endl; // ����������� � ������������ ����� ������
	int n;
	cin >> n;
	if (n == 1) //���� ���������� ������ ������ ������
	{
		List a, b;
		code(&a, in1);
		code(&b, in2);
		connecnt(&a, &b);
		decode(&a, out);
		b.~List(); // ����������� ������, ������ ��� ������ a ������������ � ������� decode
	}
	else
		if (n == 2) // ������ ������
		{
			cout << "Put values of x, y, z and t" << endl; // ����������� � ������������ �������� ����������
			bool x, y, z, t;
			cin >> x >> y >> z >> t;
			List a;
			code(&a, in1);
			bool ans = task2(&a, x, y, z, t);
			cout << "DNF = " << ans << endl;
			a.~List();
		}
		else
			if (n == 3)// ������ ������
			{
				List a, ans;
				code(&a, in1);
				task3(&a, &ans);
				decode(&ans, out);
				a.~List();
			}

			else
				if (n == 4) //��������� ������
				{
					List a, ans;
					code(&a, in1);
					task4(&a, &ans);
					decode(&ans, out);
					a.~List();
				}
				else
					cout << "Task is not found" << endl; // ���� ������������ �������� ������� ������ � ������ �����, �������� ��� �� ������
	 // ��������� ��� ������
	in1.close();
	in2.close();
	out.close();
}