//Кудряшов Сергей
//
//1. Реализовать функцию перевода из десятичной системы в двоичную, используя рекурсию.
//2. Реализовать функцию возведения числа a в степень b :
//a.без рекурсии;
//b.рекурсивно;
//c.* рекурсивно, используя свойство четности степени.

#include <stdio.h>

char* bin;

void solution1();
void solution2();
void solution3();
void menu();
void DecToBin(int n);


int main(int argc, char* argv[])
{
	int sel = 0;
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
	printf("\nЗадача 1. Перевод числа из десятичной системы в двоичную\n");
	// Решение
	printf("Введите целое положительное число:");	
	scanf("%i", &n);
	DecToBin(n);
	printf(&bin);
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
	if (n > 0)
	{
		if (n % 2 == 1)
			bin += '1';
		else
			bin += '0';
		DecToBin(n / 2);
	}
}