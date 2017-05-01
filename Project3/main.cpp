// Головная программа 
#include "task.h"
using namespace std;

int main()
{
	ifstream in1("in1.txt");
	ifstream in2("in2.txt");
	ofstream out("out.txt");

	cout << "Put number of task" << endl; // запрашиваем у пользователя номер задачи
	int n;
	cin >> n;
	if (n == 1) //если необходимо решить первую задачу
	{
		List a, b;
		code(&a, in1);
		code(&b, in2);
		connecnt(&a, &b);
		decode(&a, out);
		b.~List(); // освобождаем память, память для списка a освободилась в функции decode
	}
	else
		if (n == 2) // вторую задачу
		{
			cout << "Put values of x, y, z and t" << endl; // запрашиваем у пользователя значения переменных
			bool x, y, z, t;
			cin >> x >> y >> z >> t;
			List a;
			code(&a, in1);
			bool ans = task2(&a, x, y, z, t);
			cout << "DNF = " << ans << endl;
			a.~List();
		}
		else
			if (n == 3)// третья задача
			{
				List a, ans;
				code(&a, in1);
				task3(&a, &ans);
				decode(&ans, out);
				a.~List();
			}

			else
				if (n == 4) //четвертая задача
				{
					List a, ans;
					code(&a, in1);
					task4(&a, &ans);
					decode(&ans, out);
					a.~List();
				}
				else
					cout << "Task is not found" << endl; // если пользователь запросил решение задачи с другим номер, сообщаем ему об ошибке
	 // закрываем все потоки
	in1.close();
	in2.close();
	out.close();
}