#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct node {
char z[1050];
int n;
}dc[2050];

int compar(const void* a, const void* b)
{
    struct node* c = (struct node*)a;
    struct node* d = (struct node*)b;
    return strcmp(c->z, d->z);
}

int main()
{

    char str[15000];
    char c;
    int l = 0;

    FILE* fp = fopen("article.txt", "r");

    while ((c = fgetc(fp)) != EOF) {
        str[l] = c;
        l++;
    }

    l = 0;
    int i=0, k = 0;
    for (i = 0; i < strlen(str); i++)
    {
         if (!isalpha(str[i])) //不是字母,可能下一个就是新单词
        {
            l++;
            k = 0;
        }
        else if(isalpha(str[i]))
        {
           dc[l].z[k++] = tolower(str[i]);
        }

    }


    qsort(dc, l, sizeof(dc[0]), compar);

    for (i = 0; i < l; i++)
        if(strlen(dc[i].z)!=0)
        {
           dc[i].n = 1; //考虑全面
        }

    for (i = 0; i < l; i++)
        if (strcmp(dc[i].z, dc[i + 1].z)==0)
        {
            dc[i + 1].n += dc[i].n;
            dc[i].n = 0;
        }


    for (i = 0; i < l; i++)
        if (dc[i].n != 0)
        {
            printf("%s %d\n", dc[i].z, dc[i].n);
        }

    return 0;
}

