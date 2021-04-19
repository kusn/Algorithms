// �������� ������
//
// 1. ����������� ���������� ��� - �������.�� ���� ������� �������� ������, �� ������ ����� ����� ��������.
// 2. ���������� ���������, ����������� �������� ������ ������.
// �) �������� � ���� ����� ������ ���������� ���������;
// �) ����������� ����� � �������� ������ ������;
//
// 3. * ����������� ���� ������ ��������� �� ����� �����, ��������, ���������� �����, � ������� ������������ ��� ������, ���������� �� ������.
// �������� ������ � �������� ������ ������.���������� ����� �� ������ - ������ ���� ���� ������(�������, ���).

#include <stdio.h>
#include <locale.h>

typedef int T;
typedef struct Node							// ������ ��������� ������
{
	T data;
	struct Node* left;
	struct Node* right;
	struct Node* parent;
} Node;

void solution1();
void solution2();
void solution3();
void menu();
unsigned int GetHash(char* str);			// �������� ���
Node* GetNewNode(T value, Node* parent);	// �������� ������ ����
void InsertNode(Node** head, int value);	// ������� ����
void GoRootLeftRight(Node* root);			// ����� ������� - 1
void GoLeftRootRight(Node* root);			// ����� ������� - 2
void GoLeftRightRoot(Node* root);			// ����� ������� - 3
T SearchTree(Node* root, T value);			// ����� ��������
void PrintTree(Node* root);					// ���������� ��������� ������ � ���� ��������� ������



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
	char str[30];

	printf("������ 1. ����������� ���������� ��� - �������.�� ���� ������� �������� ������, �� ������ ����� ����� ��������\n");

	// �������
	printf("������� ������: \n");
	scanf("%s", str);
	printf("%u\n\n", GetHash(&str));
}
void solution2()
{
	int arr[10] = { 6,8,7,3,9,10,0,4,1,2 };
	Node* tree = NULL;

	printf("������ 2. ���������� ���������, ����������� �������� ������ ������\n");
	
	// �������		
	printf("������: ");

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
		InsertNode(&tree, arr[i]);
	}
	printf("\n������: ");
	PrintTree(tree);
	printf("\n������ - ���� - �����: ");
	GoRootLeftRight(tree);
	printf("\n���� - ������ - �����: ");
	GoLeftRootRight(tree);
	printf("\n���� - ����� - ������: ");
	GoLeftRightRoot(tree);
	printf("\n����� �������� ""8"": %d", SearchTree(tree, 8));
	printf("\n����� �������� ""11"": %d\n", SearchTree(tree, 11));
	free(tree);
	//PrintTree(tree);					// �������� ������������� ������
	printf("\n");
}
void solution3()
{
	printf("Solution 3\n");
	// �������
}
void menu()
{
	printf("1 - ������ 1. ����������� ���������� ��� - �������.�� ���� ������� �������� ������, �� ������ ����� ����� ��������\n");
	printf("2 - ������ 2. ���������� ���������, ����������� �������� ������ ������.\n \t\t�������� � ���� ����� ������ ���������� ���������.\n \t\t����������� ����� � �������� ������ ������\n");
	printf("3 - task3\n");
	printf("0 - exit\n");
}

//	�������� ���
unsigned int GetHash(char* str)
{
	unsigned int hash = 0;
	
	while (*str != '\0')
	{
		hash = hash + *str;
		str++;
	}

	return hash;
}

// �������� ������ ����
Node* GetNewNode(T value, Node* parent)
{
	Node* tmp = (Node*)malloc(sizeof(Node));
	if (tmp == NULL)
	{
		printf("���� ����������!\n");
		return NULL;
	}
	tmp->left = tmp->right = NULL;
	tmp->data = value;
	tmp->parent = parent;
	return tmp;
}

// ������� ����
void InsertNode(Node** head, int value)
{
	if (*head == NULL)
		*head = GetNewNode(value, NULL);
	else if (value > (*head)->data)
	{
		if ((*head)->right)
			InsertNode(&(*head)->right, value);
		else
			(*head)->right = GetNewNode(value, *head);
	}
	else
	{
		if ((*head)->left)
			InsertNode(&(*head)->left, value);
		else
			(*head)->left = GetNewNode(value, *head);
	}
}

// ����� ������� - 1
void GoRootLeftRight(Node* root)
{
	if (root) {
		printf("%d ", root->data);
		GoRootLeftRight(root->left);
		GoRootLeftRight(root->right);
	}
}

// ����� ������� - 2
void GoLeftRootRight(Node* root)
{
	if (root) {
		GoLeftRootRight(root->left);
		printf("%d ", root->data);
		GoLeftRootRight(root->right);
	}
}

// ����� ������� - 3
void GoLeftRightRoot(Node* root)
{
	if (root) {
		GoLeftRightRoot(root->left);
		GoLeftRightRoot(root->right);
		printf("%d ", root->data);
	}
}

// ����� ��������
T SearchTree(Node* root, T value)
{
	if (root == NULL)
		return -1;											// -1 �� ������
	else if (root->data == value)
		return value;
	else if (root->data > value)
		return SearchTree(root->left, value);
	else
		return SearchTree(root->right, value);
}

// ���������� ��������� ������ � ���� ��������� ������
void PrintTree(Node* root)
{
	if (root != 0xdddddddd)
	{
		printf("%d", root->data);
		if (root->left || root->right)
		{
			printf("(");
			if (root->left)
				PrintTree(root->left);
			else
				printf("NULL");
			printf(",");
			if (root->right)
				PrintTree(root->right);
			else
				printf("NULL");
			printf(")");
		}
	}
	else
		printf("������ ������!\n");
}