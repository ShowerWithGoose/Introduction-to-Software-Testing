#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
struct str{
    char c[200];
    int x;
}s[200];
int cmp(const void* p,const void* q)
{
    struct str*m=(struct str*)p;
    struct str*n=(struct str*)q;
    return strcmp(m->c,n->c);
}
int main()
{
    FILE *in;
    int i=0,j=0;
    in=fopen("article.txt","r");
    s[i].c[j]=fgetc(in);
    while(s[i].c[j]!=EOF)
    {
    if(isalpha(s[i].c[j])>0)
    {
        if(isupper(s[i].c[j]))
        s[i].c[j]+=32;
        j++;
        s[i].c[j]=fgetc(in);
    }
    else if(isalpha(s[i].c[j])==0)
    {
    if(isalpha(s[i].c[j])<=0&&isalpha(s[i].c[j-1])>0)
    {s[i].c[j]='\0';i++;j=0;}
    s[i].c[j]=fgetc(in);
    while(isalpha(s[i].c[j])<=0&&s[i].c[j]!=EOF)
    {
        s[i].c[j]=fgetc(in);
    }
    }
    }
    qsort(s,i,sizeof(struct str),cmp);
    j=0;
    while(j<i)
    {
        if(s[j].x==0)
        s[j].x=1;
        if(strcmp(s[j].c,s[j+1].c)==0)
        {
            s[j+1].x=s[j].x+1;
            s[j].x=0;
        }
        j++;
    }
    j=0;
    while(s[j].c[0]!='\0')
    {
        if(s[j].x!=0) printf("%s %d\n",s[j].c,s[j].x);
        j++;
    }
    fclose(in);
return 0;
}
