#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 32

int getWord(FILE*fp,char*str)
{
char c;
int num=0;
while((c=fgetc(fp))!=EOF)
{
    if ((c>='a')&&(c<='z'))
    {
        str[num]=c;
        num++;

    }
    else if((c>='A')&&(c<='Z'))
    {
        str[num]=c-'A'+'a';
        num++;
    }
    else
    {   if(num>0)
       {
        break;
       }
       if(num<=0)
       {
           continue;
       }
    }
}
str[num]='\0';
if(num>=1)
{
    return 1;
}
if(num==0)
{
    return 0;
}
}

/*typedef struct line{
    char f[MAX];
    int num;
    struct line *next;
}Line;*/
//Line*head=NULL;
char c,p[10000][MAX],k[MAX];
int m[10000];
int main ()
{
FILE*in,*out;
int i,j,flag,max;
in=fopen("article.txt","r");
//Line *end,*q;
//q=(Line*)malloc(sizeof(Line));
//end=q=head;
i=0;
while(getWord(in,k)!=0)
{   flag=0;
    for(j=0;j<i;j++)
    {
        if(strcmp(k,p[j])==0)
        {
            m[j]++;
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        m[i]=1;
        strcpy(p[i],k);
        i++;
    }
}
max=i;

for(i=0;i<max;i++)
{   for(j=0;j<max-i-1;j++)
    {if(strcmp(p[j],p[j+1])>0)
    {
        strcpy(k,p[j]);
        strcpy(p[j],p[j+1]);
        strcpy(p[j+1],k);
        flag=m[j];
        m[j]=m[j+1];
        m[j+1]=flag;
    }
    }
}
for(i=0;i<max;i++)
{
    printf("%s %d\n",p[i],m[i]);
}
return 0;}



