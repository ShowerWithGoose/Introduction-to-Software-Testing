# include <stdio.h>
# include <math.h>
# include <string.h>
# include<stdlib.h>
#include <ctype.h>
typedef struct node{
    char s[251];
    int count;
}WORD;
WORD a[1024];
int num;
void changeword(char s[])
{
    int l=strlen(s),i;
    for(i=0;i<l;i++)
    {
        if(s[i]>='A'&&s[i]<='Z')
        {
            s[i]=s[i]+32;
        }
    } 
    s[i]='\0';
    for(i=0;i<num;i++)
    {
        if(strcmp(a[i].s,s)==0)
        {
            a[i].count++;
            break;
        }
    }
    if(i==num)
    {
        strcpy(a[num].s,s);
        a[num].count++;
        num++;
    }
}
int cmp(WORD *a,WORD *b)
{
    return strcmp(a->s,b->s);
}
int main()
{
    FILE *in;
    char s[251],c;
    int i=0;
    in=fopen("article.txt","r"); 
    while((c=fgetc(in))!=EOF)
    {
        if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
        {
            s[i++]=c;
        }
        else if(i==0) continue;
        else if(i>0) 
        {
            s[i]='\0';
            changeword(s);
            memset(s,0,sizeof(s));
            i=0;
        }
    }
    if(i>0)
    {
        s[i]='\0';
        changeword(s);
        memset(s,0,sizeof(s));
    }
    qsort(a,num,sizeof(WORD),cmp);
    for(int i=0;i<num;i++)
    {
        int l=strlen(a[i].s);
        for(int j=0;j<l;j++)
        {
            printf("%c",a[i].s[j]);
        }
        printf(" %d\n",a[i].count);
    }
    return 0;
}
