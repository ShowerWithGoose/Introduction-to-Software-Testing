/*
 * @Author:
 * @Date: 2022-03-24 20:39:04
 * @LastEditors:
 * @LastEditTime: 2022-03-24 20:54:17
 * @FilePath: article.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAXN 100010

int tot = 0;
int Tree[MAXN][30];
int vis[MAXN];
char S[MAXN],T[MAXN],ret[MAXN];
FILE *in;

void insert(char s[])
{
    int p = 0;
    if(s[0] == '\0') return;
    for(int i=0;s[i] != '\0';++i)
    {
        int c = s[i] - 'a';
        if(!Tree[p][c]) Tree[p][c] = ++tot;
        p = Tree[p][c];
    }
    ++vis[p];
    return;
}

char tran(char c)
{
    if('A' <= c && c <= 'Z') return c - 'A' + 'a';
    return c;
}

void dfs(int x, int n, char c)
{
    ret[n] = c;
    if(vis[x])
    {
        for(int i=1;i<=n;++i) putchar(ret[i]);
        printf(" %d\n",vis[x]);
    }
    for(int i=0;i<26;++i)
        if(Tree[x][i])
            dfs(Tree[x][i], n+1, i+'a');
    return;
}

int main()
{
    in = fopen("article.txt","r");
    while (fgets(S,MAXN,in) != NULL)
    {
        int len = -1;
        for(int i=0;S[i] != '\0';++i)
        {
            
            S[i] = tran(S[i]);
            if('a' <= S[i] && S[i] <= 'z')
                T[++len] = S[i];
            else
            {
                insert(T);
                memset(T,0,sizeof(T));
                len = -1;
            }
        }
        insert(T);
        memset(T,0,sizeof(T));
    }
    dfs(0,0,' ');
    return 0;
}


