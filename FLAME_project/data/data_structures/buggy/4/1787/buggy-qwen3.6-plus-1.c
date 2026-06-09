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
            for(int j=0;j<=k;j++)
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
for(int i=0;i<k;i++) // @@ The sorting algorithm is incorrect. It uses a mix of indices that doesn't implement a standard sort (like Bubble or Selection) correctly, leading to unsorted output. Specifically, comparing a[i] with a[j] where j goes up to k-1 while i is fixed in the outer loop is logically flawed for sorting.
{
    for(int j=0;j<k-1;j++)
    {
        if(strcmp(a[i].word1,a[j].word1)>0) // @@ The comparison logic and swap targets are incorrect for a standard sorting algorithm. This condition checks if a[i] is greater than a[j], but the swap involves a[i] and a[j] in a way that doesn't guarantee ordering. A standard bubble sort would compare adjacent elements a[j] and a[j+1].
        {
            temp=a[j];
            a[j]=a[i];
            a[i]=temp;
        }
    }
}
for(int i=0;i<k;i++)
{
    printf("%s %d",a[i].word1,a[i].count); // @@ The output format is missing a newline character '\n' at the end of each line, causing all output to be on a single line instead of one word per line.
}
return 0;
}