#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int N;
int vis[11];
int s[11];
int j,k;

void DFS(int h);

int main(){
    for (j = 0; j < N; j++)
    {
        vis[j] = 0;
    }
    scanf("%d",&N);
    DFS(0);
    return 0;
}

void DFS(int h){
    int i;
    if (h == N){
        for (i=0;i < N;i++){
            printf("%d ",s[i]);
        }
        printf("\n");
        return;
    }
    for (i = 0; i < N; i++)
    {
        if (vis[i]==0)
        {
            s[h] = i+1;
            vis[i] = 1;
            DFS(h+1);
            vis[i] = 0;
        }
    }
}


