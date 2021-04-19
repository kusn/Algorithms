// Кудряшов Сергей
//
// 1. Реализовать простейшую хеш - функцию.На вход функции подается строка, на выходе сумма кодов символов.
// 2. Переписать программу, реализующую двоичное дерево поиска.
// а) Добавить в него обход дерева различными способами;
// б) Реализовать поиск в двоичном дереве поиска;
//
// 3. * Разработать базу данных студентов из полей «Имя», «Возраст», «Табельный номер», в которой использовать все знания, полученные на уроках.
// Считайте данные в двоичное дерево поиска.Реализуйте поиск по какому - нибудь полю базы данных(возраст, вес).

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