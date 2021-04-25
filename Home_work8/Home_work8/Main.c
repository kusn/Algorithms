// Кудряшов Сергей
//
// 1. Реализовать сортировку подсчетом.
// 2. Реализовать быструю сортировку.
// 3. * Реализовать сортировку слиянием.
// 4. * *Реализовать алгоритм сортировки со списком.
// Проанализировать время работы каждого из вида сортировок для 100, 10000, 1000000 элементов.

#include <stdio.h>
#include <locale.h>
#include <malloc.h>

#define SIZE101 101

void solution1();
void solution2();
void solution3();
void menu();
void Swap(int* p, int* q);							// Функция обмена
void QuickSort(int* array, int first, int last);	// Быстрая сортировка
int HeapSort(int* a, int n);						// Пирамидальная сортировка
int CountSort(int* arr, int len);					// Cортировка слиянием

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
	printf("Solution 1\n");
	// Решение
}
void solution2()
{
	printf("Solution 2\n");
	// Решение
}
void solution3()
{
	printf("Solution 3\n");
	// Решение
}
void menu()
{
	printf("1 - task1\n");
	printf("2 - task2\n");
	printf("3 - task3\n");
	printf("0 - exit\n");
}

// Функция обмена
void Swap(int* p, int* q)
{
	int buf;
	buf = *p;
	*p = *q;
	*q = buf;
}

// Быстрая сортировка
void QuickSort(int* array, int first, int last)
{
	int i = first, j = last, x = array[(first + last) / 2];
	do
	{
		while (array[i] < x)
			i++;
		while (array[j] > x)
			j--;
		if (i <= j)
		{
			if (array[i] > array[j])
				Swap(&array[i], &array[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (i < last)
		QuickSort(array, i, last);
	if (first < j)
		QuickSort(array, first, j);
}

// Пирамидальная сортировка
int HeapSort(int* a, int n)
{
	int i, j, mid, t = n - 1, k;
	mid = n / 2;										// середина массива
	for (i = mid; i >= 1; i--)
	{
		if (a[i - 1] < a[2 * i - 1])					// условие сравнения, которое соответствует пирам. сортировке
			Swap(&a[i - 1], &a[2 * i - 1]);
		if (2 * i < n && a[i - 1] < a[2 * i])			// если n-нечетное
			Swap(&a[i - 1], &a[2 * i]);
	}
	k = 2 * mid;
	Swap(&a[0], &a[t]);
	t--;
	while (t > 0)
	{
		mid = t / 2;									// теперь на последнем месте стоит максимальный элемент, его больше не трогаем
			for (i = mid; i >= 1; i--)
			{											// и проходимся по коротким ветвям
				if (a[i - 1] < a[2 * i - 1])
					Swap(&a[i - 1], &a[2 * i - 1]);
				if (2 * i < n && a[i - 1] < a[2 * i])
					Swap(&a[i - 1], &a[2 * i]);
			}
		k += 2 * mid;
		Swap(&a[0], &a[t]);
		t--;
	}
	if (n > 0 && a[0] > a[1])							// самое последнее сравнение: нулевого с первым элементом
		Swap(&a[0], &a[1]);
	k++;
	return k;
}

// Cортировка слиянием
int CountSort(int* arr, int len)
{
	int count = 0;										// счетчик обращений к элементам
	int* values = (int*)calloc(SIZE101, sizeof(int));
	if (values == NULL) {
		puts("Out of memory!");
		exit(1);
	}
	count += len;
	for (int i = 0; i < len; ++i) {
		++values[arr[i]];
	}
	int k = 0;
	for (int i = 0; i < SIZE101; ++i) {
		for (int j = 0; j < values[i]; ++j)
			arr[k++] = i;
	}
	count += len + SIZE101;
	free(values);
	return count;
}
