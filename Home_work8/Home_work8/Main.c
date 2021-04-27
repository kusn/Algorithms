// Кудряшов Сергей
//
// 1. Реализовать сортировку подсчетом.
// 2. Реализовать быструю сортировку.
// 3. * Реализовать сортировку слиянием.
// 4. **Реализовать алгоритм сортировки со списком
// 5. Проанализировать время работы каждого из вида сортировок для 100, 10000, 1000000 элементов.

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <malloc.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define SIZE101 1001

int size = 10;
char* file100 = "..\\..\\Array100.txt";
char* file10000 = "..\\..\\Array10000.txt";
char* file1000000 = "..\\..\\Array1000000.txt";

typedef char* T;
typedef struct tagNode* pNode;

typedef struct tagNode
{
	int key;
	T data;
	pNode next;
} Node;

typedef struct tagList* pList;

typedef struct tagList
{
	pNode first;
	int size;
} List;

void solution1();
void solution2();
void solution3();
void solution4();
void solution5();
void menu();
void Swap(int* p, int* q);							// Функция обмена
unsigned long int QuickSort(int* array, int first, int last);// Быстрая сортировка
unsigned long int HeapSort(int* a, int n);					// Пирамидальная сортировка
int CountSort(int* arr, int len);					// Сортировка подсчетом
int BinarySearch(int a[], int item, int low, int high);	// Бинарный поиск
void InsertionSort(int a[], int n);					// Улучшенная сортировка вставками
unsigned long int MergeSort(long num, int a[]);				// Сортировка слиянием
void PigeonHoleSort(pNode* array, int n, int minValue, int maxValue);	// Сортировка списком
void ShowArrayNode(char* message, pNode* array, int N);
unsigned long int BubbleSort(int* a, int n);					// Пузырьковая сортировка
void swap(int* p, int* q);
unsigned long int ShakerSort(int* a, int n);					// Шейкер-сортировка
unsigned long int ShellsSort(int* a, int n);					// Сортировка Шелла
void PrintArray(int N, int* a);						// Печать массива
int* GetArray(int size);							// Получить массив
int* GetArrayFromFile(char* file);					// Получение массива из файла
void ArrayToFile(int length, char* file);			// Запись массива в файл

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
		case 4:
			solution4();
			break;
		case 5:
			solution5();
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
	
	printf("Задача 1. Реализовать сортировку подсчетом\n");

	// Решение
	mass = (int*)malloc(size * sizeof(int));
	mass = GetArray(size);
	printf("Неотсортированный массив: \n");
	PrintArray(size, mass);
	printf("\n");
	int count = CountSort(mass, size);
	printf("Отсортированный массив: \n");
	PrintArray(size, mass);
	printf("\n");
}
void solution2()
{
	unsigned long int count;
	int* mass;

	printf("Задача 2. Реализовать быструю сортировку\n");
	// Решение
	mass = (int*)malloc(size * sizeof(int));
	mass = GetArray(size);
	printf("Неотсортированный массив: \n");
	PrintArray(size, mass);
	printf("\n");
	count = QuickSort(mass, 0, size);	
	printf("Отсортированный массив: \n");
	PrintArray(size, mass);
	printf("\n");
}
void solution3()
{
	int* mass;
	unsigned long int count;

	printf("Задача 3. Реализовать сортировку слиянием\n");
	// Решение
	mass = (int*)malloc(size * sizeof(int));
	mass = GetArray(size);
	printf("Неотсортированный массив: \n");
	PrintArray(size, mass);
	printf("\n");
	count = MergeSort(size, mass);
	printf("Отсортированный массив: \n");
	PrintArray(size, mass);
	printf("\n");
}
void solution4()
{
	int* mass;

	printf("Задача 4. Реализовать алгоритм сортировки со списком\n");
	// Решение
	mass = (int*)malloc(size * sizeof(int));
	mass = GetArray(size);
	pNode** arrNodes = (pNode*)malloc(size * sizeof(Node));
	for (int i = 0; i < size; i++)
	{
		pNode node = (pNode)malloc(sizeof(Node));
		node->key = mass[i];
		T randData = (char*)malloc(sizeof(char));
		*randData = (char)(rand() % CHAR_MAX);
		node->data = randData;
		node->next = NULL;
		arrNodes[i] = node;
	}

	printf("Неотсортированный массив: \n");
	PrintArray(size, mass);
	printf("\n");
	PigeonHoleSort(arrNodes, size, 0, 1000);
	ShowArrayNode("Отсортированный массив: \n", arrNodes, size);
	printf("\n");
}

