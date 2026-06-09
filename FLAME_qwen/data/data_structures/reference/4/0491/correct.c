#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int cmp(const void*a,const void*b);
struct word{
    char word[100];
    int cnt;
};
int cmp(const void*a,const void*b)
{
    struct word *p = (struct word*)a;
    struct word *q = (struct word*)b;
    return strcmp(p -> word, q -> word);
}
int main()
{
    struct word w[1000];
    FILE *fp = fopen("article.txt","r");
    char a[1000] = {0};
    char ch;
    ch = fgetc(fp);
    int i = 0, j = 0, k = 0, num = 0;
    while(ch != EOF)
    {
        a[i] = ch;
        i++;
        ch = fgetc(fp);
    }
    for(i = 0; i < strlen(a); i++)
    {
        if(a[i] >= 'A' && a[i] <= 'Z')
            a[i] = a[i] - 'A' + 'a';
    }
    for(i = 0; i < strlen(a); i++)
    {
        if(a[i] >= 'a' && a[i] <= 'z')
        {
            for(j = i + 1; j <strlen(a); j++)
            {
                if(a[j] >= 'a' && a[j] <= 'z')
                    continue;
                else
                    break;
            }
            for(k = 0; k < j - i; k++)
            {
                w[num].word[k] = a[i + k];
            }
            num++;
            i = j;
        }
        else
            continue;
    }
    qsort(w, num, sizeof(w[0]), cmp);
    for(i = 0; i < num; i++)
    {
        w[i].cnt = 1;
    }
    for(i = 0; i < num; i++)
    {
        if(strcmp(w[i].word, w[i + 1].word) == 0)
        {
            w[i + 1].cnt = w[i].cnt + w[i + 1].cnt;
            w[i].cnt = 0;
        }
    }
    for(i = 0; i < num; i++)
    {
        if(w[i].cnt == 0)
            continue;
        else
            printf("%s %d\n",w[i].word, w[i].cnt);
    }
    fclose(fp);
    return 0;
}

