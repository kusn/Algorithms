//�������� ������
//
//1. ����������� ������� �������� �� ���������� ������� � ��������, ��������� ��������.
//2. ����������� ������� ���������� ����� a � ������� b :
//a.��� ��������;
//b.����������;
//c.* ����������, ��������� �������� �������� �������.

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int result = 0;
char buffer[12];

void solution1();
void solution2();
void solution3();
void solution4();
void menu();
void DecToBin(int n);
void StrRev(char* S);
int MyPow(int a, int b);
int MyBinPow(int a, int b);


int main(int argc, char* argv[])
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

// ������ 1. ������� ����� �� ���������� ������� � ��������
void solution1()
{
	int n;

	result = 0;
	memset(buffer, 0, sizeof(buffer));

	printf("\n������ 1. ������� ����� �� ���������� ������� � ��������\n");

	// �������
	printf("������� ����� ������������� �����:");	
	scanf("%i", &n);
	DecToBin(n);	//�������� ����������� ���������
	StrRev(buffer);		//�������������� ���������
	result = atoi(buffer);	//����������� ������ � �����
	printf("%i", result);
	printf("\n\n");
}

// ������ 2. ����������� ������� ���������� ����� a � ������� b:
// a. ��� ��������;
void solution2()
{
	int a, b, i, res = 1;

	printf("������ 2. ����������� ������� ���������� ����� a � ������� b ��� ��������\n");
	
	// �������
	printf("������� ����� ������������� �����: ");
	scanf("%i", &a);
	printf("������� ������� (����� ������������� �����): ");
	scanf("%i", &b);
	for (i = 1; i <= b; i++)
		res = res * a;

	printf("��������� ���������� ����� %i � ������� %i: %i", a, b, res);
	printf("\n\n");
}

// b. ����������;
void solution3()
{
	int a, b, res;

	printf("������ 2. ����������� ������� ���������� ����� a � ������� b ����������\n");
	
	// �������
	printf("������� ����� ������������� �����: ");
	scanf("%i", &a);
	printf("������� ������� (����� ������������� �����): ");
	scanf("%i", &b);
	res = MyPow(a, b);
	printf("��������� ���������� ����� %i � ������� %i: %i", a, b, res);
	printf("\n\n");

}

// b. ����������, ��������� �������� �������� �������;
void solution4()
{
	int a, b, res;

	printf("������ 2. ����������� ������� ���������� ����� a � ������� b ����������, ��������� �������� �������� �������\n");

	// �������
	printf("������� ����� ������������� �����: ");
	scanf("%i", &a);
	printf("������� ������� (����� ������������� �����): ");
	scanf("%i", &b);
	res = MyBinPow(a, b);
	printf("��������� ���������� ����� %i � ������� %i: %i", a, b, res);
	printf("\n\n");

}

void menu()
{
	printf("1 - ������� ����� �� ���������� ������� � ��������\n");
	printf("2 - ����������� ������� ���������� ����� a � ������� b ��� ��������\n");
	printf("3 - ����������� ������� ���������� ����� a � ������� b ����������\n");
	printf("4 - ����������� ������� ���������� ����� a � ������� b ����������, ��������� �������� �������� �������\n");
	printf("0 - exit\n");
}

void DecToBin(int n)
{
	char c_res[10] = "";

	if (n > 0)
	{		
		result = n % 2;	//������� ������� �� �������
		ultoa(result, c_res, 10);	//���������� �� ��������� ����������
		snprintf(buffer, sizeof buffer, "%s%s", buffer, c_res);	//��������� ������
		DecToBin(n / 2);		
	}	
}

//��������� ������
void StrRev(char* S)
{
	int i, j, l;
	char t;
	l = strlen(S);
	i = 0;
	j = l - 1;
	while (i < j)
	{
		t = S[i];
		S[i] = S[j];
		S[j] = t;
		i++; j--;
	}
}

//���������� � ������� ����������
int MyPow(int a, int b)
{		
	if (b > 0) return a * MyPow(a, b - 1);
	return 1;
}

//���������� � ������� ����������, ��������� �������� �������� �������
int MyBinPow(int a, int b)
{
	if (b == 0)
		return 1;
	if (b % 2 == 1)
		return MyBinPow(a, b - 1) * a;
	else
	{
		int c = MyBinPow(a, b / 2);
		return c * c;
	}
}