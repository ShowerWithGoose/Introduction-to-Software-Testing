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
while(!feof(fp)) // @@ feof does not work as expected; may cause extra iteration or miss end-of-file. Use while((charac=fgetc(fp))!=EOF) instead.
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
            for(int j=0;j<=k;j++) // @@ Loop should be j<k, not j<=k, because a[k] is uninitialized; comparing against junk can cause undefined behavior.
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
for(int i=0;i<k;i++) // @@ Outer loop of sorting is incorrect; should use a standard bubble sort (e.g., for(i=0;i<k-1;i++) for(j=0;j<k-1-i;j++)).
{
    for(int j=0;j<k-1;j++) // @@ Inner loop should be j<k-1-i to avoid unnecessary comparisons.
    {
        if(strcmp(a[i].word1,a[j].word1)>0) // @@ Comparison and swap logic is flawed; it does not sort correctly. Should compare a[j] and a[j+1] for bubble sort.
        {
            temp=a[j];
            a[j]=a[i];
            a[i]=temp;
        }
    }
}
for(int i=0;i<k;i++)
{
    printf("%s %d",a[i].word1,a[i].count); // @@ Missing newline; output should be "word count\n" per line.
}
return 0;
}