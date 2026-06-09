#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
struct Node{
    char words[105];
    int repeat;
} List[100];
int cmp(const void * p1,const void * p2)
{
    struct Node * a=(struct Node * )p1;
    struct Node * b=(struct Node * )p2;
    return strcmp(a->words,b->words);
}

int cnt;
int  main()
{
    FILE * in,* out;
    in=fopen("article.txt","r");
    char article[100005] = {};
    int len = fread(article, 1, 100005, in);
    int i;
    for(i=0;i<len;i++)
    {
        if(isalpha(article[i]))
        {
            int j;
            for(j=i; isalpha(article[j]);j++)
            {
                article[j]= tolower(article[j]);
                List[cnt].words[j-i]=article[j];
            }
            i=j;
            cnt++;
        }
    }
    qsort(List,cnt,sizeof (struct Node),cmp);
    for (int i = 0; i < cnt; i++) {
        if(strcmp(List[i].words,List[i+1].words)==0)
        {
            List[i].repeat++;
            for(int j=i+1;j<cnt;j++)
            {
                List[j]=List[j+1];
            }
            cnt--;
            i--;
        }
    }
    for(int i=0;i<cnt;i++)
    {
        printf("%s %d\n",List[i].words,List[i].repeat+1);
    }
    return 0;
}

