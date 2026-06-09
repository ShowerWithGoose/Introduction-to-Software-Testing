#include <stdio.h>
#include<math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct node {
    char s[1024];
    int num;

}
h[2000];

int cmpfuc(const void* a, const void* b)
{
    struct node* c = (struct node*)a;
    struct node* d = (struct node*)b;
    return strcmp(c->s, d->s);
}
int main()
{
    FILE* fp = fopen("article.txt", "r");
    char str[14124];
    char c;
    int cnt = 0;
    while ((c = fgetc(fp)) != EOF) {
        str[cnt++] = c;                 //¶ÁÈëËùÓĞ×Ö·û
    }

    cnt = 0;
    int k = 0;
    for (int i = 0; i < strlen(str); i++)
    {
         if (!isalpha(str[i]))
        {
            cnt++;
            k = 0;                      }
        else if(isalpha(str[i])) h[cnt].s[k++] = tolower(str[i]);
    }


    qsort(h, cnt, sizeof(h[0]), cmpfuc);

    for (int i = 0; i < cnt; i++)
        if(strlen(h[i].s)) h[i].num = 1;
    for (int i = 0; i < cnt; i++)
        if (!strcmp(h[i].s, h[i + 1].s))
        {
            h[i + 1].num += h[i].num;
            h[i].num = 0;
        }
    for (int i = 0; i < cnt; i++)
        if (h[i].num != 0)
            printf("%s %d\n", h[i].s, h[i].num);
    return 0;
}

