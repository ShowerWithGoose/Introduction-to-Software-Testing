#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char str[1000][20];
char s[1000][20];
struct std{
    char word[20];
    int count;
};
int num=0;
int x=0;
struct std string[1000];
void change(char a[],char b[][20])
{
    int n= strlen(a);
    int i,j;
    for(i=0,j=0;i<n;i++)
    {
        if(a[i]<='Z'&&a[i]>='A')
            b[x][j]=a[i]-'A'+'a',j++;
        else if(a[i]<='z'&&a[i]>='a')
            b[x][j]=a[i],j++;
        else if((j>0)&&((a[i]<'a'&&a[i]>'Z')||a[i]<'A'||a[i]>'z'))
            {
            b[x][j]='\0';x++;j=0;
            }
    }
    b[x][j]='\0';
    
}
int comp(const void *p1,const void *p2)
{
    return   strcmp((*(struct std*)p1).word,(*(struct std*)p2).word);
}

int main() {
    int i=0;
    FILE *in;
    in= fopen("article.txt","r");

    while(fscanf(in,"%s",str[i])!=EOF)
    {
        i++;
    }
    int sum=i;
    for(i=0;i<sum;i++,x++)
    {
        change(str[i],s);
    }
    num=x;
    for(i=0;i<x;i++) string[i].count=0;
    int j,k,flag=0;
    for(i=0,j=0;j<num;j++)
    {
        for(k=0;k<i;k++)
        {
            if(strcmp(string[k].word,s[j])==0) 
            {
            flag=1,string[k].count++;
            break;
            }
        }
        if(flag==0) strcpy(string[i].word,s[j]),string[i++].count=1;
        flag=0;
    }
    x=i;
    qsort(string,x,sizeof(string[0]),comp);
    for(i=0;i<x;i++)
    {
        if(string[i].word[0]!='\0'&&string[i].count!=0) printf("%s %d\n",string[i].word,string[i].count);
    }
    fclose(in);
    return 0;
}




