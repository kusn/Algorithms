// �������� ������

// 1. ����������� �������������� ����������� ����������.
// �������� ���������� �������� ��������� ���������������� � �� ���������������� ���������.
// �������� ������� ����������, ������� ���������� ���������� ��������.
// 2. * ����������� ��������� ����������.
// 3. ����������� �������� �������� ������ � ���� �������, ������� ���������� ��������������� ������.
// ������� ���������� ������ ���������� �������� ��� - 1, ���� ������� �� ������.
// 4. * ���������� ���������� �������� ��� ������ �� ���������� � �������� ��� � ��������������� ���������� ���������.

#include <stdio.h>
#include <malloc.h>
#include <locale.h>
#include <stdlib.h>

int lenghArray = 100;
char* file = "..\\..\\Array.txt";

void solution1();
void solution2();
void solution3();
void menu();
void BubbleSort(int length, int* mass);
void BubbleSortWithFlag(int length, int* mass);
void print(int N, int* a);
void swap(int* a, int* b);
int* GetArrayFromFile(char* file);
void ArrayToFile(int length, char* file);

int main()
{
	int sel = 0;	

	setlocale(LC_ALL, "rus");
	ArrayToFile(lenghArray, file);

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
	int* mass;

	printf("������ 1\n");
	
	// �������
	mass = (int*)malloc(lenghArray * sizeof(int));
	mass = GetArrayFromFile(file);
	printf("����������������� ������\n");
	print(lenghArray, mass);
	printf("��������������� ������ ��������� � ������\n");
	BubbleSortWithFlag(lenghArray, mass);

	mass = GetArrayFromFile(file);
	printf("����������������� ������\n");
	print(lenghArray, mass);
	printf("��������������� ������ ��������� ��� �����\n");
	BubbleSort(lenghArray, mass);
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
	printf("1 - ������ 1\n");
	printf("2 - task2\n");
	printf("3 - task3\n");
	printf("0 - exit\n");
}

// ���������� ��������� � ������
void BubbleSortWithFlag(int length, int* mass)
{
	int tmp, Flag, step = 0;	

	for (int i = length - 1; i >= 0; i--)
	{
		Flag = 1;
		step++;
		for (int j = 0; j < i; j++)
		{
			if (mass[j] > mass[j + 1])
			{
				swap(&mass[j], &mass[j + 1]);
				Flag = 0;
				step++;
			}
		}
		if (Flag == 1)
		{
			step++;
			break;
		}
	}
	printf("��������������� ������:\n");
	print(length, mass);
	printf("\n");
	printf("���������� ����� ��������� %d\n", step);
}

// ���������� ���������
void BubbleSort(int length, int* mass)
{
	int tmp, step = 0;	

	for (int i = length - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (mass[j] > mass[j + 1])
			{
				swap(&mass[j], &mass[j + 1]);
				step++;
			}
		}		
	}
	printf("��������������� ������:\n");
	print(length, mass);
	printf("\n");
	printf("���������� ����� ��������� %d\n", step);
}

// ������������� ������
void print(int N, int* a)
{
	int i;
	for (i = 0; i < N; i++)
		printf("%6i", a[i]);
	printf("\n");
}

// ������ ��������
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

// �������� ������ �� �����
int* GetArrayFromFile(char* file)
{
	int N;
	int* a; // ������ ������ ������������� �������
	int i;
	
	FILE* in;
	in = fopen(file, "r");
	fscanf(in, "%i", &N);
	a = (int*)malloc(N * sizeof(int));	
	for (i = 0; i < N; i++)
	{
		fscanf(in, "%i", &a[i]);
	}
	fclose(in);

	return a;
}

// ������ ���� � ������������� �������
void ArrayToFile(int length, char* file)
{
	int* mass;
	mass = (int*)malloc(length * sizeof(int));

	FILE* out;
	out = fopen(file, "w +");
	fprintf(out, "%i\n", length);
	for (int i = 0; i < length; i++)
	{		
		fprintf(out, "%i\n", rand() % 1000);
	}
	fclose(out);
}