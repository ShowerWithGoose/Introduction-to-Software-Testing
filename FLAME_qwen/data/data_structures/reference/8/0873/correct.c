#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include<assert.h> 

int map[110][110];
int DFS_visit[200];
int BFS_visit[200];
int num_point;
int num_line;

void DFS(int p) {
    int flag = 0;//not been visited
    if (flag == 0) {
        printf("%d ", p);
        flag = 1;
    }//be visited
    DFS_visit[p] = 1;
    int i;
    for ( i = 0; i < num_point; i++) {
        if (DFS_visit[i] == 0 && map[p][i] == 1)
            DFS(i);
    }
}
void BFS(int p) {
    int head = 0, t;
    int tail = 1;
    int q[200];
    q[head] = p;
    int i;
    while (head <= tail) {
        t = q[head];
        head++;
        if (BFS_visit[t] == 1)
			continue;
        else {
            printf("%d ", t);
            BFS_visit[t] = 1;
            for ( i = 0; i < num_point; i++) {
                if (map[t][i] && BFS_visit[i] == 0)
                    q[++tail]=i;
                   
            }

        }
    }

}
void print(){
	 DFS(0);
    printf("\n");
    BFS(0);
    printf("\n");
}
int main() {
    scanf("%d %d", &num_point, &num_line);
    int x, y;
    int i, j;
    memset(map, 0, sizeof(map));
    memset(DFS_visit, 0, sizeof(DFS_visit));
    memset(BFS_visit, 0, sizeof(BFS_visit));
    for (i = 0; i < num_line; i++) {
        scanf("%d %d", &x, &y);
        map[x][y] = 1;
        map[y][x] = 1;
    }
    int delet;
    scanf("%d", &delet);
    
    print();
    
    memset(DFS_visit, 0, sizeof(DFS_visit));
    memset(BFS_visit, 0, sizeof(BFS_visit));
    DFS_visit[delet]=1;
    BFS_visit[delet]=1;
    
    print();
    
    return 0;
}


