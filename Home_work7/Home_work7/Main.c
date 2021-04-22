// �������� ������
//
// 1. �������� �������, ������� ��������� ������� ��������� �� ����� � ������� �� �� �����.
// 2. �������� ����������� ������� ������ ����� � �������.
// 3. �������� ������� ������ ����� � ������.

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <malloc.h>

#define infinity 9999
#define MAX 6
#define SIZE 40

int size = MAX;
const char* filename = "..\\..\\adjacencymatrix.txt";

typedef struct Node
{
	int vertex;
	struct Node* next;
} Node;

typedef struct Graph
{
	int numVertices;
	int* visited;
	Node** adjList;
} Graph;

typedef struct Queue
{
	int items[SIZE];
	int front;
	int rear;
} Queue;

void solution1();
void solution2();
void solution3();
void menu();
int** GetAdjacencyMatrix(char* file, int size);		// �������� ������� �� �����
void PrintMatrix(int** matrix, int size);			// �������� �������
Node* CreateNode(int v);							// ������ ����� ����
Graph* CreateGraph(int vertices);					// ������ ����
void AddEdge(Graph* graph, int src, int dest);		// ��������� �����
void PrintGraph(Graph* graph);						// �������� ����
void DFS(Graph* graph, int vertex);					// ����� ����� � �������
void GetGraphFromMatrix(Graph* graph, int** matrix, int size);	// ������ ���� �� ������� ���������
Queue* CreateQueue();								// ������ �������
void Enqueue(Queue* q, int value);					// ��������� � �������
int Dequeue(Queue* q);								// ����� �� �������
void DisplayQueue(Queue* q);						// ��������� �������
int isEmpty(Queue* q);								// �������� �� �������
void PrintQueue(Queue* q);							// ������ �������
void BFS(Graph* graph, int startVertex);			// ����� ����� � ������

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
	int** G;
	
	printf("������ 1. �������� �������, ������� ��������� ������� ��������� �� ����� � ������� �� �� �����\n");
	
	// �������
	G = (int**)malloc(size * sizeof(int*));
	for (int i = 0; i < size; i++)
		G[i] = (int*)malloc(size * sizeof(int));

	G = GetAdjacencyMatrix(filename, size);
	PrintMatrix(G, size);
	printf("\n");
}
void solution2()
{
	int** G;
	Graph* graph = CreateGraph(size);

	printf("������ 2. �������� ����������� ������� ������ ����� � �������\n");
	// �������

	G = (int**)malloc(size * sizeof(int*));
	for (int i = 0; i < size; i++)
		G[i] = (int*)malloc(size * sizeof(int));

	G = GetAdjacencyMatrix(filename, size);
	printf("������� ���������:\n");
	PrintMatrix(G, size);	
	GetGraphFromMatrix(graph, G, size);
	PrintGraph(graph);
	DFS(graph, 0);
	printf("\n");
}
void solution3()
{
	int** G;
	Graph* graph = CreateGraph(size);

	printf("������ 3. �������� ������� ������ ����� � ������\n");
	// �������
	G = (int**)malloc(size * sizeof(int*));
	for (int i = 0; i < size; i++)
		G[i] = (int*)malloc(size * sizeof(int));

	G = GetAdjacencyMatrix(filename, size);
	printf("������� ���������:\n");
	PrintMatrix(G, size);
	GetGraphFromMatrix(graph, G, size);
	PrintGraph(graph);
	BFS(graph, 0);
	printf("\n");
}
void menu()
{
	printf("1 - ������ 1. �������� �������, ������� ��������� ������� ��������� �� ����� � ������� �� �� �����\n");
	printf("2 - ������ 2. �������� ����������� ������� ������ ����� � �������\n");
	printf("3 - ������ 3. �������� ������� ������ ����� � ������\n");
	printf("0 - exit\n");
}

// �������� ������� �� �����
int** GetAdjacencyMatrix(char* filename, int size)
{
	int tmp = 0;
	int** G;

	G = (int**)malloc(size * sizeof(int*));
	for (int i = 0; i < size; i++)
		G[i] = (int*)malloc(size * sizeof(int));

	FILE* file = fopen(filename, "r");
	if (file == NULL)
	{
		printf("���� %s �� ������", filename);
		exit(1);
	}
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			fscanf(file, "%i", &tmp);
			G[i][j] = tmp;
		}
	fclose(file);
	
	return G;
}

