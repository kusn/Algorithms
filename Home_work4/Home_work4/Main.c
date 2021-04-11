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
#include <string.h>

#define N 8
#define M 8
#define mapN 4
#define mapM 4

int c[20][20];
char x[20], y[20], b[20][20];

void solution1();
void solution2();
void solution3();
void menu();
void Print2(int n, int m, int a[N][M]);
void PrintOfMap(int n, int m, int a[mapN][mapM]);
void print(int i, int j);
void lcs(int m, int n);

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
	int A[N][M], map[mapN][mapM];
	int i, j;
	
	printf("������ 1. ���������� ��������� � �������������.����������� ������ ������� � ������������ � ���������� ���������� ���������\n");
	
	// �������
	
	// ����� �����	
	for (i = 0; i < mapN; i++)
		for (j = 0; j < mapM; j++)
			map[i][j] = rand() % 2;
	map[0][0] = 1;
	PrintOfMap(mapN, mapM, map);
	printf("\n");

	// ������������ ���-�� ���������
	for (j = 0; j < M; j++)                                              // ��������� ������ �������
	{
		A[0][j] = 1;
		if (map[0][j] == 0 && j < mapM || (A[0][j - 1] == 0 && j >= 1))	// ���� � MAP 0, �� � � ����� ������� ��� ������ ���� 0
		{																// ���� ����� ������� ������, �� � � ��������� ������� ������ �� ������
			A[0][j] = 0;
		}
	}
	for (i = 1; i < N; i++)
	{
		if (map[i][0] == 0 && i < mapN || (A[i - 1][0] == 0 && i >= 1))	// ���� � MAP 0, �� � � ����� ������� ��� ������ ���� 0
		{																// ���� ������ ������� ������, �� � � ��������� ������� ������ �� ������
			A[i][0] = 0;
		}
		else {
			A[i][0] = 1;
		}

		for (j = 1; j < M; j++)
		{
			if (map[i][j] == 0 && i < mapN && j < mapM)
			{
				A[i][j] = 0;
			}
			else {
				A[i][j] = A[i][j - 1] + A[i - 1][j];
			}
		}
	}
	printf("��������� ��������:\n");
	Print2(N, M, A);
	getch();
}
void solution2()
{
	int i, j, m, n, c[20][20];
	char x[20], y[20], b[20][20];
	
	printf("������ 2. ������ ������ � ���������� ����� ������������ ������������������ � ������� �������\n");

	// �������

	printf("������� ������ ������������������:");
	scanf("%s", x);
	printf("������� ������ ������������������:");
	scanf("%s", y);
	printf("\n���������� ����� ���������: \n");
	m = strlen(x);
	n = strlen(y);
	lcs(m, n);
	print(m, n);
	getch();
}
void solution3()
{
	printf("Solution 3\n");
	// �������
}
void menu()
{
	printf("1 - ������ 1. ���������� ��������� � �������������.����������� ������ ������� � ������������ � ���������� ���������� ���������\n");
	printf("2 - ������ 2. ������ ������ � ���������� ����� ������������ ������������������ � ������� �������\n");
	printf("3 - task3\n");
	printf("0 - exit\n");
}

void Print2(int n, int m, int a[N][M])
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

void PrintOfMap(int n, int m, int a[mapN][mapM])
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

void print(int i, int j)
{
	if (i == 0 || j == 0)
		return;
	if (b[i][j] == 'c')
	{
		print(i - 1, j - 1);
		printf("%c", x[i - 1]);
	}
	else if (b[i][j] == 'u')
		print(i - 1, j);
	else
		print(i, j - 1);
}

void lcs(int m, int n)
{	
	for (int i = 0; i <= m; i++)
		c[i][0] = 0;
	for (int i = 0; i <= n; i++)
		c[0][i] = 0;

	//c, u � l ���������� ����������, ���������� � ���������� ����������� ��������������(cross upper left)
	//m - ����� ������ ������
	//n - ����� ������ ������
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (x[i - 1] == y[j - 1])
			{
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = 'c';
				printf("%c", b[i][j]);
			}
			else if (c[i - 1][j] >= c[i][j - 1])
			{
				c[i][j] = c[i - 1][j];
				b[i][j] = 'u';
				printf("%c", b[i][j]);
			}
			else
			{
				c[i][j] = c[i][j - 1];
				b[i][j] = 'l';
				printf("%c", b[i][j]);
			}
		}
		printf("\n");
	}
}