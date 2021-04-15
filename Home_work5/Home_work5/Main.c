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
void solution4();
void solution5();
void solution6();
void menu();
void push(T value);
T pop();
void PrintStack();
void push2(TT value);
TT pop2();
void PrintStack2();
void DecToBin(int n);
int IsBracketSequence(char* s, int size);
void pushToStack(struct Stack *stack, T value);
T popStack(struct Stack *Stack);
struct Stack CopyStack(struct Stack* FromStack);
void PrintStack3(struct Stack Stack);
int precedence(char с);
void init(struct Stack* stack);
int empty(struct Stack* Stack);
int full(struct Stack* Stack);
int top(struct Stack* Stack);
void infix_to_postfix(char infix[], char postfix[]);
void enQueue(struct Queue* q, int k);
void deQueue(struct Queue* q);						// Количество функций росло по мере выполнения ДЗ

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

// Нода связного списка
struct QNode
{
	int key;
	struct QNode* next;
};


// Структура очереди с двумя ссылками на начало и конец связного списка
struct Queue
{
	struct QNode* front;
	struct QNode* rear;
};

//Создание новой ноды связного списка. 
struct QNode* newNode(int k)
{
	struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
	temp->key = k;
	temp->next = NULL;
	return temp;
}

//Создание пустой очереди
struct Queue* createQueue()
{
	struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
	q->front = NULL;
	q->rear = NULL;
	return q;
}

