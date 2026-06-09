//
//  main.c
//  text  2
//
//  Created by  on 2021/11/5.
//
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<string.h>
int a[100], book[100], n;
void pri(int m[]){
    int i;
    for (i = 1; i <= n; i++)
    {
        printf("%d ", m[i]);
    }
    printf("\n");
}

void dfs(int step)
{
    int i;
    if (step == n + 1)
    {pri(a);
       
        return;
    }
    for (i = 1; i <= n; i++)
    {
        if (book[i] == 0)
        {
            a[step] = i;
            book[i] = 1;
            dfs(step + 1);
            book[i] = 0;
        }
    }
    return;
}

int main()
{
    scanf("%d", &n);
    dfs(1);
   
}

