//�������� ������
//
//1. ����������� ������� �������� �� ���������� ������� � ��������, ��������� ��������.
//2. ����������� ������� ���������� ����� a � ������� b :
//a.��� ��������;
//b.����������;
//c.* ����������, ��������� �������� �������� �������.

#include <stdio.h>

char* bin;

void solution1();
void solution2();
void solution3();
void menu();
void DecToBin(int n);


int main(int argc, char* argv[])
{
	int sel = 0;
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
	printf("\n������ 1. ������� ����� �� ���������� ������� � ��������\n");
	// �������
	printf("������� ����� ������������� �����:");	
	scanf("%i", &n);
	DecToBin(n);
	printf(&bin);
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
	if (n > 0)
	{
		if (n % 2 == 1)
			bin += '1';
		else
			bin += '0';
		DecToBin(n / 2);
	}
}