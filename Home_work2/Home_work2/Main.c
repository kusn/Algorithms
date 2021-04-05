//Кудряшов Сергей
//
//1. Реализовать функцию перевода из десятичной системы в двоичную, используя рекурсию.
//2. Реализовать функцию возведения числа a в степень b :
//a.без рекурсии;
//b.рекурсивно;
//c.* рекурсивно, используя свойство четности степени.

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int result = 0;
char buffer[12];

void solution1();
void solution2();
void solution3();
void solution4();
void menu();
void DecToBin(int n);
void StrRev(char* S);
int MyPow(int a, int b);
int MyBinPow(int a, int b);


int main(int argc, char* argv[])
{
	int sel = 0;
	
	setlocale(LC_ALL, "rus");

	do
	{
		menu();
		scanf("%i", &sel);
		switch (sel)
		{
		case 1:
			solution1();
			break;
		case 2:
			solution2();
			break;
		case 3:
			solution3();
			break;
		case 4:
			solution4();
			break;
		case 0:
			printf("Bye-bye");
			break;
		default:
			printf("Wrong selected\n");
		}
	} while (sel != 0);

	return 0;
}

// Задача 1. Перевод числа из десятичной системы в двоичную
void solution1()
{
	int n;

	result = 0;
	memset(buffer, 0, sizeof(buffer));

	printf("\nЗадача 1. Перевод числа из десятичной системы в двоичную\n");

	// Решение
	printf("Введите целое положительное число:");	
	scanf("%i", &n);
	DecToBin(n);	//Получаем перевёрнутый результат
	StrRev(buffer);		//Переворачиваем результат
	result = atoi(buffer);	//Преобразуем строку в целое
	printf("%i", result);
	printf("\n\n");
}

// Задача 2. Реализовать функцию возведения числа a в степень b:
// a. без рекурсии;
void solution2()
{
	int a, b, i, res = 1;

	printf("Задача 2. Реализовать функцию возведения числа a в степень b без рекурсии\n");
	
	// Решение
	printf("Введите целое положительное число: ");
	scanf("%i", &a);
	printf("Введите степень (целое положительное число): ");
	scanf("%i", &b);
	for (i = 1; i <= b; i++)
		res = res * a;

	printf("Результат возведения числа %i в степень %i: %i", a, b, res);
	printf("\n\n");
}

// b. рекурсивно;
void solution3()
{
	int a, b, res;

	printf("Задача 2. Реализовать функцию возведения числа a в степень b рекурсивно\n");
	
	// Решение
	printf("Введите целое положительное число: ");
	scanf("%i", &a);
	printf("Введите степень (целое положительное число): ");
	scanf("%i", &b);
	res = MyPow(a, b);
	printf("Результат возведения числа %i в степень %i: %i", a, b, res);
	printf("\n\n");

}

// b. рекурсивно, используя свойство четности степени;
void solution4()
{
	int a, b, res;

	printf("Задача 2. Реализовать функцию возведения числа a в степень b рекурсивно, используя свойство четности степени\n");

	// Решение
	printf("Введите целое положительное число: ");
	scanf("%i", &a);
	printf("Введите степень (целое положительное число): ");
	scanf("%i", &b);
	res = MyBinPow(a, b);
	printf("Результат возведения числа %i в степень %i: %i", a, b, res);
	printf("\n\n");

}

void menu()
{
	printf("1 - Перевод числа из десятичной системы в двоичную\n");
	printf("2 - Реализовать функцию возведения числа a в степень b без рекурсии\n");
	printf("3 - Реализовать функцию возведения числа a в степень b рекурсивно\n");
	printf("4 - Реализовать функцию возведения числа a в степень b рекурсивно, используя свойство четности степени\n");
	printf("0 - exit\n");
}

void DecToBin(int n)
{
	char c_res[10] = "";

	if (n > 0)
	{		
		result = n % 2;	//Находим остаток от деления
		ultoa(result, c_res, 10);	//Записываем во временную переменную
		snprintf(buffer, sizeof buffer, "%s%s", buffer, c_res);	//Соединяем строки
		DecToBin(n / 2);		
	}	
}

//Переворот строки
void StrRev(char* S)
{
	int i, j, l;
	char t;
	l = strlen(S);
	i = 0;
	j = l - 1;
	while (i < j)
	{
		t = S[i];
		S[i] = S[j];
		S[j] = t;
		i++; j--;
	}
}

//Возведение в степень рекурсивно
int MyPow(int a, int b)
{		
	if (b > 0) return a * MyPow(a, b - 1);
	return 1;
}

//Возведение в степень рекурсивно, используя свойство четности степени
int MyBinPow(int a, int b)
{
	if (b == 0)
		return 1;
	if (b % 2 == 1)
		return MyBinPow(a, b - 1) * a;
	else
	{
		int c = MyBinPow(a, b / 2);
		return c * c;
	}
}