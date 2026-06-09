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
char charac,words[25]; @@ `charac` should be declared as `int` to correctly store the return value of `fgetc()` (including `EOF`) and prevent undefined behavior when passed to `isalpha()`.
fp=fopen("article.txt","r");
while(!feof(fp)) @@ `feof()` should not be used as a loop condition; it only returns true after a failed read attempt. The loop should check the return value of `fgetc()` directly.
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
            for(int j=0;j<=k;j++) @@ Loop bound should be `j<k` to avoid accessing uninitialized array elements and performing redundant comparisons.
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
    for(int j=0;j<k-1;j++) @@ Incorrect sorting loop bounds. Should be `for(int j=i+1;j<k;j++)` to properly implement selection sort for lexicographical ordering.
    {
        if(strcmp(a[i].word1,a[j].word1)>0) @@ Comparison logic is flawed due to incorrect loop indices; should compare `a[i]` with `a[j]` where `j` starts from `i+1`.
        {
            temp=a[j];
            a[j]=a[i];
            a[i]=temp;
        }
    }
}
for(int i=0;i<k;i++)
{
    printf("%s %d",a[i].word1,a[i].count); @@ Missing newline character `\n` at the end of the format string, violating the output format requirement of one word per line.
}
return 0;
}