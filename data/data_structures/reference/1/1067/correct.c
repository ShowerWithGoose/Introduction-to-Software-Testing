#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#define MAXN 100000 
bool vis[11];
int a[11];
void FullArray(int N, int now)//N can be an external variable
{
    if(now == N + 1)
    {
        for(int j = 1; j <= N; j ++)
            printf("%d ", a[j]);
        puts("");
        return;
    }
    for(int i = 1; i <= N; i++)
        if(!vis[i])
        {
            vis[i] = 1;
            a[now] = i;
            FullArray(N, now + 1);
            vis[i] = 0;
        }
}
int main()
{
    int N;
    scanf("%d", &N);
    FullArray(N, 1);
    return 0;
}
