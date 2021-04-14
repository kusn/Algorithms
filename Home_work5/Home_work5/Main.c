// Кудряшов Сергей
//
// 1. Реализовать перевод из десятичной в двоичную систему счисления с использованием стека.
// 2. Добавить в программу «реализация стека на основе односвязного списка» проверку на выделение памяти.
// Если память не выделяется, то выводится соответствующее сообщение.
// Постарайтесь создать ситуацию, когда память не будет выделяться(добавлением большого количества данных).
// 3. Написать программу, которая определяет, является ли введенная скобочная последовательность правильной.
// Примеры правильных скобочных выражений : (), ([])(), {}(), ([{}]), неправильных — )(, ())({ ), (, ]) }), ([(]) для скобок[, (, { .
// Например: (2 + (2 * 2)) или[2 / {5 * (4 + 7)}]
//
// 4. * Создать функцию, копирующую односвязный список(то есть создает в памяти копию односвязного списка, не удаляя первый список).
// 5. * *Реализовать алгоритм перевода из инфиксной записи арифметического выражения в постфиксную.
// 6. * Реализовать очередь.


#include <stdio.h>
#include <malloc.h>
#include <locale.h>
#define T int

int result = 0;
char buffer[12];

void solution1();
void solution2();
void solution3();
void menu();
void push(T value);
T pop();
void PrintStack();
void DecToBin(int n);

// Опишем структуру узла списка
struct TNode
{
	T value;
	struct TNode* next;
};

typedef struct TNode Node;

struct Stack
{
	Node* head;
	int size;
	int maxSize;
};
struct Stack Stack;



int main()
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
	Stack.maxSize = 100;
	Stack.head = NULL;
	printf("Задача 1. Реализовать перевод из десятичной в двоичную систему счисления с использованием стека\n");

	// Решение
	printf("Введите целое положительное число: ");
	scanf("%i", &n);
	DecToBin(n);
	PrintStack();
	printf("\n\n");
}
void solution2()
{
	int n = 9;

	result = 0;
	Stack.maxSize = 3;
	Stack.head = NULL;
	printf("Задача 2. Добавить в программу «реализация стека на основе односвязного списка» проверку на выделение памяти\n");
	
	// Решение
	printf("Попробуем перевести в двоичный вид целое положительное число 9 с помощью стека размером в 3 разряда\n");
	//scanf("%i", &n);
	DecToBin(n);
	PrintStack();
	printf("\n\n");
}
void solution3()
{
	printf("Solution 3\n");
	// Решение
}
void menu()
{
	printf("1 - Задача 1. Реализовать перевод из десятичной в двоичную систему счисления с использованием стека\n");
	printf("2 - Задача 2. Добавить в программу «реализация стека на основе односвязного списка» проверку на выделение памяти\n");
	printf("3 - task3\n");
	printf("0 - exit\n");
}

void push(T value)
{
	if (Stack.size >= Stack.maxSize) {
		printf("Ошибка. Стек переполнен!\n");
		return;
	}
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->value = value;
	tmp->next = Stack.head;
	Stack.head = tmp;
	Stack.size++;
}

T pop() {
	if (Stack.size == 0)
	{
		printf("Stack is empty");
		return;
	}
	// Временный указатель
	Node* next = NULL;
	// Значение "наверху" списка
	T value;
	value = Stack.head->value;
	next = Stack.head;
	Stack.head = Stack.head->next;
	// Запись, на которую указывала голова удаляем, освобождая память
	free(next);
	// Возвращаем значение, которое было в голове
	Stack.size--;
	return value;
}

void PrintStack()
{
	Node* current = Stack.head;
	while (current != NULL)
	{
		printf("%i", current->value);
		current = current->next;
	}
}

void DecToBin(int n)
{
	while (n)
	{
		result = n % 2;
		push(result);
		n = n / 2;
	}
}