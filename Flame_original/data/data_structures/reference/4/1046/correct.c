#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#define LL long long
#define max 128
#define true 1
int cmp3(const void *a,const void *b);
struct word
{
    char ch[10];
    int times;
}w[1000];
int main()
{
    int i,j,k,l,m,n;
    char ch[100];
    FILE *in;
    in=fopen("article.txt","r");
    k=0;
    j=0;
    while (fgets(ch,90,in)!=NULL)
    {
        for(i=0;ch[i]!='\0';i++)
        {
            if(ch[i]>='a'&&ch[i]<='z')
            {
                w[k].ch[j++]=ch[i];
            }
            else if (ch[i]>='A'&&ch[i]<='Z')
            {
                w[k].ch[j++]=ch[i]-'A'+'a';
            }
            if(((ch[i]>='a'&&ch[i]<='z')||(ch[i]>='A'&&ch[i]<='Z'))&&(ch[i+1]>'z'||ch[i+1]<'A'||(ch[i+1]<'a'&&ch[i+1]>'Z')))
            {
                k++;
                j=0;
            }
        }
    }
    m=k;
    for(i=0;i<m-1;i++)
    {
        if(w[i].times>=0)
        {
            for(j=i+1;j<m;j++)
            {
                if(strcmp(w[i].ch,w[j].ch)==0)
                {
                    w[i].times++;
                    w[j].times=-1;
                }
            }
        }
    }
    qsort(w,m,sizeof(w[0]),cmp3);
    for(i=0;i<m;i++)
    {
        if(w[i].times>=0)
            printf("%s %d\n",w[i].ch,w[i].times+1);
    }
    fclose(in);
    return 0;
}
int cmp3(const void *a,const void *b)
{
    struct word*aa=(struct word*)a;
    struct word*bb=(struct word*)b;
    return strcmp(aa->ch,bb->ch);
}
