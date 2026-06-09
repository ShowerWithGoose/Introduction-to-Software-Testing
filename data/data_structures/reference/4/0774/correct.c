#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define MAX 10000
int Min(int a,int b){return a<b?a:b;}
int Max(int a,int b){return a>b?a:b;}

struct Node{
    char c[30];
    int num;
} word[1000], sym;

int i, j, k, n, mark, len;
char a[1026];
int main()
{
    FILE *in;
	in = fopen("article.txt", "r");
    while(fgets(a,1025,in) != NULL)
    {
        len = strlen(a);
        for(k=0;k<len;k++)
        {
            if ((a[k] < 91 && a[k] > 64) || (a[k] > 96 && a[k] < 123))
            {
                word[i].c[j++] = a[k];
                mark = 1;
            }
            else if (mark != 0)
            {
                word[i].c[j] = '\0';
                word[i++].num = 1;
                j = mark = 0;
            }
        }
    }

    n=i;
    for(i=0;i<n;i++)
    {
        len = strlen(word[i].c);
        for (j=0;j<len;j++)
        {
            if (word[i].c[j] < 97)
                word[i].c[j] += 32;
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if (strcmp(word[i].c, word[j].c) == 0)
            {
                strcpy(word[j].c, "\0");
                word[i].num += word[j].num;
            }
            if (strcmp(word[i].c, word[j].c) > 0)
            {
                sym = word[i];
                word[i] = word[j];
                word[j] = sym;
            }
        }
    }

    for(i=0;i<n;i++)
    {
        if (strlen(word[i].c) != 0)
            printf("%s %d\n", word[i].c, word[i].num);
    }
    return 0;
}

