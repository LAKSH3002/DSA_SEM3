/* Adjacency Matrix representation of an undirected graph in C */

#include <stdio.h>
#define V 4 /* number of vertices in the graph */

/* function to initialize the matrix to zero */
void init(int arr[][4])
{
    int i, j;
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            arr[i][j] = 0;
}

/* function to add edges to the graph */
void insertEdge(int arr[][4])
{
    int edges;
    printf("ENTER THE NUMBER OF EDGES YOUR GRAPH HAS\n");
    scanf("%d",&edges);
    int i,j, a, b;
    for (i = 0; i <= edges; i++)
    {
        printf("ENTER THE VERTEX A AND B THAT ARE CONNECTED TO EACH OTHER AND FORM AN EDGE\n");
        printf("ENTER VERTEX A\n");
        scanf("%d", &a);
        printf("ENTER VERTEX B\n");
        scanf("%d", &b);
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
}

/* function to print the matrix elements */
void printAdjMatrix(int arr[][4])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        printf("%d: ", i);
        for (j = 0; j < 4; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int adjMatrix[4][4];

    int a, b;
    init(adjMatrix);
    printAdjMatrix(adjMatrix);
    insertEdge(adjMatrix);
    printAdjMatrix(adjMatrix);
    return 0;
}