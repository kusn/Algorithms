//�������� ������

/*1. ������ ��� � ���� ��������.���������� � ������� ������ ����� ���� �� ������� I = m / (h * h);
��� m - ����� ���� � �����������, h - ���� � ������.
2. ����� ������������ �� ������� �����.������� �� ������������.
3. �������� ��������� ������ ���������� ���� ������������� ���������� :
a.� �������������� ������� ����������;
b.* ��� ������������� ������� ����������.

4. �������� ��������� ���������� ������ ��������� ����������� ���������.*/

#include <stdio.h>
#include <locale.h>
#include <math.h>

void solution1();
void solution2();
void solution3();
void solution4();
void menu();


int main(int argc, const char* argv[])
{
	int sel = 0;
	
	setlocale(LC_ALL, "Rus");
	
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
	// ��������� ������ ����� ����	
	double m, h, imt;

	printf("������ 1. ���\n");
	printf("������� ����� ���� � �����������: ");
	scanf("%lf", &m);
	printf("������� ���� � ������: ");
	scanf("%lf", &h);

	imt = m / (h * h);
	printf("������ ����� ���� �����: %lf\n", imt);
	printf("\n");
}

void solution2()
{
	// ����� ������������ �� ������� �����. ������� �� ������������.
	int x1, x2, x3, x4, max;

	printf("������ 2. ����� ������������ �� ������� �����\n");
	printf("������� ������ �����: ");
	scanf("%i", &x1);
	printf("������� ������ �����: ");
	scanf("%i", &x2);
	printf("������� ������ �����: ");
	scanf("%i", &x3);
	printf("������� ��������� �����: ");
	scanf("%i", &x4);

	max = x1;
	if (x2 > max)
		max = x2;
	if (x3 > max)
		max = x3;
	if (x4 > max)
		max = x4;
	printf("������������ �� 4-�: %i\n", max);
	printf("\n");
}

void solution3()
{
	// �������� ��������� ������ ���������� ���� ������������� ����������:
	// a.� �������������� ������� ����������;
	// b.* ��� ������������� ������� ����������.
	int a, b, c;

	printf("������ 3. �������� ��������� ������ ���������� ���� ������������� ����������\n");
	printf("������� ������ ���������� a: ");
	scanf("%i", &a);
	printf("������� ������ ���������� b: ");
	scanf("%i", &b);

	printf("����� � ������������� ������� ����������:\n");
	c = a;
	a = b;
	b = c;
	printf("a - %i, b - %i\n\n", a, b);

	printf("����� ��� ������������� ������� ����������:\n");	
	a = a + b;
	b = a - b;
	a = a - b;
	printf("a - %i, b - %i\n\n", a, b);
}

void solution4()
{
	// �������� ��������� ���������� ������ ��������� ����������� ���������
	double a, b, c, d, x1, x2;

	printf("������ 4. ���������� ������ ��������� ����������� ���������\n");
	printf("������� ����������� a: ");
	scanf("%lf", &a);
	printf("������� ����������� b: ");
	scanf("%lf", &b);
	printf("������� ����������� c: ");
	scanf("%lf", &c);
	printf("���������� ��������� %lfx^2+%lfx+%lf\n", a, b, c);

	d = b * b - 4 * a * c;
	if (d < 0)
		printf("������ ���");
	else if (d > 0)
	{
		x1 = (-1.0 * b + sqrt(d)) / (2.0 * a);
		x2 = (-1.0 * b - sqrt(d)) / (2.0 * a);
		printf("����� ��������� �1 = %lf, �2 = %lf\n", x1, x2);
	}
	else
	{
		x1 = (-1.0 * b + sqrt(d)) / (2.0 * a);		
		printf("������ ��������� �1 = %lf\n", x1);
	}	
	printf("\n");
}

void menu()
{
	printf("1 - ������ 1. ���\n");
	printf("2 - ������ 2. ����� �������������\n");
	printf("3 - ������ 3. ����� ���������� ���� ������������� ����������\n");
	printf("4 - ������ 4. ���������� ������ ��������� ����������� ���������\n");
	printf("0 - exit\n");
}
