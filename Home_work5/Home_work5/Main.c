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

// ������ ��������� ���� ������
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
	printf("Solution 3\n");
	// �������
}
void menu()
{
	printf("1 - ������ 1. ����������� ������� �� ���������� � �������� ������� ��������� � �������������� �����\n");
	printf("2 - ������ 2. �������� � ��������� ����������� ����� �� ������ ������������ ������ �������� �� ��������� ������\n");
	printf("3 - task3\n");
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