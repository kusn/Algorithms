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

#define TYPE_TREE_BY_ID 0
#define TYPE_TREE_BY_AGE 1
#define TYPE_TREE_BY_NAME 2

typedef int T;
typedef struct Node							// Создаём структуру дерева
{
	T data;
	struct Node* left;
	struct Node* right;
	struct Node* parent;
} Node;

typedef struct Student						// Создаём структуру Студента
{
	int id;
	char name[30];
	char age;
} Student;

typedef struct StudentNode					// Элемент списка студентов
{
	struct StudentNode* next;
	struct Student* data;
} StudentNode;

typedef struct StudentsStack				// Стек студентов
{
	struct StudentNode* head;
	int size;
	int maxsize;
} StudentsStack;

typedef struct StudentsTreeNode				// Элемент дерева студентов
{
	struct StudentNode* data;
	struct StudentsTreeNode* left;
	struct StudentsTreeNode* right;
	struct StudentsTreeNode* parent;
} StudentsTreeNode;

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
StudentsTreeNode* GetNewStudentsTreeNode(StudentNode* value, StudentsTreeNode* parent);	// Создание нового узла дерева
StudentNode* GetNewStudentNode(StudentNode* head, Student* data);						// Создание нового элемента списка
void InsertStudentNode(StudentsTreeNode** head, Student* value, int type);				// Вставка узла дерева студентов
StudentsTreeNode* GetSearchTree(StudentNode* head, int type);							// Генерация дерева поиска
void WriteToDB();																		// Запись тестовой базы студентов
void PushStack(StudentsStack* stack, Student* value);									// Добавление студентов в стек
void PrintStudents(StudentNode* node);													// Вывод студентов на экран
void PrintTreeStudents(StudentsTreeNode* root);											// Вывод дерева поиска студентов
StudentNode* SearchByName(StudentsTreeNode* root, char* name);							// Поиск по студента по Имени
StudentNode* SearchByAge(StudentsTreeNode* root, int age);								// Поиск по студента по Возрасту
StudentNode* SearchById(StudentsTreeNode* root, int id);								// Поиск по студента по ID
void LoadDB(StudentsStack* stack);														// Загрузка базы данных


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
	StudentsStack students;
	students.head = NULL;
	students.size = 0;
	StudentsTreeNode* searchTreeId = NULL;
	StudentsTreeNode* searchTreeAge = NULL;
	StudentsTreeNode* searchTreeName = NULL;

	printf("Задача 3. Разработать базу данных студентов из полей «Имя», «Возраст», «Табельный номер»\n");

	// Решение
	WriteToDB();
	LoadDB(&students);
	printf("\nСтудентов загружено: %d\n", students.size);
	printf("id-------Имя---------------------Возраст\n");
	PrintStudents(students.head);

	searchTreeId = GetSearchTree(students.head, TYPE_TREE_BY_ID);
	searchTreeAge = GetSearchTree(students.head, TYPE_TREE_BY_AGE);
	searchTreeName = GetSearchTree(students.head, TYPE_TREE_BY_NAME);

	printf("\nДерево поиска по имени: \n");
	printf("id-------Имя---------------------Возраст\n");
	PrintTreeStudents(searchTreeName);
	printf("\n");
	printf("\nДерево поиска по id: \n");
	printf("id-------Имя---------------------Возраст\n");
	PrintTreeStudents(searchTreeId);
	printf("\n");
	printf("\nДерево поиска по Возрасту: \n");
	printf("id-------Имя---------------------Возраст\n");
	PrintTreeStudents(searchTreeAge);
	printf("\n");

	printf("\nПоиск по имени Иван Иванов: \n");
	printf("id-------Имя---------------------Возраст\n");
	PrintStudents(SearchByName(searchTreeName, "Иван Иванов"));
	printf("\n");
	printf("\nПоиск по восзрасту 21: \n");
	printf("id-------Имя---------------------Возраст\n");
	PrintStudents(SearchByAge(searchTreeAge, 21));
	printf("\n");
	printf("\nПоиск по номеру 10: \n");
	printf("id-------Имя---------------------Возраст\n");
	PrintStudents(SearchById(searchTreeId, 10));
	printf("\n");
	printf("\n");
}
void menu()
{
	printf("1 - Задача 1. Реализовать простейшую хеш - функцию.На вход функции подается строка, на выходе сумма кодов символов\n");
	printf("2 - Задача 2. Переписать программу, реализующую двоичное дерево поиска.\n \t\tДобавить в него обход дерева различными способами.\n \t\tРеализовать поиск в двоичном дереве поиска\n");
	printf("3 - Задача 3. Разработать базу данных студентов из полей «Имя», «Возраст», «Табельный номер», \n\t\tв которой использовать все знания, полученные на уроках. \n\t\tСчитайте данные в двоичное дерево поиска.Реализуйте поиск по какому - нибудь полю базы данных(возраст, вес)\n");
	printf("0 - Выход\n");
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
	{
		printf("Дерево пустое!\n");
		return;
	}
}

// Создание нового узла дерева
StudentsTreeNode* GetNewStudentsTreeNode(StudentNode* value, StudentsTreeNode* parent)
{
	StudentsTreeNode* tmp = (StudentsTreeNode*)malloc(sizeof(StudentsTreeNode));
	if (tmp == NULL)
	{
		printf("Стек переполнен!\n");
		return NULL;
	}
	tmp->left = tmp->right = NULL;
	tmp->data = value;
	tmp->parent = parent;
	return tmp;
}

// Создание нового элемента списка
StudentNode* GetNewStudentNode(StudentNode* head, Student* data)
{
	StudentNode* tmp = (StudentNode*)malloc(sizeof(StudentNode));
	if (tmp == NULL)
	{
		printf("Стек переполнен!\n");
		return NULL;
	}
	tmp->data = data;
	tmp->next = head;
	return tmp;
}

