// Кудряшов Сергей

// 1. Попробовать оптимизировать пузырьковую сортировку.
// Сравнить количество операций сравнения оптимизированной и не оптимизированной программы.
// Написать функции сортировки, которые возвращают количество операций.
// 2. * Реализовать шейкерную сортировку.
// 3. Реализовать бинарный алгоритм поиска в виде функции, которой передается отсортированный массив.
// Функция возвращает индекс найденного элемента или - 1, если элемент не найден.
// 4. * Подсчитать количество операций для каждой из сортировок и сравнить его с асимптотической сложностью алгоритма.

#include <stdio.h>

void solution1();
void solution2();
void solution3();
void menu();

int main()
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
	printf("Solution 1\n");
	// Решение
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
	printf("1 - task1\n");
	printf("2 - task2\n");
	printf("3 - task3\n");
	printf("0 - exit\n");
}