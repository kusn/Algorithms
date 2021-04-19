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
#include <locale.h>

typedef int T;
typedef struct Node							// Создаём структуру дерева
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
unsigned int GetHash(char* str);			// Получаем хэш
Node* GetNewNode(T value, Node* parent);	// Создание нового узла
void InsertNode(Node** head, int value);	// Вставка узла
void GoRootLeftRight(Node* root);			// Обход вариант - 1
void GoLeftRootRight(Node* root);			// Обход вариант - 2
void GoLeftRightRoot(Node* root);			// Обход вариант - 3
T SearchTree(Node* root, T value);			// Поиск элемента
void PrintTree(Node* root);					// Распечатка двоичного дерева в виде скобочной записи



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

	printf("Задача 1. Реализовать простейшую хеш - функцию.На вход функции подается строка, на выходе сумма кодов символов\n");

	// Решение
	printf("Введите строку: \n");
	scanf("%s", str);
	printf("%u\n\n", GetHash(&str));
}
void solution2()
{
	int arr[10] = { 6,8,7,3,9,10,0,4,1,2 };
	Node* tree = NULL;

	printf("Задача 2. Переписать программу, реализующую двоичное дерево поиска\n");
	
	// Решение		
	printf("Массив: ");

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
		InsertNode(&tree, arr[i]);
	}
	printf("\nДерево: ");
	PrintTree(tree);
	printf("\nКорень - Лево - Право: ");
	GoRootLeftRight(tree);
	printf("\nЛево - Корень - Право: ");
	GoLeftRootRight(tree);
	printf("\nЛево - Право - Корень: ");
	GoLeftRightRoot(tree);
	printf("\nПоиск значения ""8"": %d", SearchTree(tree, 8));
	printf("\nПоиск значения ""11"": %d\n", SearchTree(tree, 11));
	free(tree);
	//PrintTree(tree);					// Проверка высвобождения памяти
	printf("\n");
}
void solution3()
{
	printf("Solution 3\n");
	// Решение
}
void menu()
{
	printf("1 - Задача 1. Реализовать простейшую хеш - функцию.На вход функции подается строка, на выходе сумма кодов символов\n");
	printf("2 - Задача 2. Переписать программу, реализующую двоичное дерево поиска.\n \t\tДобавить в него обход дерева различными способами.\n \t\tРеализовать поиск в двоичном дереве поиска\n");
	printf("3 - task3\n");
	printf("0 - exit\n");
}

//	Получаем хэш
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

// Создание нового узла
Node* GetNewNode(T value, Node* parent)
{
	Node* tmp = (Node*)malloc(sizeof(Node));
	if (tmp == NULL)
	{
		printf("Стэк переполнен!\n");
		return NULL;
	}
	tmp->left = tmp->right = NULL;
	tmp->data = value;
	tmp->parent = parent;
	return tmp;
}

// Вставка узла
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

// Обход вариант - 1
void GoRootLeftRight(Node* root)
{
	if (root) {
		printf("%d ", root->data);
		GoRootLeftRight(root->left);
		GoRootLeftRight(root->right);
	}
}

// Обход вариант - 2
void GoLeftRootRight(Node* root)
{
	if (root) {
		GoLeftRootRight(root->left);
		printf("%d ", root->data);
		GoLeftRootRight(root->right);
	}
}

// Обход вариант - 3
void GoLeftRightRoot(Node* root)
{
	if (root) {
		GoLeftRightRoot(root->left);
		GoLeftRightRoot(root->right);
		printf("%d ", root->data);
	}
}

// Поиск элемента
T SearchTree(Node* root, T value)
{
	if (root == NULL)
		return -1;											// -1 не найден
	else if (root->data == value)
		return value;
	else if (root->data > value)
		return SearchTree(root->left, value);
	else
		return SearchTree(root->right, value);
}

// Распечатка двоичного дерева в виде скобочной записи
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
		printf("Дерево пустое!\n");
}