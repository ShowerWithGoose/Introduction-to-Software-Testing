#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct word
{
    char s[100];
    int num;
}list[100];
char line[100];
int compare(const void*a,const void*b)
{
    struct word *p=(struct word*)a,*q=(struct word *)b;
    return strcmp(p->s,q->s);
}
int main()
{
    FILE *in;
    char temp[100];
    int i,n=0,k=0,u;
    in=fopen("article.txt","r");
    while (fgets(line,99,in)!=NULL)
    {
        for(i=0;line[i]!='\0';i++)
        {
            if(line[i]>='A'&&line[i]<='Z')
            {
                temp[k++]=line[i]-('A'-'a');
                continue;
            }
            if(line[i]>='a'&&line[i]<='z')
            {
                temp[k++]=line[i];
                continue;
            }
            if(line[i]<='A'||line[i]>='Z')
            {
                temp[k]='\0';
                k=0;
                if(temp[0]>='a'&&temp[0]<='z')
                for(u=0;u<=n;u++)
                {
                    if(u==n)
                    {
                        strcpy(list[u].s,temp);
                        list[u].num=1;
                        n++;
                        break;
                    }
                    if(strcmp(temp,list[u].s)==0)
                    {
                        list[u].num++;
                        break;
                    }
                }
            }
        }
    }
    qsort(list,n,sizeof(list[0]),compare);
    for(i=0;i<n;i++)
    {
        printf("%s %d\n",list[i].s,list[i].num);
    }
    return 0;
}