struct Stack Stack;
struct Stack Stack3, Stack4;
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
		case 4:
			solution4();
			break;
		case 5:
			solution5();
			break;
		case 6:
			solution6();
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
	printf("\n\n");

}
void solution4()
{
	int x1, x2, x3, x4, x5;

	Stack3.maxSize = 5;
	Stack4.maxSize = 5;
	Stack3.head = NULL;
	Stack4.head = NULL;
	Stack3.size = 0;
	Stack4.size = 0;
	printf("Задача 4. Создать функцию, копирующую односвязный список(то есть создает в памяти копию односвязного списка, не удаляя первый список)\n");

	// Решение
	printf("Введите 5 целых чисел в формате \"х, у\": ");
	scanf("%i,%i,%i,%i,%i", &x1, &x2, &x3, &x4, &x5);
	pushToStack(&Stack3, x1);
	pushToStack(&Stack3, x2);
	pushToStack(&Stack3, x3);
	pushToStack(&Stack3, x4);
	pushToStack(&Stack3, x5);
	printf("Стэк №1: ");
	PrintStack3(Stack3);
	printf("\n");
	Stack4 = CopyStack(&Stack3);
	printf("Стэк №2: ");
	PrintStack3(Stack4);
	printf("\n\n");

}
void solution5()
{
	char infix[30], postfix[30];

	printf("Задача 5. Реализовать алгоритм перевода из инфиксной записи арифметического выражения в постфиксную\n");

	// Решение
	printf("Введите инфиксную запись например (5+2*4): ");
	scanf("%s", &infix);	
	infix_to_postfix(infix, postfix);
	printf("\nПостфиксная запись: %s\n\n", postfix);
}
void solution6()
{
	struct Queue* q = createQueue();

	printf("Задача 6. Реализовать очередь\n");

	// Решение
	
	enQueue(q, 10);
	enQueue(q, 20);
	deQueue(q);
	deQueue(q);
	enQueue(q, 30);
	enQueue(q, 40);
	enQueue(q, 50);
	deQueue(q);
	printf("Фронт очереди : %d \n", q->front->key);
	printf("Тыл очереди : %d\n\n", q->rear->key);
}
void menu()
{
	printf("1 - Задача 1. Реализовать перевод из десятичной в двоичную систему счисления с использованием стека\n");
	printf("2 - Задача 2. Добавить в программу «реализация стека на основе односвязного списка» проверку на выделение памяти\n");
	printf("3 - Задача 3. Написать программу, которая определяет, является ли введенная скобочная последовательность правильной\n");
	printf("4 - Задача 4. Создать функцию, копирующую односвязный список(то есть создает в памяти копию односвязного списка, не удаляя первый список)\n");
	printf("5 - Задача 5. Реализовать алгоритм перевода из инфиксной записи арифметического выражения в постфиксную\n");
	printf("6 - Задача 6. Реализовать очередь\n");
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

void pushToStack(struct Stack *stack, T value)
{
	if (stack->size >= stack->maxSize) {
		printf("Ошибка. Стек переполнен!\n");
		return;
	}
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->value = value;
	tmp->next = stack->head;
	stack->head = tmp;
	stack->size++;
}

T popStack(struct Stack *stack)
{
	if (stack->size == 0)
	{
		printf("Stack is empty");
		return;
	}
	// Временный указатель
	Node* next = NULL;
	// Значение "наверху" списка
	T value;
	value = stack->head->value;
	next = stack->head;
	stack->head = stack->head->next;
	// Запись, на которую указывала голова удаляем, освобождая память
	free(next);
	// Возвращаем значение, которое было в голове
	stack->size--;
	return value;
}

struct Stack CopyStack(struct Stack *FromStack)
{
	T value;
	struct Stack ToStack;
	struct Stack TempStack;
	ToStack.maxSize = FromStack->size;
	TempStack.maxSize = FromStack->size;
	ToStack.head = NULL;
	TempStack.head = NULL;
	ToStack.size = 0;
	TempStack.size = 0;

	if (FromStack->size == 0)
	{
		printf("Исходный стек пустой");
		return;
	}
	Node* current = FromStack->head;
	while (current != NULL)
	{
		value = current->value;
		current = current->next;
		pushToStack(&TempStack, value);		
	}
	
	while (TempStack.size)
	{
		value = popStack(&TempStack);
		pushToStack(&ToStack, value);
	}
	return ToStack;
}

void PrintStack3(struct Stack Stack)
{
	Node* current = Stack.head;
	while (current != NULL)
	{
		printf("%i", current->value);
		current = current->next;
	}
}

int precedence(char с)
{
	if (с == '(')
		return(0);
	if (с == '+' || с == '-')
		return(1);
	if (с == '*' || с == '/' || с == '%')
		return(2);

	return(3);
}

void init(struct Stack* stack)
{
	stack->head = NULL;
	stack->size = 0;
	
}

int empty(struct Stack* stack)
{
	if (stack->size == 0)
		return 1;

	return 0;
}

int full(struct Stack* stack)
{
	if (stack->size == stack->maxSize)
		return 1;

	return 0;
}

int top(struct Stack* stack)
{
	Node* current = stack->head;
	return (current->value);
}

void infix_to_postfix(char infix[], char postfix[])
{
	struct Stack s;
	char x, token;
	int i, j;
	
	init(&s);
	s.maxSize = 30;
	j = 0;

	for (i = 0; infix[i] != '\0'; i++)
	{
		token = infix[i];
		if (isalnum(token))
			postfix[j++] = token;
		else
			if (token == '(')
				pushToStack(&s, '(');
			else
				if (token == ')')
					while ((x = popStack(&s)) != '(')
						postfix[j++] = x;
				else
				{
					if(!empty(&s))
						while (precedence(token) <= precedence(top(&s)))
						{
							x = popStack(&s);
							postfix[j++] = x;
						}
					pushToStack(&s, token);
				}
	}

	while (!empty(&s))
	{
		x = popStack(&s);
		postfix[j++] = x;
	}

	postfix[j] = '\0';
}

// Добавление ноды в очередь
void enQueue(struct Queue* q, int k)
{
	// Создание ноды 
	struct QNode* temp = newNode(k);

	// Если очередь пуста то первая нода является и головой и хвостом одновременно
	if (q->rear == NULL)
	{
		q->front = temp;
		q->rear = temp;
		return;
	}

	// Добавляем новую ноду в конец 
	q->rear->next = temp;
	q->rear = temp;
}

// Удаление ноды по ключу
void deQueue(struct Queue* q)
{
	// Если очередь пуста то return NULL. 
	if (q->front == NULL)
		return;

	// Сохраняем предыдущиее значение головы, и перемещаем front на одну ноду вперед 
	struct QNode* temp = q->front;

	q->front = q->front->next;

	//Если голова стала NULL, то меняем конецтакже на NULL 
	if (q->front == NULL)
		q->rear = NULL;

	free(temp);
}