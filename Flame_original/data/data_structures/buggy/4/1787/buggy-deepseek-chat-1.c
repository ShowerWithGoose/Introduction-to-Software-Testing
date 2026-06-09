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
            for(int j=0;j<=k;j++) // @@ The loop condition should be j < k, not j <= k, because a[k] is uninitialized and may cause undefined behavior when comparing strings.
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
    for(int j=0;j<k-1;j++)
    {
        if(strcmp(a[i].word1,a[j].word1)>0) // @@ The sorting logic is incorrect; it should compare a[j] and a[j+1] for bubble sort, not a[i] and a[j]. This will not sort the array correctly.
        {
            temp=a[j];
            a[j]=a[i];
            a[i]=temp;
        }
    }
}
for(int i=0;i<k;i++)
{
    printf("%s %d",a[i].word1,a[i].count); // @@ Missing newline character in printf; output should end with a newline after each line.
}
return 0;
}