// �������� �������
void PrintMatrix(int** matrix, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			printf("%4i", matrix[i][j]);
		printf("\n");
	}
}

// ������ ����� ����
Node* CreateNode(int v)
{
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->vertex = v;
	newNode->next = NULL;
	return newNode;
}

// ������ ����
Graph* CreateGraph(int vertices)
{
	Graph* graph = (Graph*)malloc(sizeof(Graph));

	graph->numVertices = vertices;
	graph->adjList = malloc(vertices * sizeof(Node*));
	graph->visited = malloc(vertices * sizeof(int));

	for (int i = 0; i < vertices; i++)
	{
		graph->adjList[i] = NULL;
		graph->visited[i] = 0;
	}
	return graph;
}

// ��������� �����
void AddEdge(Graph* graph, int src, int dest)
{
	// ������ ����� �� ���������
	Node* newNode = CreateNode(dest);
	newNode->next = graph->adjList[src];
	graph->adjList[src] = newNode;

	// ������ ����� � ���������
	newNode = CreateNode(src);
	newNode->next = graph->adjList[dest];
	graph->adjList[dest] = newNode;
}

// �������� ����
void PrintGraph(Graph* graph)
{	
	for (int v = 0; v < graph->numVertices; v++)
	{
		Node* tmp = graph->adjList[v];
		printf("������ ��������� ������� %d\n ", v);
		while (tmp)
		{
			printf("%d ->", tmp->vertex);
			tmp = tmp->next;
		}
		printf("\n");
	}
}

// ����� ����� � �������
void DFS(Graph* graph, int vertex)
{
	Node* adjList = graph->adjList[vertex];
	Node* temp = adjList;

	graph->visited[vertex] = 1;
	printf("���������� ������� %d \n", vertex);

	while (temp != NULL)
	{
		int connectedVertex = temp->vertex;

		if (graph->visited[connectedVertex] == 0)
		{
			DFS(graph, connectedVertex);
		}
		temp = temp->next;
	}
}

// ������ ���� �� ������� ���������
void GetGraphFromMatrix(Graph* graph, int** matrix, int size)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			if (matrix[i][j] != 0)
				AddEdge(graph, i, j);
		}
}

// ������ �������
Queue* CreateQueue()
{
	Queue* q = (Queue*)malloc(sizeof(Queue));
	q->front = -1;
	q->rear = -1;
	return q;
}

// ��������� � �������
void Enqueue(Queue* q, int value)
{
	if (q->rear == SIZE - 1)
		printf("\n������� ���������!!!\n");
	else
	{
		if (q->front == -1)
			q->front = 0;
		q->rear++;
		q->items[q->rear] = value;
	}
}

// ����� �� �������
int Dequeue(Queue* q)
{
	int item;
	if (isEmpty(q))
	{
		printf("������� ������\n");
		item = -1;
	}
	else
	{
		item = q->items[q->front];
		q->front++;
		if (q->front > q->rear)
		{
			printf("����� �������\n");
			q->front = q->rear = -1;
		}
	}
	return item;
}

// ��������� �������
void DisplayQueue(Queue* q)
{

}

// �������� �� �������
int isEmpty(Queue* q)
{
	if (q->rear == -1)
		return 1;
	else
		return 0;
}

// ������ �������
void PrintQueue(Queue* q)
{
	int i = q->front;
	if (isEmpty(q))
	{
		printf("������� ������\n");
	}
	else
	{
		printf("\n������� ������� ��: \n");
		for (i = q->front; i < q->rear + 1; i++)
		{
			printf("%d ", q->items[i]);
		}
		printf("\n");
	}
}

// ����� ����� � ������
void BFS(Graph* graph, int startVertex)
{
	Queue* q = CreateQueue();

	graph->visited[startVertex] = 1;
	Enqueue(q, startVertex);

	while (!isEmpty(q))
	{
		PrintQueue(q);
		int currentVertex = Dequeue(q);
		printf("���������� �������: %d\n", currentVertex);

		Node* temp = graph->adjList[currentVertex];

		while (temp)
		{
			int adjVertex = temp->vertex;
			if (graph->visited[adjVertex] == 0)
			{
				graph->visited[adjVertex] = 1;
				Enqueue(q, adjVertex);
			}
			temp = temp->next;
		}
	}
}