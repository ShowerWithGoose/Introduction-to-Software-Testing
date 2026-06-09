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
char charac,words[25]; @@ `charac` should be declared as `int` to correctly store the `EOF` value returned by `fgetc()`, preventing potential infinite loops or undefined behavior when checking `isalpha()`.
fp=fopen("article.txt","r");
while(!feof(fp)) @@ Using `feof()` to control the loop is incorrect as it only returns true after a failed read; the loop will process `EOF` as a valid character once, leading to incorrect output.
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
            for(int j=0;j<=k;j++) @@ Loop bound should be `j<k` to avoid accessing uninitialized array elements at index `k`, which can cause incorrect string comparisons or out-of-bounds access.
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
    for(int j=0;j<k-1;j++) @@ The inner loop bounds and comparison logic are incorrect for sorting; it should iterate from `j=i+1` to `k` to properly implement a selection sort for lexicographical order.
    {
        if(strcmp(a[i].word1,a[j].word1)>0)
        {
            temp=a[j];
            a[j]=a[i];
            a[i]=temp;
        }
    }
}
for(int i=0;i<k;i++)
{
    printf("%s %d",a[i].word1,a[i].count); @@ Missing newline character `\n` at the end of the format string, which violates the requirement that each word and count should be printed on a separate line.
}
return 0;
}