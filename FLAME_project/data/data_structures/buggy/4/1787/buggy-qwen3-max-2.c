#include<stdio.h>
#include<ctype.h>
#include<string.h>
struct word{
  char word1[100];
  int count;
  }a[1000],temp;
int main()
{
FILE* fp;
int i=0,k=0,flag=0;
char charac,words[25];
fp=fopen("article.txt","r");
while(!feof(fp))
{
    charac=fgetc(fp);
    if(isalpha(charac))
    {
        charac=tolower(charac);
        words[i]=charac;
        i++;
    }
    else
    {
        words[i]='\0';
        if(words[0]!='\0')
        {
            for(int j=0;j<=k;j++) // @@ [Loop condition should be j < k, not j <= k, because a[k] is uninitialized when j == k]
            {
                if(strcmp(a[j].word1,words)==0)
                {
                    a[j].count++;
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                a[k].count=1;
                strcpy(a[k].word1,words);
                k++;
            }
            flag=0;
            i=0;
        }
        else
        {
            i=0;
        }
    }
}
for(int i=0;i<k;i++)
{
    for(int j=0;j<k-1;j++) // @@ [Incorrect bubble sort implementation: inner loop should depend on outer loop index and compare adjacent elements a[j] and a[j+1]]
    {
        if(strcmp(a[i].word1,a[j].word1)>0) // @@ [Wrong comparison: should compare a[j] and a[j+1], not a[i] and a[j]]
        {
            temp=a[j];
            a[j]=a[i];
            a[i]=temp;
        }
    }
}
for(int i=0;i<k;i++)
{
    printf("%s %d",a[i].word1,a[i].count); // @@ [Missing newline character '\n' at the end of each output line]
}
return 0;
}