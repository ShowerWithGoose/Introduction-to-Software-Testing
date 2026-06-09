#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int a, b, str[102][102], temp[102], tempp[102], flag;

int jiaohuan(int x,int y,int str[102][102])
{
	str[x][y] = 1;
    str[y][x] = 1;
    
}
print()
{
	printf("\n");
}
fuling(int k,int temp[102],int flag)
{
	temp[k] = 0;
        flag = 0;
}
void Dfs(int p)
{
    if (flag == 0)
    {
        printf("%d", p);
        flag = 1;
    }
    else
    {
        printf(" %d", p);
    }
    temp[p] = 1;
    for (int i = 1; i <= a; i++)
    {
        if (str[p][i] == 1 && temp[i] == 0)
        {
            Dfs(i);
        }
    }
}

void Bfs(int p)
{
    int t;
    tempp[1] = p;
    for (int j = 1, r = 1; j <= r;)
    {
        t = tempp[j++];
        if (temp[t] == 1)
        {
            continue;
        }
        if (flag == 0)
        {
            printf("%d", t);
            flag = 1;
        }
        else
        {
            printf(" %d", t);
        }

        temp[t] = 1;
        for (int i = 1; i <= a; i++)
        {
            if (str[t][i] == 1 && temp[i] == 0)
            {
                tempp[++r] = i;
            }
        }
    }
}
int main()
{
    int x, y;
    scanf("%d%d", &a, &b);
    for (int i = 1; i <= b; i++)
    {
        scanf("%d%d", &x, &y);
        jiaohuan(x,y,str);
        
        
    }
    Dfs(0);
    print();
    for (int k = 0; k < 102; k++)
    {
        fuling(k,temp,flag);
    }
    Bfs(0);
    print();
    for (int k = 0; k < 102; k++)
    {
        fuling(k,temp,flag);
    }
    scanf("%d",&x);
    temp[x] = 1;
    Dfs(0);
    printf("\n");
    for (int k = 0; k < 102; k++)
    {
        fuling(k,temp,flag);
    }
    temp[x] = 1;
    Bfs(0);
    printf("\n");
    for (int k = 0; k < 102; k++)
    {
        fuling(k,temp,flag);
    }
}




