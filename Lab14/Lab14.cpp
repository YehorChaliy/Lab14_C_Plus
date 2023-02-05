#include <iostream>
#include <windows.h>
#include <string>
#include <locale>

using namespace std;

class plural 
{
public:
	virtual void add_element(int&) = 0;
	virtual void delete_element(int&) = 0;
	virtual void fill(int) = 0;
	virtual void show(int) = 0;
	virtual void clean(int&) = 0;
};

class object :public plural
{
	int* obj;
public:
	object() 
	{

	}
	object(int N){
		delete[]obj;
		obj = new int[N];
		for (int i = 0; i < N; i++) 
		{
	    cout << "Вкажіть " << i + 1 << " елемент: ";
			cin >> obj[i];
		}
	}
	object(object& w)
	{

	}
	~object()
	{
		delete[]obj;
	}

	void add_element(int& N)
	{
		int* arr;
		arr = new int[N];
		for (int i = 0; i < N; i++)
		{
			arr[i] = obj[i];
		}
		delete[] obj;
		obj = new int[N + 1];
		int w;
		cout << "Вкажіть, яке число необхідно додати: ";
		cin >> w;
		for (int i = 0; i < N; i++)
		{
			obj[i] = arr[i];
		}
		obj[N] = w;
		N = N + 1;
		system("cls");
	}

	void delete_element(int& N)
	{
		int a = 0;
		int j = 0;
	note_1: cout << "Укажіть елемент, який необхідно видалити: ";
		cin >> a;
		if (a <= 0 || a > N) 
		{
			cout << "Такого елемента не існує!" << endl;
			goto note_1;
		}
		int* arr = new int[N - 1];
		for (int i = 0; i < N; i++)
		{
			if (i + 1 == a)
			i++;
			arr[j] = obj[i];
			j++;
		}
		system("cls");
		cout << a << " елемент видалено." << endl;
		cout << endl;
		N = N - 1;
		delete[]obj;
		obj = new int[N];
		for (int i = 0; i < N; i++)
		{
			obj[i] = arr[i];
		}
		delete[]arr;
	}

	void fill(int N)
	{
		delete[]obj;
		obj = new int[N];

		for (int i = 0; i < N; i++)
		{
			cout << "Введіть " << i + 1 << " елемент: ";
			cin >> obj[i];
		}
	}
	void show(int N)
	{
		for (int i = 0; i < N; i++)
		{
			if (N == 0) 
			{
				cout << "Елементи відсутні!" << endl;
				break;
			}
			cout << i + 1 << " елемент множини: " << obj[i] << endl;
		}
	}

	void clean(int& N)
	{
		delete[] obj;
		obj = new int[N];
		N = 0;
	}
};

int main() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "UKRAINIAN");
	int N;
	int x;
note: cout << "Для запуску натисніть '0': ";
	cin >> N;
	if (N = 0)
	{
		system("cls");
		cout << "Помилка! Вкажіть цифру більше 0! " << endl;
		goto note;
	}
	object list(N);
	system("cls");
menu:cout << "1.Створити множину." << endl;
	 cout << "2.Вивести всі елементи." << endl;
	 cout << "3.Додати елемент до множини." << endl;
	 cout << "4.Видалити елемент із множини." << endl;
	 cout << "5.Очистити множину." << endl;
	 cout << "6.Завершити програму.\n" << endl;
	 cout << "Оберіть бажану функцію: " << "";

	 cin >> x;
	
	switch (x) 
	{
	default:
		system("cls");
		cout << "Оберіть правильний варіант!\n";
		cout << endl;
		goto menu;
	case 1:
		system("cls");
		cout << "Введіть розмір множини: ";
		cin >> N;
		list.fill(N);
		system("cls");
		goto menu;
	case 2:
		system("cls");
		list.show(N);
		cout << endl;
		goto menu;
	case 3:
		system("cls");
		list.add_element(N);
		system("cls");
		goto menu;
	case 4:
		system("cls");
		list.delete_element(N);
		goto menu;
	case 5:
		system("cls");
		list.clean(N);
		system("cls");
		cout << "Елементи видалено!\n";
		cout << endl;
		goto menu;
	case 6:
		system("cls");
		cout << "Ви вийшли з програми" << endl;
		break;
	}
	return 0;
}