// Вставка узла
void InsertStudentNode(StudentsTreeNode** head, Student* value, int type)	// Одинаковые значения объединяются в список на одном узле
{
	int IsRight = 0;
	if (*head == NULL)
	{
		*head = GetNewStudentsTreeNode(GetNewStudentNode(NULL, value), NULL);
		return;
	}

	switch (type)
	{
	case TYPE_TREE_BY_ID:
		if (value->id == (*head)->data->data->id)
		{
			(*head)->data = GetNewStudentNode((*head)->data, value);
			return;
		}
		IsRight = (value->id > (*head)->data->data->id);
		break;
	case TYPE_TREE_BY_AGE:
		if (value->age == (*head)->data->data->age)
		{
			(*head)->data = GetNewStudentNode((*head)->data, value);
			return;
		}
		IsRight = (value->age > (*head)->data->data->age);
		break;
	case TYPE_TREE_BY_NAME:
		IsRight = strcmp(value->name, (*head)->data->data->name);
		if (IsRight == 0)
		{
			(*head)->data = GetNewStudentNode((*head)->data, value);
			return;
		}
		IsRight = (IsRight > 0);
		break;
	default:
		printf("Неизвестный тип построения дерева!");
	}

	if (IsRight)
	{
		if ((*head)->right)
			InsertStudentNode(&(*head)->right, value, type);
		else
			(*head)->right = GetNewStudentsTreeNode(GetNewStudentNode(NULL, value), *head);
	}
	else {
		if ((*head)->left)
			InsertStudentNode(&(*head)->left, value, type);
		else
			(*head)->left = GetNewStudentsTreeNode(GetNewStudentNode(NULL, value), *head);
	}
}

// Генерация дерева поиска
StudentsTreeNode* GetSearchTree(StudentNode* head, int type)
{
	StudentsTreeNode* tree = NULL;
	while (head)
	{
		InsertStudentNode(&tree, head->data, type);
		head = head->next;
	}
	return tree;
}

// Запись тестовой базы студентов
void WriteToDB()
{
	int i = 0;
	Student student[10];

	strcpy(student[0].name, "Иван Иванов");
	student[0].id = 6;
	student[0].age = 18;
	strcpy(student[1].name, "Алексей Алексеев");
	student[1].id = 22;
	student[1].age = 20;
	strcpy(student[2].name, "Роман Романов");
	student[2].id = 11;
	student[2].age = 21;
	strcpy(student[3].name, "Дмитрий Дмитриев");
	student[3].id = 18;
	student[3].age = 23;
	strcpy(student[4].name, "Петр Петров");
	student[4].id = 16;
	student[4].age = 18;
	strcpy(student[5].name, "Кирилл Кириллов");
	student[5].id = 100;
	student[5].age = 20;
	strcpy(student[6].name, "Илья Ильин");
	student[6].id = 34;
	student[6].age = 24;
	strcpy(student[7].name, "Константин Константинов");
	student[7].id = 12;
	student[7].age = 19;
	strcpy(student[8].name, "Николай Николаев");
	student[8].id = 7;
	student[8].age = 21;
	strcpy(student[9].name, "Александр Александров");
	student[9].id = 10;
	student[9].age = 22;

	FILE* file = fopen("..//..//students.db", "wb");
	if (file != NULL)
	{
		for (i = 0; i < 10; i++)
			fwrite(&student[i], sizeof(Student), 1, file);
		fclose(file);
	}
}

// Добавление студентов в стек
void PushStack(StudentsStack* stack, Student* value)
{
	stack->head = GetNewStudentNode(stack->head, value);
	stack->size++;
}

// Вывод студентов на экран
void PrintStudents(StudentNode* node)
{
	if (node)
	{
		printf("%d\t%s\t\t%d\n", node->data->id, node->data->name, node->data->age);
		PrintStudents(node->next);
	}
}

// Вывод дерева поиска студентов
void PrintTreeStudents(StudentsTreeNode* root)
{
	if (root)
	{
		PrintTreeStudents(root->left);
		printf("Узел: \n");
		PrintStudents(root->data);
		PrintTreeStudents(root->right);
	}
}

// Поиск по студента по Имени
StudentNode* SearchByName(StudentsTreeNode* root, char* name)
{
	int result = 0;
	if (root == NULL)
		return NULL;
	result = strcmp(root->data->data->name, name);
	if (result == 0)
		return root->data;
	else if (result > 0)
		return SearchByName(root->left, name);
	else
		return SearchByName(root->right, name);
}

// Поиск по студента по Возрасту
StudentNode* SearchByAge(StudentsTreeNode* root, int age)
{
	if (root == NULL)
		return NULL;
	if (root->data->data->age == age)
		return root->data;
	else if (root->data->data->age > age)
		return SearchByAge(root->left, age);
	else
		return SearchByAge(root->right, age);
}

// Поиск по студента по ID
StudentNode* SearchById(StudentsTreeNode* root, int id)
{
	if (root == NULL)
		return NULL;
	if (root->data->data->id == id)
		return root->data;
	else if (root->data->data->id > id)
		return SearchById(root->left, id);
	else
		return SearchById(root->right, id);
}

// Загрузка базы данных
void LoadDB(StudentsStack* stack)
{
	Student* student;
	FILE* file = fopen("..//..//students.db", "rb");
	if (file != NULL)
	{
		while (!feof(file))
		{
			student = malloc(sizeof(Student));
			if (fread(student, sizeof(Student), 1, file))
				PushStack(stack, student);
			else
				free(student);
		}
		fclose(file);
	}
}