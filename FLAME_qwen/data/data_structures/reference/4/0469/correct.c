#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
FILE *in;
struct hello
{
    char ch[100];
    int num;
} c[1000],d;
char a[1050];

void ftolower(struct hello c[1000],int n)
{
    int i,j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<strlen(c[i].ch); j++)
        {
            if(c[i].ch[j]>='A'&&c[i].ch[j]<='Z')
            {
                c[i].ch[j]+=32;
            }
        }
    }
}
void repeat(struct hello c[1000],struct hello d,int n)
{
    int i,j;
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(strcmp(c[i].ch,c[j].ch)==0)
            {
                strcpy(c[j].ch,"\0");
                c[i].num+=c[j].num;
            }
            if(strcmp(c[i].ch,c[j].ch)>0)
            {
                d=c[i];
                c[i]=c[j];
                c[j]=d;
            }
        }
    }
}
int main()
{
    int i=0,j=0,k;
    int flag=0;
    int sum;
    in=fopen("article.txt","r");
    while(fgets(a,500,in)!=NULL)
    {
        for(k=0; k<strlen(a); k++)
        {

            if((a[k]<='z'&&a[k]>='a')||(a[k]>='A'&&a[k]<='Z'))
            {
                c[i].ch[j++]=a[k];
                flag=1;
            }
            else if(flag==1)
            {
                c[i].ch[j]='\0';
                c[i].num=1;
                i++;
                j=flag=0;
            }
        }
    }
    sum=i;
    ftolower(c,sum);
    repeat(c,d,sum);
    for(i=0; i<sum; i++)
    {
        if(strlen(c[i].ch)!=0)
            printf("%s %d\n",c[i].ch,c[i].num);
    }
    return 0;
}

