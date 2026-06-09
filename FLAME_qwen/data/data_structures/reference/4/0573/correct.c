#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>

struct list{
    char word[17];
    int num;
};

int main()
{
    FILE *fp;
    struct list wd[100];
    char ch[17];
    char c;
    fp=fopen("article.txt","r");
    c=fgetc(fp);
    int a=0,b=0;
    while(c!=EOF)
    {
        if(65<=c && c<=90) {c+=32;ch[a]=c;a++;}
        else if(97<=c && c<=122) {ch[a]=c;a++;}
        else if(a!=0)
        {
            strcpy(wd[b].word,ch);
            wd[b].num=1;
            b+=1;
            a=0;
            memset(ch,0,sizeof(ch));
        }
        c=fgetc(fp);
    }
    struct list ti;
    for(int i=0;i<b;i++)
    {
        for(int j=0;j<b;j++)
        {
            if(strcmp(wd[i].word,wd[j].word)<0)
            {
               ti=wd[i];
               wd[i]=wd[j];
               wd[j]=ti;
            }
        }
    }
    for(int i=b-1;i>0;i--)
    {
        if(strcmp(wd[i].word,wd[i-1].word)==0)
        {
            wd[i-1].num+=wd[i].num;
            wd[i].num=0;
        }
    }
    for(int i=0;i<b;i++)
    {
        if(wd[i].num==0) continue;
        printf("%s %d\n",wd[i].word,wd[i].num);
    }
    return 0;
}

