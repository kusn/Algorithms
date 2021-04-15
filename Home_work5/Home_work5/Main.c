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
#include <stdlib.h>
#define T int
#define TT char

int result = 0;
char buffer[12];

void solution1();
void solution2();
void solution3();
void menu();
void push(T value);
T pop();
void PrintStack();
void push2(TT value);
TT pop2();
void PrintStack2();
void DecToBin(int n);
int IsBracketSequence(char* s, int size);

// Опишем структуру узла списка
struct TNode
{
	T value;
	struct TNode* next;
};

struct TTNode
{
	TT value;
	struct TTNode* next;
};

typedef struct TNode Node;
typedef struct TTNode Node2;

struct Stack
{
	Node* head;
	int size;
	int maxSize;
};

struct Stack2
{
	Node2* head;
	int size;
	int maxSize;
};

struct Stack Stack;
struct Stack2 Stack2;


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
	char s[30];

	Stack2.maxSize = 30;
	Stack2.head = NULL;
	Stack2.size = 0;
	printf("Задача 3.  Написать программу, которая определяет, является ли введенная скобочная последовательность правильной\n");
	
	// Решение
	printf("Введите скобочную последовательность. Например: (2 + (2 * 2)) или[2 / {5 * (4 + 7)}]\n");
	scanf("%s", s);
	
	if (IsBracketSequence(s, 30))
		printf("Скобочная последовательность верна\n");
	else
		printf("Скобочная последовательность не верна\n");
	printf("\n");

}
void menu()
{
	printf("1 - Задача 1. Реализовать перевод из десятичной в двоичную систему счисления с использованием стека\n");
	printf("2 - Задача 2. Добавить в программу «реализация стека на основе односвязного списка» проверку на выделение памяти\n");
	printf("3 - Задача 3.  Написать программу, которая определяет, является ли введенная скобочная последовательность правильной\n");
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

void push2(TT value)
{
	if (Stack2.size >= Stack2.maxSize) {
		printf("Ошибка. Стек переполнен!\n");
		return;
	}
	Node2* tmp = (Node2*)malloc(sizeof(Node2));
	tmp->value = value;
	tmp->next = Stack2.head;
	Stack2.head = tmp;
	Stack2.size++;
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

TT pop2() {
	if (Stack2.size == 0)
	{
		printf("Stack is empty");
		return;
	}
	// Временный указатель
	Node2* next = NULL;
	// Значение "наверху" списка
	TT value;
	value = Stack2.head->value;
	next = Stack2.head;
	Stack2.head = Stack2.head->next;
	// Запись, на которую указывала голова удаляем, освобождая память
	free(next);
	// Возвращаем значение, которое было в голове
	Stack2.size--;
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

void PrintStack2()
{
	Node2* current = Stack2.head;
	while (current != NULL)
	{
		printf("%c", current->value);
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

int IsBracketSequence(char* s, int size)
{
	int r = 0;
	char c;

	for (int i = 0; i < size; i++)
	{
		if (Stack2.size != 0)
			r = 0;
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
		{
			push2(s[i]);
		}
		else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
		{
			c = pop2();
			if (s[i] == ')' && c == '(')
				r = 1;
			else if (s[i] == ']' && c == '[')
				r = 1;
			else if (s[i] == '}' && c == '{')
				r = 1;
			else
				r = 0;
		}
	}

	return r;
}