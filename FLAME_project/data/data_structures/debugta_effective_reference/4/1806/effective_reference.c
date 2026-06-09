#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
int hashtable[100000000]={0};
int hashfunc(char s[], int len)
{
    int id=0;
    for(int i=0;i<len;i++)
    {
        id=id*26+(s[i]-'a');
    }
    return id%26;
}
struct Node{
    int num;
    char s[10000];
    int id;
    int flag;
}str[10000];
int cmp1(const struct Node *a,const struct Node *b)
{
    if((a->id)>(b->id)) return 1;
    else if((a->id)<(b->id)) return -1;
}
int cmp2(const struct Node *a,const struct Node *b)
{
    if(strcmp(a->s,b->s)>0) return 1;
    else if(strcmp(a->s,b->s)<0) return -1;
}
int main()
{
    int id;
    FILE *in,*out;
    in=fopen("article.txt","r");
    char c;
    char *p,*q;
    int i=0,j=-1,flag=0;
    while((c=fgetc(in))!=EOF)
    {
        if(isalpha(c))
        {
            str[i].s[++j]=tolower(c);
            flag=1;
        }
        if((isalpha(c)==0&&flag==1))
        {
            flag=0;
            i++;
            j=-1;
        }
    }
    int n=i;
    for(i=0;i<n;i++)
    {
        p=str[i].s;
        id=hashfunc(p,strlen(p));
        while(hashtable[id]!=0)
        {
            id++;
        }
        hashtable[id]=1;
        str[i].num=hashtable[id];
        str[i].id=id;
        str[i].flag=1;
    }
    qsort(str,n,sizeof(str[0]),cmp1);
    for(int k=0;k<n;k++)
    {
        if(str[k].flag==1){
        for(int m=k+1;m<n;m++)
        {
            if(str[m].flag==1)
            {
                if(strcmp(str[m].s,str[k].s)==0)
                {
                    str[m].flag=0;
                    str[k].num++;
                }
            }
        }
    }
    }
    qsort(str,n,sizeof(str[0]),cmp2);
    for(int k=0;k<n;k++)
    {
        if(str[k].flag==1)
        {
            printf("%s %d\n",str[k].s,str[k].num);
        }
    }
    fclose(in);
}

