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
            for(int j=0;j<=k;j++) // @@ [Loop condition should be j < k, not j <= k, because valid indices are 0 to k-1; accessing a[k] is out-of-bounds]
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
    for(int j=0;j<k-1;j++) // @@ [Incorrect bubble sort implementation: inner loop should compare adjacent elements (j and j+1), and outer loop index should control passes; current logic compares fixed i with varying j leading to wrong ordering]
    {
        if(strcmp(a[i].word1,a[j].word1)>0) // @@ [Comparison uses wrong indices: should compare a[j] and a[j+1], not a[i] and a[j]]
        {
            temp=a[j];
            a[j]=a[i];
            a[i]=temp;
        }
    }
}
for(int i=0;i<k;i++)
{
    printf("%s %d",a[i].word1,a[i].count); // @@ [Missing newline character '\n' at end of each output line as required by problem specification]
}
return 0;
}