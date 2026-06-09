#include<stdio.h>
#include<stdlib.h>
int graph[100][100];
int p[100] = {0};
int a, b;

void f(int v)
{
    p[v] = 1;
    printf("%d ", v);
    for(int i=0;i<a;i++)
    {
        if(graph[v][i] && !p[i])
            f(i);
    }
}

void g(int v)
{
    int queue[100];
    int first=-1, rear=-1;
    queue[rear+1] = v;
    rear++;
    p[v] = 1;
    while(first < rear)
    {
        int x = queue[++first];
        printf("%d ", x);
        for(int i=0;i<a;i++)
        {
            if(graph[x][i] && !p[i])
            {
                queue[++rear] = i;
                p[i] = 1;
            }
        }
    }
}

int main()
{
    
    scanf("%d%d", &a, &b);
    for(int i=0;i<a;i++)
        for(int j=0;j<a;j++)
            graph[i][j] = 0;
    for(int i=0;i<b;i++)
    {
        int v1, v2;
        scanf("%d%d", &v1, &v2);
        graph[v1][v2] = graph[v2][v1] = 1;
    }
    f(0); 
	printf("\n"); 
	for(int i=0;i<100;i++) p[i] = 0;
    g(0); 
	printf("\n"); 
	for(int i=0;i<100;i++) p[i] = 0;

    int v;
    scanf("%d", &v);
    for(int i=0;i<a;i++)
        graph[i][v] = graph[v][i] = 0;
    f(0); 
	printf("\n"); 
	for(int i=0;i<100;i++) p[i] = 0;
    g(0); 
	printf("\n"); 
	for(int i=0;i<100;i++) p[i] = 0;
    return 0;
}

