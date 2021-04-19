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

void solution1();
void solution2();
void solution3();
void menu();
int main()
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
	printf("Solution 1\n");
	// �������
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
	printf("1 - task1\n");
	printf("2 - task2\n");
	printf("3 - task3\n");
	printf("0 - exit\n");
}