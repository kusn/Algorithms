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

#define TYPE_TREE_BY_ID 0
#define TYPE_TREE_BY_AGE 1
#define TYPE_TREE_BY_NAME 2

typedef int T;
typedef struct Node							// ������ ��������� ������
{
	T data;
	struct Node* left;
	struct Node* right;
	struct Node* parent;
} Node;

typedef struct Student						// ������ ��������� ��������
{
	int id;
	char name[30];
	char age;
} Student;

typedef struct StudentNode					// ������� ������ ���������
{
	struct StudentNode* next;
	struct Student* data;
} StudentNode;

typedef struct StudentsStack				// ���� ���������
{
	struct StudentNode* head;
	int size;
	int maxsize;
} StudentsStack;

typedef struct StudentsTreeNode				// ������� ������ ���������
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
unsigned int GetHash(char* str);			// �������� ���
Node* GetNewNode(T value, Node* parent);	// �������� ������ ����
void InsertNode(Node** head, int value);	// ������� ����
void GoRootLeftRight(Node* root);			// ����� ������� - 1
void GoLeftRootRight(Node* root);			// ����� ������� - 2
void GoLeftRightRoot(Node* root);			// ����� ������� - 3
T SearchTree(Node* root, T value);			// ����� ��������
void PrintTree(Node* root);					// ���������� ��������� ������ � ���� ��������� ������
StudentsTreeNode* GetNewStudentsTreeNode(StudentNode* value, StudentsTreeNode* parent);	// �������� ������ ���� ������
StudentNode* GetNewStudentNode(StudentNode* head, Student* data);						// �������� ������ �������� ������
void InsertStudentNode(StudentsTreeNode** head, Student* value, int type);				// ������� ���� ������ ���������
StudentsTreeNode* GetSearchTree(StudentNode* head, int type);							// ��������� ������ ������
void WriteToDB();																		// ������ �������� ���� ���������
void PushStack(StudentsStack* stack, Student* value);									// ���������� ��������� � ����
void PrintStudents(StudentNode* node);													// ����� ��������� �� �����
void PrintTreeStudents(StudentsTreeNode* root);											// ����� ������ ������ ���������
StudentNode* SearchByName(StudentsTreeNode* root, char* name);							// ����� �� �������� �� �����
StudentNode* SearchByAge(StudentsTreeNode* root, int age);								// ����� �� �������� �� ��������
StudentNode* SearchById(StudentsTreeNode* root, int id);								// ����� �� �������� �� ID
void LoadDB(StudentsStack* stack);														// �������� ���� ������


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
	StudentsStack students;
	students.head = NULL;
	students.size = 0;
	StudentsTreeNode* searchTreeId = NULL;
	StudentsTreeNode* searchTreeAge = NULL;
	StudentsTreeNode* searchTreeName = NULL;

	printf("������ 3. ����������� ���� ������ ��������� �� ����� �����, ��������, ���������� �����\n");

	// �������
	WriteToDB();
	LoadDB(&students);
	printf("\n��������� ���������: %d\n", students.size);
	printf("id-------���---------------------�������\n");
	PrintStudents(students.head);

	searchTreeId = GetSearchTree(students.head, TYPE_TREE_BY_ID);
	searchTreeAge = GetSearchTree(students.head, TYPE_TREE_BY_AGE);
	searchTreeName = GetSearchTree(students.head, TYPE_TREE_BY_NAME);

	printf("\n������ ������ �� �����: \n");
	printf("id-------���---------------------�������\n");
	PrintTreeStudents(searchTreeName);
	printf("\n");
	printf("\n������ ������ �� id: \n");
	printf("id-------���---------------------�������\n");
	PrintTreeStudents(searchTreeId);
	printf("\n");
	printf("\n������ ������ �� ��������: \n");
	printf("id-------���---------------------�������\n");
	PrintTreeStudents(searchTreeAge);
	printf("\n");

	printf("\n����� �� ����� ���� ������: \n");
	printf("id-------���---------------------�������\n");
	PrintStudents(SearchByName(searchTreeName, "���� ������"));
	printf("\n");
	printf("\n����� �� ��������� 21: \n");
	printf("id-------���---------------------�������\n");
	PrintStudents(SearchByAge(searchTreeAge, 21));
	printf("\n");
	printf("\n����� �� ������ 10: \n");
	printf("id-------���---------------------�������\n");
	PrintStudents(SearchById(searchTreeId, 10));
	printf("\n");
	printf("\n");
}
void menu()
{
	printf("1 - ������ 1. ����������� ���������� ��� - �������.�� ���� ������� �������� ������, �� ������ ����� ����� ��������\n");
	printf("2 - ������ 2. ���������� ���������, ����������� �������� ������ ������.\n \t\t�������� � ���� ����� ������ ���������� ���������.\n \t\t����������� ����� � �������� ������ ������\n");
	printf("3 - ������ 3. ����������� ���� ������ ��������� �� ����� �����, ��������, ���������� �����, \n\t\t� ������� ������������ ��� ������, ���������� �� ������. \n\t\t�������� ������ � �������� ������ ������.���������� ����� �� ������ - ������ ���� ���� ������(�������, ���)\n");
	printf("0 - �����\n");
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
	{
		printf("������ ������!\n");
		return;
	}
}

