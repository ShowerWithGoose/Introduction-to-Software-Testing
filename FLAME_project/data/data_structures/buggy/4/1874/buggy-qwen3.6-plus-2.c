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
    while((c=fgetc(in))!=EOF) // @@ [Operator precedence error: != has higher precedence than =, so c was assigned the boolean result (0 or 1) instead of the character. Added parentheses to fix.]
    {
        if(isalpha(c)!=0)
        {
             str[i++]=tolower(c);
        }
        else
        {
            if(i > 0) // @@ [Logic error: Should only process the word if at least one character was read (i > 0). Without this, empty strings are processed when non-alpha characters appear consecutively or at the start.]
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
                    strcpy(sheet[k].word,str); // @@ [Initialization error: The count of the new word must be initialized to 1. Previously it contained garbage value.]
                    sheet[k].count = 1;
                    num++;
                }
            }
            else 
            {
                 i = 0; // @@ [Reset index even if no word was formed to prevent buffer overflow on long sequences of non-alpha chars.]
            }
        }
    }
    if (i > 0) { // @@ [Logic error: The last word in the file might not be followed by a non-alpha character (e.g., EOF), so it needs to be processed after the loop ends.]
        str[i] = '\0';
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
            strcpy(sheet[k].word,str);
            sheet[k].count = 1;
            num++;
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