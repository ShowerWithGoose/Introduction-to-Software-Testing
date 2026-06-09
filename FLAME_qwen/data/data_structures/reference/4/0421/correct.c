#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
struct words
{
    char w[105];
    int times;
} word[505];
int cmp(const void *a,const void *b)
{
    struct words *c=(struct words*)a;
    struct words *d=(struct words*)b;
    return strcmp(c->w,d->w);
}
int main()
{
    char c,op[10005];
    int i,j=0,k=0,fl=0;
    FILE *fp=fopen("article.txt","r");
    while((c=fgetc(fp))!=EOF)
        op[k++]=c;
    for(i=0; i<k; i++)
    {
        if(isalpha(op[i])==0)
        {
            fl++;
            j=0;
        }
        else if(isalpha(op[i])) word[fl].w[j++]=tolower(op[i]);
    }
    qsort(word,fl,sizeof(word[0]),cmp);
    for(i=0; i<fl; i++)
        if(!strcmp(word[i].w,word[i+1].w))
        {
            word[i+1].times+=word[i].times+1;
            word[i].times=-1;
        }
    for(i=0; i<fl; i++)
        if(isalpha(word[i].w[0])&&word[i].times!=-1)
            printf("%s %d\n",word[i].w,word[i].times+1);
    return 0;
}