// �������� ������ ���� ������
StudentsTreeNode* GetNewStudentsTreeNode(StudentNode* value, StudentsTreeNode* parent)
{
	StudentsTreeNode* tmp = (StudentsTreeNode*)malloc(sizeof(StudentsTreeNode));
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

// �������� ������ �������� ������
StudentNode* GetNewStudentNode(StudentNode* head, Student* data)
{
	StudentNode* tmp = (StudentNode*)malloc(sizeof(StudentNode));
	if (tmp == NULL)
	{
		printf("���� ����������!\n");
		return NULL;
	}
	tmp->data = data;
	tmp->next = head;
	return tmp;
}

// ������� ����
void InsertStudentNode(StudentsTreeNode** head, Student* value, int type)	// ���������� �������� ������������ � ������ �� ����� ����
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
		printf("����������� ��� ���������� ������!");
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

// ��������� ������ ������
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

// ������ �������� ���� ���������
void WriteToDB()
{
	int i = 0;
	Student student[10];

	strcpy(student[0].name, "���� ������");
	student[0].id = 6;
	student[0].age = 18;
	strcpy(student[1].name, "������� ��������");
	student[1].id = 22;
	student[1].age = 20;
	strcpy(student[2].name, "����� �������");
	student[2].id = 11;
	student[2].age = 21;
	strcpy(student[3].name, "������� ��������");
	student[3].id = 18;
	student[3].age = 23;
	strcpy(student[4].name, "���� ������");
	student[4].id = 16;
	student[4].age = 18;
	strcpy(student[5].name, "������ ��������");
	student[5].id = 100;
	student[5].age = 20;
	strcpy(student[6].name, "���� �����");
	student[6].id = 34;
	student[6].age = 24;
	strcpy(student[7].name, "���������� ������������");
	student[7].id = 12;
	student[7].age = 19;
	strcpy(student[8].name, "������� ��������");
	student[8].id = 7;
	student[8].age = 21;
	strcpy(student[9].name, "��������� �����������");
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

// ���������� ��������� � ����
void PushStack(StudentsStack* stack, Student* value)
{
	stack->head = GetNewStudentNode(stack->head, value);
	stack->size++;
}

// ����� ��������� �� �����
void PrintStudents(StudentNode* node)
{
	if (node)
	{
		printf("%d\t%s\t\t%d\n", node->data->id, node->data->name, node->data->age);
		PrintStudents(node->next);
	}
}

// ����� ������ ������ ���������
void PrintTreeStudents(StudentsTreeNode* root)
{
	if (root)
	{
		PrintTreeStudents(root->left);
		printf("����: \n");
		PrintStudents(root->data);
		PrintTreeStudents(root->right);
	}
}

// ����� �� �������� �� �����
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

// ����� �� �������� �� ��������
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

// ����� �� �������� �� ID
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

// �������� ���� ������
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