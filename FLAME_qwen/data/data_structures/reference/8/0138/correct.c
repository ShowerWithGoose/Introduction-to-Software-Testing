/*
 *                        _oo0oo_
 *                       o8888888o
 *                       88" . "88
 *                       (| -_- |)
 *                       0\  =  /0
 *                     ___/`---'\___
 *                   .' \\|     |// '.
 *                  / \\|||  :  |||// \
 *                 / _||||| -:- |||||- \
 *                |   | \\\  - /// |   |
 *                | \_|  ''\---/''  |_/ |
 *                \  .-\__  '-'  ___/-. /
 *              ___'. .'  /--.--\  `. .'___
 *           ."" '<  `.___\_<|>_/___.' >' "".
 *          | | :  `- \`.;`\ _ /`;.`/ - ` : | |
 *          \  \ `_.   \_ __\ /__ _/   .-` /  /
 *      =====`-.____`.___ \_____/___.-`___.-'=====
 *                        `=---='
 * 
 * 
 *      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * 
 *            佛祖保佑       永不宕机     永无BUG
 */

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int a, b, str[102][102], temp[102], tempp[102], flag;
void Dfs(int p);
void Bfs(int p);

int main()
{
    int x, y;
    scanf("%d%d", &a, &b);
    for (int i = 1; i <= b; i++) //建立邻接表
    {
        scanf("%d%d", &x, &y);
        str[x][y] = 1;
        str[y][x] = 1;
    }
    Dfs(0);
    printf("\n");
    for (int k = 0; k < 102; k++)
    {
        temp[k] = 0;
        flag = 0;
    }
    Bfs(0);
    printf("\n");
    for (int k = 0; k < 102; k++)
    {
        temp[k] = 0;
        flag = 0;
    }
    scanf("%d",&x);
    temp[x] = 1;
    Dfs(0);
    printf("\n");
    for (int k = 0; k < 102; k++)
    {
        temp[k] = 0;
        flag = 0;
    }
    temp[x] = 1;
    Bfs(0);
    printf("\n");
    for (int k = 0; k < 102; k++)
    {
        temp[k] = 0;
        flag = 0;
    }
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


