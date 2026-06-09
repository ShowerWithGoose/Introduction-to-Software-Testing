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
            for(int j=0;j<=k;j++) // @@ The loop condition j<=k accesses a[k] which is uninitialized or out of bounds for existing elements (0 to k-1). It should be j<k. Also, logic error: if k=0, it checks a[0] which might be garbage if not yet filled properly in previous steps, but primarily the bound is wrong for checking existing k words.
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
        if(strcmp(a[i].word1,a[j].word1)>0) // @@ This sorting logic is incorrect. It compares a[i] with a[j] in a nested loop that doesn't implement a standard sort algorithm correctly (like bubble or selection). It mixes indices i and j improperly for swapping adjacent or specific elements. A standard bubble sort would compare a[j] and a[j+1]. A selection sort would find min/max. This current structure leads to undefined sorting behavior.
        {
            temp=a[j];
            a[j]=a[i];
            a[i]=temp;
        }
    }
}
for(int i=0;i<k;i++)
{
    printf("%s %d",a[i].word1,a[i].count); // @@ Missing newline character '\n' at the end of the format string. The expected output requires each word and count on a new line.
}
return 0;
}