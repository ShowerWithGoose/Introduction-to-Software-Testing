#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct node
{
    char word[50];
    int count;
};
struct node sheet[300];

void sort(struct node sheet[],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(strcmp(sheet[j].word,sheet[j+1].word)>0)
            {
                struct node tmp=sheet[j];
                sheet[j]=sheet[j+1];
                sheet[j+1]=tmp;
            }    
        }
    }
}

int main()
{
    FILE *in;
    in=fopen("article.txt","r");
    int i=0,c,num=0;
    char str[50];
    while((c=fgetc(in))!=EOF) // @@ The original code `c=fgetc(in)!=EOF` assigns the boolean result of the comparison (0 or 1) to c, due to operator precedence. It should be `(c=fgetc(in))!=EOF`.
    {
        if(isalpha(c)!=0)
        {
             str[i++]=tolower(c);
        }
        else
        {
            if(i > 0) // @@ Added check to ensure we only process if a word was actually accumulated. If consecutive non-alpha chars appear, i is 0, str is empty, and we shouldn't process an empty string as a word.
            {
                str[i]='\0';
                i=0;
                int k;
                for(k=0;k<num;k++)
                {
                    if(strcmp(sheet[k].word,str)==0)
                    {
                        break;
                    }
                }
                if(k<num)
                {
                    sheet[k].count++;
                }
                else if(k==num)
                {
                    strcpy(sheet[k].word,str); // @@ Moved strcpy before incrementing num or just use k. The logic `else if(k==num)` implies k is the new index.
                    sheet[k].count = 1; // @@ Initialize count to 1 for the new word. The original code missed initializing count, leading to garbage values.
                    num++;
                }
            }
            else 
            {
                 i=0; // @@ Reset i even if no word was formed (e.g. multiple spaces)
            }
        }
    }
    
    sort(sheet,num);
    int j;
    for(j=0;j<num;j++)
    {
        printf("%s %d\n",sheet[j].word,sheet[j].count);
    }
    fclose(in);
    return 0;
}