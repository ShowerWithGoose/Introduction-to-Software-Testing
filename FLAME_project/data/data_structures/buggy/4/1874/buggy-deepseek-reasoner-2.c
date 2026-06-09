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
    while(c=fgetc(in)!=EOF) // @@ Assignment and comparison operator precedence error: should be (c=fgetc(in))!=EOF, otherwise c is always 0 or 1, never the actual character.
    {
        if(isalpha(c)!=0)
        {
             str[i++]=tolower(c);
        }
        else
        {
            str[i]='\0'; // @@ Missing guard: before processing, should check if i>0 (i.e., a word was actually read) to avoid adding empty strings for consecutive delimiters.
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
                num++;
                strcpy(sheet[k].word,str); // @@ Missing count initialization: after copying the word, sheet[k].count should be set to 1; otherwise it holds garbage value.
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