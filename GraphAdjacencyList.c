// A C Program to demonstrate adjacency list representation of graphs
#include <stdio.h>
#include <malloc.h>
#include <conio.h>
// A structure to represent an adjacency list node
struct Node
{
	char data;
	struct Node* pNext;
};
// A structure to represent an adjacency list
struct List
{
	struct Node *pHead; // pointer to head node of list
};
// A structure to represent a graph. A graph is an array of adjacency lists.
// Size of array will be V (number of vertices in graph)
struct Graph
{
	int V;
	struct List* array;
};
// A utility function to create a new adjacency list node
struct Node* newListNode(char data)
{
	struct Node* newNode =(struct Node*) malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->pNext = NULL;
	return newNode;
}
// A utility function that creates a graph of V vertices
struct Graph* createGraph(int V)
{
	int i;
	struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
	if(graph)
	{
		graph->V = V;
		// Create an array of adjacency lists. Size of array will be V
		graph->array = (struct List*) malloc(V * sizeof(struct List));
		// Initialize each adjacency list as empty by making pHead as NULL
	for (i = 0; i < V; ++i)
		graph->array[i].pHead = NULL;
	}
	return graph;
}
// Adds an edge to an undirected graph
int addEdge(struct Graph* graph, int src, char data)
{
	int flag=0;
	// Add an edge from src to data. A new node is added to the adjacency
	// list of src. The node is added at the begining
	struct Node* newNode = newListNode(data);
	if(newNode)
	{
		flag=1;
		newNode->pNext = graph->array[src].pHead;
		graph->array[src].pHead = newNode;
		// Since graph is undirected, add an edge from data to src also
		newNode = newListNode(src);
		newNode->pNext = graph->array[data].pHead;
		graph->array[data].pHead = newNode;
	}
	return flag;
}
// A utility function to print the adjacenncy list representation of graph
void printGraph(struct Graph* graph)
{
	struct Node* pCurr;
	int i;
	for (i = 0; i < graph->V; i++)
	{
		pCurr = graph->array[i].pHead;
		printf("\nAdjacency list of vertex %c: head ", i+65);
		while (pCurr)
		{
			printf("-> %c", pCurr->data);
			pCurr = pCurr->pNext;
		}
		printf("\n");
	}
}
// Driver program to test above functions
int main()
{
	// create the graph given in above fugure
    int V = 4;
	struct Graph* graph = createGraph(V);
	printf("add B to A : %d\n",addEdge(graph, 0, 'B'));
	printf("add C to A : %d\n",addEdge(graph, 0, 'C'));
	printf("add D to B : %d\n",addEdge(graph, 1, 'D'));
	printf("add D to C : %d\n",addEdge(graph, 2, 'D'));
	// print the adjacency list representation of the above graph
	printf("\npress any key to print All\n");
	getch();
	printGraph(graph);
	getch();
	return 0;
}