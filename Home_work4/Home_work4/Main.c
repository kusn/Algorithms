// �������� ������
//
// 1. * ���������� ��������� � �������������.����������� ������ ������� � ������������ � ���������� ���������� ���������.
// ��������, �����:
// 3 3
// 1 1 1
// 0 1 0
// 0 1 0
//
// 2. ������ ������ � ���������� ����� ������������ ������������������ � ������� �������.
// 3. * **��������� ������ ����� ��������� ����� �������� NxM, ������ ����� ��� ���� ����� �� ������ ����.
// ����� �������� ������� ����� ��, ��� � ������ � 8 ������.������� ������ � �������� ��������� ����.

#include <stdio.h>
#include <locale.h>

#define N 8
#define M 8

void solution1();
void solution2();
void solution3();
void menu();
void Print2(int n, int m, int a[N][M]);

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
	printf("������ 1. ���������� ��������� � �������������.����������� ������ ������� � ������������ � ���������� ���������� ���������\n");
	
	// �������
	int A[N][M];
	int i, j;
	for (j = 0; j < M; j++)
	{
		A[0][j] = 1;
	}
	for (i = 1; i < N; i++)
	{
		A[i][0] = 1;
		for (j = 1; j < M; j++)
		{
			A[i][j] = A[i][j - 1] + A[i - 1][j];
		}
	}
	Print2(N, M, A);
	getch();
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
	printf("1 - ������ 1. ���������� ��������� � �������������.����������� ������ ������� � ������������ � ���������� ���������� ���������\n");
	printf("2 - task2\n");
	printf("3 - task3\n");
	printf("0 - exit\n");
}void Print2(int n, int m, int a[N][M])
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("%6d", a[i][j]);
		}
		printf("\n");
	}
}