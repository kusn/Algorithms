// �������� ������
//
// 1. ����������� ���������� ���������.
// 2. ����������� ������� ����������.
// 3. * ����������� ���������� ��������.
// 4. * *����������� �������� ���������� �� �������.
// ���������������� ����� ������ ������� �� ���� ���������� ��� 100, 10000, 1000000 ���������.

#include <stdio.h>
#include <locale.h>
#include <malloc.h>
#include <math.h>

#define SIZE101 101

void solution1();
void solution2();
void solution3();
void menu();
void Swap(int* p, int* q);							// ������� ������
void QuickSort(int* array, int first, int last);	// ������� ����������
int HeapSort(int* a, int n);						// ������������� ����������
int CountSort(int* arr, int len);					// C��������� ��������
int BinarySearch(int a[], int item, int low, int high);	// �������� �����
void InsertionSort(int a[], int n);					// ���������� ���������� ���������
void Merge(int arr[], int l, int m, int r);			// ������� �������
void MergeSort(int arr[], int l, int r);			// ���������� ��������
int CountSort(int* arr, int len);					// ���������� ���������

int main()
{
	int sel = 0;
	int size = 10;
	int a[10];

	setlocale(LC_ALL, "rus");

	for (int i = 0; i < size; i++)
	{
		a[i] = rand() % 20 - 10;
	}
	for (int i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

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

// ������� ������
void Swap(int* p, int* q)
{
	int buf;
	buf = *p;
	*p = *q;
	*q = buf;
}

// ������� ����������
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
	}
	while (i <= j);

	if (i < last)
		QuickSort(array, i, last);
	if (first < j)
		QuickSort(array, first, j);
}

// ������������� ����������
int HeapSort(int* a, int n)
{
	int i, j, mid, t = n - 1, k;
	mid = n / 2;										// �������� �������
	for (i = mid; i >= 1; i--)
	{
		if (a[i - 1] < a[2 * i - 1])					// ������� ���������, ������� ������������� �����. ����������
			Swap(&a[i - 1], &a[2 * i - 1]);
		if (2 * i < n && a[i - 1] < a[2 * i])			// ���� n-��������
			Swap(&a[i - 1], &a[2 * i]);
	}
	k = 2 * mid;
	Swap(&a[0], &a[t]);
	t--;
	while (t > 0)
	{
		mid = t / 2;									// ������ �� ��������� ����� ����� ������������ �������, ��� ������ �� �������
			for (i = mid; i >= 1; i--)
			{											// � ���������� �� �������� ������
				if (a[i - 1] < a[2 * i - 1])
					Swap(&a[i - 1], &a[2 * i - 1]);
				if (2 * i < n && a[i - 1] < a[2 * i])
					Swap(&a[i - 1], &a[2 * i]);
			}
		k += 2 * mid;
		Swap(&a[0], &a[t]);
		t--;
	}
	if (n > 0 && a[0] > a[1])							// ����� ��������� ���������: �������� � ������ ���������
		Swap(&a[0], &a[1]);
	k++;
	return k;
}

// C��������� ��������
int CountSort(int* arr, int len)
{
	int count = 0;										// ������� ��������� � ���������
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

// �������� �����
int BinarySearch(int a[], int item, int low, int high)
{
	if (high <= low)
	{
		if (item > a[low])
		{
			return (low + 1);
		}
		else
		{
			return low;
		}
	}

	int mid = (low + high) / 2;

	if (item == a[mid])
	{
		return mid + 1;
	}

	if (item > a[mid])
	{
		return BinarySearch(a, item, mid + 1, high);
	}

	return BinarySearch(a, item, low, mid - 1);
}

// ���������� ���������� ���������
void InsertionSort(int a[], int n)
{
	int i, loc, j, k, selected;

	for (i = 1; i < n; i++)
	{
		j = i - 1;
		selected = a[i];

		loc = BinarySearch(a, selected, 0, j);

		while (j >= loc)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = selected;
	}
}

// ������� �������
void Merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	//int L[n1], R[n2];

	int* L = (int*)malloc(n1 * sizeof(int));
	int* R = (int*)malloc(n2 * sizeof(int));

	for (i = 0; i < n1; i++)
		L[i] = arr[l + 1];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	i = 0; j = 0; k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}
}

// ���������� ��������
void MergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		int m = l + (r - 1) / 2;
		MergeSort(arr, l, m);
		MergeSort(arr, m + 1, r);
		Merge(arr, l, m, r);
	}
}

// ���������� ���������
int CountSort(int* arr, int len)
{
	int count = 0;
	int* values = (int*)calloc(SIZE101, sizeof(int));

	if (values == NULL)
	{
		puts("Out of memory!");
		exit(1);
	}

	count += len;
	for (int i = 0; i < len; ++i)
	{
		++values[arr[i]];
	}

	int k = 0;
	for (int i = 0; i < SIZE101; i++)
	{
		for (int j = 0; j < values[i]; ++j)
			arr[k++] = i;
	}
	count += len + SIZE101;

	free(values);
	return count;
}