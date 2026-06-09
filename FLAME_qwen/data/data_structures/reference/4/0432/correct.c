#include<stdio.h>
#include<string.h>
char s[100],*w;
struct word
    {
        char wordd[100];
        int num;

    };
int getword(FILE*fp,char*w)
{
    int c;
    while(!isalpha(c=fgetc(fp)))
        if(c==EOF) return c;
    else continue;
    do
    {
        *w++=tolower(c);
    }
    while(isalpha(c=fgetc(fp)));
    *w='\0';
    return 1;
}
int bj(char s[],struct word list[],int n);
int main()
{
    w=&s[0];
    int n=0,i=0,j,k;

    struct word list[100];
    FILE *in;
    in=fopen("article.txt","r");
    while(getword(in,w)!=-1)
    {
         k=bj(s,list,n);
       //  printf("%d",k);
          if(k==-1)
           {
               strcpy(list[n].wordd,s);
               list[n].num=1;
               n++;
           }
           else
           {
               list[k].num++;
           }
    }
     for(i=0;i<n-1;i++)
    {
      for(j=0;j<n-1-i;j++)
        if(strcmp(list[j].wordd,list[j+1].wordd)>0)
        {
            list[99]=list[j];
            list[j]=list[j+1];
            list[j+1]=list[99];
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%s %d\n",list[i].wordd,list[i].num);
    }
    fclose(in);
return 0;

}
int bj(char s[],struct word list[],int n)
{
    int i,j,k;
    for(i=0;i<n;i++)
    {
        if(strcmp(s,list[i].wordd)==0)
            return i;
    }
    return -1;

}

