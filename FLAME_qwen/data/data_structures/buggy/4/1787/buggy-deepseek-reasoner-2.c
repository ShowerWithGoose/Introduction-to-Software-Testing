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
            for(int j=0;j<=k;j++) // @@ In C89, variable declaration inside for loop is not allowed; declare j at the beginning of the block.
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
for(int i=0;i<k;i++) // @@ In C89, variable declaration inside for loop is not allowed; declare i at the beginning of the block.
{
    for(int j=0;j<k-1;j++) // @@ In C89, variable declaration inside for loop is not allowed; declare j at the beginning of the block.
    {
        if(strcmp(a[i].word1,a[j].word1)>0)
        {
            temp=a[j];
            a[j]=a[i];
            a[i]=temp;
        }
    }
}
for(int i=0;i<k;i++) // @@ In C89, variable declaration inside for loop is not allowed; declare i at the beginning of the block.
{
    printf("%s %d",a[i].word1,a[i].count);
}
return 0;
}