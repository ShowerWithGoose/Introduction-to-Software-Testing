#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ver[200][200] , vis[200] = {0} , n , m , que[200];

void DFS (int a) {
	int i;
	printf("%d " , a);
	vis[a] = 1;
	for(i = 0; i < n; i++)
		if (ver[a][i] == 1 && vis[i] == 0)
			DFS(i);
}

void BFS (int a) {
	int i , head = 0 , tail = 1 , b;
	que[head] = a;
	while(head <= tail)
	{
		b = que[head];
		head++;
		if (vis[b] == 1)	continue;
		else {
			printf ("%d " , b);
			vis[b] = 1;
			for (i = 0 ; i < n ; i++)
				if (ver[b][i] == 1 && vis[i] == 0)
					que[tail++] = i;
		}
	}
}
int main()
{	
	int x , y , i , del;
	scanf ("%d %d " , &n , &m);
	for (i = 0 ; i < m ; i++) {
		scanf("%d %d " , &x , &y);
		ver[x][y] = 1;
		ver[y][x] = 1;
	}
	DFS (0);
    printf ("\n");
    for (i = 0 ; i < 200 ; i++)
        vis[i] = 0;
	BFS (0);
    printf ("\n");
	scanf ("%d" , &del);
	for (i = 0 ; i < 200 ; i++) {
        vis[i] = 0;
        que[i] = 0;
    }
	vis[del] = 1;
	DFS (0);
    printf ("\n");
	for (i = 0 ; i < 200 ; i++)
        vis[i] = 0;
	vis[del] = 1;
	BFS (0);
    printf ("\n");
	return 0;
}

