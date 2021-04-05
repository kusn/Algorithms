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
void menu();
void DecToBin(int n);
void StrRev(char* S);


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
		case 0:
			printf("Bye-bye");
			break;
		default:
			printf("Wrong selected\n");
		}
	} while (sel != 0);

	return 0;
}

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
	printf("\n");
}
void solution2()
{
	printf("Solution 2\n");
	// Решение
}
void solution3()
{
	printf("Solution 3\n");
	// Решение
}
void menu()
{
	printf("Задача 1. Перевод числа из десятичной системы в двоичную\n");
	printf("2 - task2\n");
	printf("3 - task3\n");
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