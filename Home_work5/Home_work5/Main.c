// �������� ������
//
// 1. ����������� ������� �� ���������� � �������� ������� ��������� � �������������� �����.
// 2. �������� � ��������� ����������� ����� �� ������ ������������ ������ �������� �� ��������� ������.
// ���� ������ �� ����������, �� ��������� ��������������� ���������.
// ������������ ������� ��������, ����� ������ �� ����� ����������(����������� �������� ���������� ������).
// 3. �������� ���������, ������� ����������, �������� �� ��������� ��������� ������������������ ����������.
// ������� ���������� ��������� ��������� : (), ([])(), {}(), ([{}]), ������������ � )(, ())({ ), (, ]) }), ([(]) ��� ������[, (, { .
// ��������: (2 + (2 * 2)) ���[2 / {5 * (4 + 7)}]
//
// 4. * ������� �������, ���������� ����������� ������(�� ���� ������� � ������ ����� ������������ ������, �� ������ ������ ������).
// 5. * *����������� �������� �������� �� ��������� ������ ��������������� ��������� � �����������.
// 6. * ����������� �������.


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
void menu();
void push(T value);
T pop();
void PrintStack();
void push2(TT value);
TT pop2();
void PrintStack2();
void DecToBin(int n);
int IsBracketSequence(char* s, int size);
void pushToStack(struct Stack Stack, T value);
T popStack(struct Stack Stack);
void CopyStack(struct Stack FromStack, struct Stack ToStack);
void PrintStack3(struct Stack Stack);

// ������ ��������� ���� ������
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
	printf("������ 1. ����������� ������� �� ���������� � �������� ������� ��������� � �������������� �����\n");

	// �������
	printf("������� ����� ������������� �����: ");
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
	printf("������ 2. �������� � ��������� ����������� ����� �� ������ ������������ ������ �������� �� ��������� ������\n");
	
	// �������
	printf("��������� ��������� � �������� ��� ����� ������������� ����� 9 � ������� ����� �������� � 3 �������\n");
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
	printf("������ 3.  �������� ���������, ������� ����������, �������� �� ��������� ��������� ������������������ ����������\n");
	
	// �������
	printf("������� ��������� ������������������. ��������: (2 + (2 * 2)) ���[2 / {5 * (4 + 7)}]\n");
	scanf("%s", s);
	
	if (IsBracketSequence(s, 30))
		printf("��������� ������������������ �����\n");
	else
		printf("��������� ������������������ �� �����\n");
	printf("\n");

}

void solution4()
{
	int x1, x2, x3, x4, x5;

	Stack3.maxSize = 5;
	Stack4.maxSize = 5;
	Stack3.head = NULL;
	Stack4.head = NULL;
	printf("������ 4. ������� �������, ���������� ����������� ������(�� ���� ������� � ������ ����� ������������ ������, �� ������ ������ ������)\n");

	// �������
	printf("������� 5 ����� ����� � ������� \"�, �\": ");
	scanf("%i,%i,%i,%i,%i", &x1, &x2, &x3, &x4, &x5);
	pushToStack(Stack3, x1);
	pushToStack(Stack3, x2);
	pushToStack(Stack3, x3);
	pushToStack(Stack3, x4);
	pushToStack(Stack3, x5);
	printf("���� �1: ");
	PrintStack3(Stack3);
	printf("\n");
	CopyStack(Stack3, Stack4);
	printf("���� �2: ");
	PrintStack3(Stack4);
	printf("\n");

}
void menu()
{
	printf("1 - ������ 1. ����������� ������� �� ���������� � �������� ������� ��������� � �������������� �����\n");
	printf("2 - ������ 2. �������� � ��������� ����������� ����� �� ������ ������������ ������ �������� �� ��������� ������\n");
	printf("3 - ������ 3. �������� ���������, ������� ����������, �������� �� ��������� ��������� ������������������ ����������\n");
	printf("4 - ������ 4. ������� �������, ���������� ����������� ������(�� ���� ������� � ������ ����� ������������ ������, �� ������ ������ ������)\n");
	printf("0 - exit\n");
}

void push(T value)
{
	if (Stack.size >= Stack.maxSize) {
		printf("������. ���� ����������!\n");
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
		printf("������. ���� ����������!\n");
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
	// ��������� ���������
	Node* next = NULL;
	// �������� "�������" ������
	T value;
	value = Stack.head->value;
	next = Stack.head;
	Stack.head = Stack.head->next;
	// ������, �� ������� ��������� ������ �������, ���������� ������
	free(next);
	// ���������� ��������, ������� ���� � ������
	Stack.size--;
	return value;
}

TT pop2() {
	if (Stack2.size == 0)
	{
		printf("Stack is empty");
		return;
	}
	// ��������� ���������
	Node2* next = NULL;
	// �������� "�������" ������
	TT value;
	value = Stack2.head->value;
	next = Stack2.head;
	Stack2.head = Stack2.head->next;
	// ������, �� ������� ��������� ������ �������, ���������� ������
	free(next);
	// ���������� ��������, ������� ���� � ������
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

void pushToStack(struct Stack stack, T value)
{
	if (stack.size >= stack.maxSize) {
		printf("������. ���� ����������!\n");
		return;
	}
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->value = value;
	tmp->next = stack.head;
	stack.head = tmp;
	stack.size++;
}

T popStack(struct Stack Stack)
{
	if (Stack.size == 0)
	{
		printf("Stack is empty");
		return;
	}
	// ��������� ���������
	Node* next = NULL;
	// �������� "�������" ������
	T value;
	value = Stack.head->value;
	next = Stack.head;
	Stack.head = Stack.head->next;
	// ������, �� ������� ��������� ������ �������, ���������� ������
	free(next);
	// ���������� ��������, ������� ���� � ������
	Stack.size--;
	return value;
}

void CopyStack(struct Stack FromStack, struct Stack ToStack)
{
	T value;
	struct Stack TempStack;
	TempStack.maxSize = FromStack.size;
	TempStack.head = NULL;

	if (FromStack.size == 0)
	{
		printf("�������� ���� ������");
		return;
	}
	Node* current = FromStack.head;
	while (current != NULL)
	{
		value = current->value;
		current = current->next;
		pushToStack(TempStack, current);
	}
	
	while (TempStack.size)
	{
		pushToStack(ToStack, popStack(TempStack));
	}	
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