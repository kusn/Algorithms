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
void menu();
void DecToBin(int n);
void StrRev(char* S);


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
	printf("������ 1. ������� ����� �� ���������� ������� � ��������\n");
	printf("2 - task2\n");
	printf("3 - task3\n");
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