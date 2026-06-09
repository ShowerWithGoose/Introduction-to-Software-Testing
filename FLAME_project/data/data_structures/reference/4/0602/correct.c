#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct sent
{
    char a[1005];
    int num;
}word[2005];
int sort(void *a,void *b)
{
    struct sent *c=(struct sent*)a;
    struct sent *d=(struct sent*)b;
    return strcmp(c->a,d->a);
}
void bubbleSort(struct sent word[],int n)
{
    int i,j,flag,on;
    char hold[1005]="\0";
    for(i=0;i<n-1;i++)
    {
        flag=0;
        for(j=0;j<n-1-i;j++)
        {
            if(strcmp(word[j].a,word[j+1].a)>0)
            {
                strcpy(hold,word[j].a);
                on=word[j].num;
                strcpy(word[j].a,word[j+1].a);
                word[j].num=word[j+1].num;
                strcpy(word[j+1].a,hold);
                word[j+1].num=on;
                flag=1;
            }
        }
        if(flag==0)
            break;
    }
}
int main()
{
    FILE *in=fopen("article.txt","r");
    char text[10005],x;
    int count=0,i,j,k,m=0,textlength;
    for(i=0;(x=fgetc(in))!=EOF;i++)
    {
        text[i]=x;
    }
    textlength=strlen(text);
    for(i=0;i<textlength;i++)
    {
        if(!isalpha(text[i]))
        {
            count++;
            m=0;
        }
        else if(isalpha(text[i]))
        {
            word[count].a[m++]=tolower(text[i]);
        }
    }
    bubbleSort(word,count);
    for(i=0;i<count;i++)
    {
        if(strlen(word[i].a)!=0)
        {
            word[i].num=1;
        }
    }
    for(i=0;i<count;i++)
    {
            if(strcmp(word[i].a,word[i+1].a)==0)
            {
                word[i+1].num+=word[i].num;
                word[i].num=0;
            }
    }
    for(i=0;i<count;i++)
    {
        if(word[i].num!=0)
        {
            printf("%s %d\n",word[i].a,word[i].num);
        }
    }
return 0;
}

