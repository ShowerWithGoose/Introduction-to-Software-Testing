#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char s[100];
    int num;
}a[1000];
char op[1024];
int cmp(const void *qq_,const void *pp_)
{
    struct node qq=*(struct node *)qq_;
    struct node pp=*(struct node *)pp_;
    return strcmp(qq.s,pp.s);
}
int main()
{
    FILE *in;
    in=fopen("article.txt","r");
    int n=0;
    while (fgets(op,1023,in)!=NULL)
    {
        int i,j=0,flot=0;
        for(i=0;op[i]!='\0';i++)
        {
            if(isalpha(op[i]))
            {
                a[n].s[j]=tolower(op[i]);
                j++;
                flot=1;
            }
            else if(flot)
            {
                a[n].s[j]='\0';
                n++;
                j=0;
                flot=0;
            }
        }
    }
    qsort(a,n,sizeof(a[0]),cmp);
    int i,j;
    for(i=0;i<n;i++)
    {
        j=i+1;
        a[i].num=1;
        if(j>=n)
        {
            break;
        }
        while(j<n&&strcmp(a[i].s,a[j].s)==0)
        {
            a[i].num++;
            j++;
        }
        if(j>=n)
        {
            break;
        }
        i=j;
        i--;
    }
    for(i=0;i<n;i++)
    {
        if(a[i].num!=0)
        {
            printf("%s %d\n",a[i].s,a[i].num);
        }
    }
    return 0;
}


