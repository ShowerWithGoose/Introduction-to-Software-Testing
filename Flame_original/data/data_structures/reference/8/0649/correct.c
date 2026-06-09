#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<stdbool.h>
#define MAXA 101
#define MAXB 101
#define max(a, b) ((a) > (b)) ?  (a) : (b)
int v, edge;
bool flag;
int string[102][102];
int sTmp[102], s2Tmp[102];
void graphDfs(int tar)
{
    if (!flag)
    {
        printf("%d", tar);
        flag = true;
    }
    else
    {
        printf(" %d", tar);
    }
    sTmp[tar] = 1;
    for (int i = 1; i <= v; i++)
    {
        if (string[tar][i] == 1 && sTmp[i] == 0)
        {
            graphDfs(i);
        }
    }
}
void graphBfs(int tar)
{
    int tmp;
    s2Tmp[1] = tar;
    for (int j = 1, r = 1; j <= r;)
    {
        tmp = s2Tmp[j++];
        if (sTmp[tmp] == 1)
        {
            continue;
        }
        if (!flag)
        {
            printf("%d", tmp);
            flag = true;
        }
        else
        {
            printf(" %d", tmp);
        }

        sTmp[tmp] = 1;
        for (int i = 1; i <= v; i++)
        {
            if (string[tmp][i] == 1 && sTmp[i] == 0)
            {
                s2Tmp[++r] = i;
            }
        }
    }
}
void adjust(int a,int b)
{
	for (int i = 0; i <= a; i++)
	{
		for (int j = 0; j <= b; j++)
		{
			int tmp = string[i][j];
			string[i][j] = max(a , b);
			string[i][j] = tmp;
		}
	}
}
int main(void)
{
    int first, second;
    scanf("%d%d", &v, &edge);
    for (int i = 1; i <= edge; i++) //建立邻接表
    {
        scanf("%d%d", &first, &second);
		string[second][first] = 1;
        string[first][second] = 1;
    }
    graphDfs(0);
	adjust(MAXA, MAXB);
    puts("");
    for (int i = 0; i <= 101; i++)
    {        
		flag = false;
        sTmp[i] = 0;
    }
    graphBfs(0);
	adjust(MAXA, MAXB);
    puts("");
    for (int i = 0; i <= 101; i++)
    {
		flag = false;
        sTmp[i] = 0;  
    }
    scanf("%d",&first);
    sTmp[first] = 1;
    graphDfs(0);
	adjust(MAXA, MAXB);
    puts("");
    for (int i = 0; i <= 101; i++)
    {    
		flag = false;
        sTmp[i] = 0;
   
    }
    sTmp[first] = 1;
    graphBfs(0);
	adjust(MAXA, MAXB);
    puts("");
    for (int i = 0; i <= 101; i++)
    {
		flag = false;
        sTmp[i] = 0;
    }
	adjust(MAXA, MAXB);
	return 0;
}




