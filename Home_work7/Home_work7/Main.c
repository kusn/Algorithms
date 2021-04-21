// �������� ������
//
// 1. �������� �������, ������� ��������� ������� ��������� �� ����� � ������� �� �� �����.
// 2. �������� ����������� ������� ������ ����� � �������.
// 3. �������� ������� ������ ����� � ������.

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <malloc.h>

#define infinity 9999;
#define MAX 6;

int size = MAX;
const char* filename = "..\\..\\adjacencymatrix.txt";

void solution1();
void solution2();
void solution3();
int** GetAdjacencyMatrix(char* file, int size);		// �������� ������� �� �����
void PrintMatrix(int** matrix, int size);			// �������� �������
void menu();

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
	int** G;
	
	printf("������ 1. �������� �������, ������� ��������� ������� ��������� �� ����� � ������� �� �� �����\n");
	
	// �������
	G = (int**)malloc(size * sizeof(int*));
	for (int i = 0; i < size; i++)
		G[i] = (int*)malloc(size * sizeof(int));

	G = GetAdjacencyMatrix(filename, size);
	PrintMatrix(G, size);
	printf("\n");
}
void solution2()
{
	printf("Solution 2\n");
	// �������
}
void solution3()
{
	printf("Solution 3\n");
	// �������
}
void menu()
{
	printf("1 - ������ 1. �������� �������, ������� ��������� ������� ��������� �� ����� � ������� �� �� �����\n");
	printf("2 - task2\n");
	printf("3 - task3\n");
	printf("0 - exit\n");
}

// �������� ������� �� �����
int** GetAdjacencyMatrix(char* filename, int size)
{
	int tmp = 0;
	int** G;

	G = (int**)malloc(size * sizeof(int*));
	for (int i = 0; i < size; i++)
		G[i] = (int*)malloc(size * sizeof(int));

	FILE* file = fopen(filename, "r");
	if (file == NULL)
	{
		printf("���� %s �� ������", filename);
		exit(1);
	}
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			fscanf(file, "%i", &tmp);
			G[i][j] = tmp;
		}
	fclose(file);
	
	return G;
}

// �������� �������
void PrintMatrix(int** matrix, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			printf("%4i", matrix[i][j]);
		printf("\n");
	}
}