void solution5()
{
	int size100 = 100;
	int size10000 = 10000;
	int size1000000 = 1000000;
	unsigned long int count = 0;

	time_t start, end;

	int* mass100;
	int* mass10000;
	int* mass1000000;

	printf("Задача 5. Проанализировать время работы каждого из вида сортировок для 100, 10000, 1000000 элементов\n");
	// Решение
	ArrayToFile(100, file100);
	ArrayToFile(10000, file10000);
	ArrayToFile(1000000, file1000000);
	mass100 = (int*)malloc(size100 * sizeof(int));
	mass10000 = (int*)malloc(size10000 * sizeof(int));
	mass1000000 = (int*)malloc(size1000000 * sizeof(int));

	printf("-----------Сортировка Quick Sort-----------:\n");		
	mass100 = GetArrayFromFile(file100);
	printf("100 элементов: ");
	start = time(NULL);
	count = QuickSort(mass100, 0, 100);
	end = time(NULL);
	printf("Время выполнения: %f;\tКоличество сравнений: %lu\n", difftime(end, start), count);	
	
	mass10000 = GetArrayFromFile(file10000);
	printf("10000 элементов: ");
	start = time(NULL);
	count = QuickSort(mass10000, 0, 10000);
	end = time(NULL);
	printf("Время выполнения: %f;\tКоличество сравнений: %lu\n", difftime(end, start), count);	
	
	mass1000000 = GetArrayFromFile(file1000000);
	printf("1000000 элементов: ");
	start = time(NULL);
	count = QuickSort(mass1000000, 0, 1000000);
	end = time(NULL);
	printf("Время выполнения: %f;\tКоличество сравнений: %lu\n", difftime(end, start), count);	

	printf("-----------Сортировка Shell Sort-----------:\n");	
	mass100 = GetArrayFromFile(file100);
	printf("100 элементов: ");
	time(&start);
	count = ShellsSort(mass100, size100);
	time(&end);
	printf("Время выполнения: %f;\tКоличество сравнений: %lu\n", difftime(end, start), count);
	
	mass10000 = GetArrayFromFile(file10000);
	printf("10000 элементов: ");
	time(&start);
	count = ShellsSort(mass10000, size10000);
	time(&end);
	printf("Время выполнения: %f;\tКоличество сравнений: %lu\n", difftime(end, start), count);
	
	mass1000000 = GetArrayFromFile(file1000000);
	printf("1000000 элементов: ");
	time(&start);
	count = ShellsSort(mass1000000, size1000000);
	time(&end);
	printf("Время выполнения: %f;\tКоличество сравнений: %lu\n", difftime(end, start), count);

	printf("-----------Сортировка Merge Sort-----------:\n");	
	mass100 = GetArrayFromFile(file100);
	printf("100 элементов: ");
	time(&start);
	count = MergeSort(size100, mass100);
	time(&end);
	printf("Время выполнения: %f;\tКоличество сравнений: %lu\n", difftime(end, start), count);

	mass10000 = GetArrayFromFile(file10000);
	printf("10000 элементов: ");
	time(&start);
	count = MergeSort(size10000, mass10000);
	time(&end);
	printf("Время выполнения: %f;\tКоличество сравнений: %lu\n", difftime(end, start), count);

	mass1000000 = GetArrayFromFile(file1000000);
	printf("1000000 элементов: ");
	time(&start);
	count = MergeSort(size1000000, mass1000000);
	time(&end);
	printf("Время выполнения: %f;\tКоличество сравнений: %lu\n", difftime(end, start), count);

	printf("-----------Сортировка Heap Sort-----------:\n");	
	mass100 = GetArrayFromFile(file100);
	printf("100 элементов: ");
	time(&start);
	count = HeapSort(mass100, size100);
	time(&end);
	printf("Время выполнения: %f;\tКоличество сравнений: %lu\n", difftime(end, start), count);

	mass10000 = GetArrayFromFile(file10000);
	printf("10000 элементов: ");
	time(&start);
	count = HeapSort(mass10000, size10000);
	time(&end);
	printf("Время выполнения: %f;\tКоличество сравнений: %lu\n", difftime(end, start), count);

	mass1000000 = GetArrayFromFile(file1000000);
	printf("1000000 элементов: ");
	time(&start);
	count = HeapSort(mass1000000, size1000000);
	time(&end);
	printf("Время выполнения: %f;\tКоличество сравнений: %lu\n", difftime(end, start), count);

	printf("-----------Сортировка Bubble Sort-----------:\n");
	mass100 = GetArrayFromFile(file100);
	printf("100 элементов: ");
	time(&start);
	count = BubbleSort(mass100, size100);
	time(&end);
	printf("Время выполнения: %f;\tКоличество сравнений: %lu\n", difftime(end, start), count);

	mass10000 = GetArrayFromFile(file10000);
	printf("10000 элементов: ");
	time(&start);
	count = BubbleSort(mass10000, size10000);
	time(&end);
	printf("Время выполнения: %f;\tКоличество сравнений: %lu\n", difftime(end, start), count);

	mass1000000 = GetArrayFromFile(file1000000);
	printf("1000000 элементов: ");
	time(&start);
	count = BubbleSort(mass1000000, size1000000);
	time(&end);
	printf("Время выполнения: %f;\tКоличество сравнений: %lu\n", difftime(end, start), count);
	
	printf("-----------Сортировка Shake Sort-----------:\n");
	mass100 = GetArrayFromFile(file100);
	printf("100 элементов: ");
	time(&start);
	count = ShakerSort(mass100, size100);
	time(&end);
	printf("Время выполнения: %f;\tКоличество сравнений: %lu\n", difftime(end, start), count);

	mass10000 = GetArrayFromFile(file10000);
	printf("10000 элементов: ");
	time(&start);
	count = ShakerSort(mass10000, size10000);
	time(&end);
	printf("Время выполнения: %f;\tКоличество сравнений: %lu\n", difftime(end, start), count);

	mass1000000 = GetArrayFromFile(file1000000);
	printf("1000000 элементов: ");
	time(&start);
	count = ShakerSort(mass1000000, size1000000);
	time(&end);
	printf("Время выполнения: %f;\tКоличество сравнений: %lu\n", difftime(end, start), count);
	free(mass100);
	free(mass10000);
	free(mass1000000);
	
	printf("\n\n");
}
void menu()
{
	printf("1 - Задача 1. Реализовать сортировку подсчетом\n");
	printf("2 - Задача 2. Реализовать быструю сортировку\n");
	printf("3 - Задача 3. Реализовать сортировку слиянием\n");
	printf("4 - Задача 4. Реализовать алгоритм сортировки со списком\n");
	printf("5 - Задача 5. Проанализировать время работы каждого из вида сортировок для 100, 10000, 1000000 элементов\n");
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
unsigned long int QuickSort(int* array, int first, int last)
{
	unsigned long int count = 0;
	int i = first, j = last, x = array[(first + last) / 2];

	do
	{
		while (array[i] < x)
		{
			i++;			
		}
		while (array[j] > x)
		{
			j--;			
		}
		if (i <= j)
		{
			if (array[i] > array[j])
			{
				Swap(&array[i], &array[j]);
				count++;
			}
			i++;
			j--;
			count++;
		}
	}
	while (i <= j);

	if (i < last)
	{
		QuickSort(array, i, last);
		count++;
	}
	if (first < j)
	{
		QuickSort(array, first, j);
		count++;
	}
	return count;
}

// Пирамидальная сортировка
unsigned long int HeapSort(int* a, int n)
{
	int i, j, mid, t = n - 1;
	unsigned long int count = 0;

	mid = n / 2;										// середина массива
	for (i = mid; i >= 1; i--)
	{
		if (a[i - 1] < a[2 * i - 1])					// условие сравнения, которое соответствует пирам. сортировке
		{
			Swap(&a[i - 1], &a[2 * i - 1]);
			count++;
		}
		if (2 * i < n && a[i - 1] < a[2 * i])			// если n-нечетное
		{
			Swap(&a[i - 1], &a[2 * i]);
			count++;
		}
	}	
	Swap(&a[0], &a[t]);
	t--;
	while (t > 0)
	{
		mid = t / 2;									// теперь на последнем месте стоит максимальный элемент, его больше не трогаем
			for (i = mid; i >= 1; i--)
			{											// и проходимся по коротким ветвям
				if (a[i - 1] < a[2 * i - 1])
				{
					Swap(&a[i - 1], &a[2 * i - 1]);
					count++;
				}
				if (2 * i < n && a[i - 1] < a[2 * i])
				{
					Swap(&a[i - 1], &a[2 * i]);
					count++;
				}
			}		
		Swap(&a[0], &a[t]);
		t--;
	}
	if (n > 0 && a[0] > a[1])							// самое последнее сравнение: нулевого с первым элементом
	{
		Swap(&a[0], &a[1]);
		count++;
	}	
	return count;
}

// Сортировка подсчетом
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

// Бинарный поиск
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

// Улучшенная сортировка вставками
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

unsigned long int MergeSort(long num, int a[])
{
	int rght, rend;
	int i, j, m;
	unsigned long int count = 0;

	int* b = (int*)malloc(num * sizeof(int));

	for (int k = 1; k < num; k *= 2)
	{
		for (int left = 0; left + k < num; left += k * 2)
		{
			rght = left + k;
			rend = rght + k;
			if (rend > num)
			{
				rend = num;
				count++;
			}
			m = left; i = left; j = rght;
			while (i < rght && j < rend)
			{
				if (a[i] <= a[j])
				{
					b[m] = a[i];
					i++;
					count++;
				}
				else
				{
					b[m] = a[j];
					j++;
					count++;
				}
				m++;
			}
			while (i < rght)
			{
				b[m] = a[i];
				i++; m++;
				count++;
			}
			while (j < rend)
			{
				b[m] = a[j];
				j++; m++;
				count++;
			}
			for (m = left; m < rend; m++)
			{
				a[m] = b[m];
			}
		}
	}
}

// Сортировка списком
void PigeonHoleSort(pNode* array, int n, int minValue, int maxValue)
{
	int k = maxValue - minValue + 1;
	pNode* countArr = (pNode*)malloc(k * sizeof(Node));
	int i;

	for (i = 0; i < k; i++)
		countArr[i] = NULL;

	for (i = 0; i < n; i++)
	{
		pNode node = countArr[array[i]->key - minValue];
		if (node == NULL)
			countArr[array[i]->key - minValue] = array[i];
		else
		{
			while (node->next != NULL)
				node = node->next;
			node->next = array[i];
		}
	}

	int	b = 0;

	for (i = 0; i < k; i++)
	{
		pNode p = countArr[i];
		while (p != NULL)
		{
			array[b] = p;
			b++;
			p = p->next;
			if (p != NULL)
				array[b]->next = NULL;
		}
	}
	free(countArr);
}

void ShowArrayNode(char* message, pNode* array, int N)
{	
	for (int i = 0; i < N; i++)
		printf(((i == 0) ? "(%d, %c)" : ", (%d, %c)"), array[i]->key, array[i]->data);	
}

// Пузырьковая сортировка
unsigned long int BubbleSort(int* a, int n)
{
	int j = 0;
	unsigned long int count = 0;
	
	for (int i = 0; i < n; i++)
	{
		for (j = 0; j < n - 1; j++)
		{			
			if (a[j] > a[j + 1])
			{
				// простая операция перестановки
				count++;
				swap(&a[j], &a[j + 1]);
			}
		}
	}
	return count;
}

void swap(int* p, int* q)
{
	int buf;
	buf = *p;
	*p = *q;
	*q = buf;
}

// Шейкер-сортировка
unsigned long int ShakerSort(int* a, int n)
{
	// границы и подсчет операций
	int left = 0,
		right = n - 1;
	unsigned long int count = 0;

	while (left <= right)
	{
		// прямой обход
		for (int i = left; i < right; i++)
		{			
			if (a[i] > a[i + 1]) {
				count++;
				swap(&a[i], &a[i + 1]);
			}
		}
		right--;
		// обратный обход
		for (int i = right; i > left; i--)
		{			
			if (a[i - 1] > a[i]) {
				count++;
				swap(&a[i], &a[i - 1]);
			}
		}
		left++;
	}
	return count;
}

// Сортировка Шелла
unsigned long int ShellsSort(int* a, int n)
{
	int i, j, k;
	int t;
	unsigned long int count = 0;

	for (k = n / 2; k > 0; k /= 2)
		for (i = k; i < n; i++)
		{
			t = a[i];
			for (j = i; j >= k; j -= k)
			{
				
				if (t < a[j - k])
				{
					a[j] = a[j - k];
					count++;
				}
				else
					break;
			}
			a[j] = t;
		}
	return count;
}


// Печать массива
void PrintArray(int N, int* a)
{
	int i;
	for (i = 0; i < N; i++)
		printf("%6i", a[i]);
	printf("\n");
}

// Получить массив
int* GetArray(int size)
{
	int* mass;

	mass = (int*)malloc(size * sizeof(int));
	for (int i = 0; i < size; i++)
	{
		mass[i] = rand() % 1000;
	}

	return mass;
}

// Получение массива из файла
int* GetArrayFromFile(char* file)
{
	int N;
	int* a;
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

// Запись массива в файл
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