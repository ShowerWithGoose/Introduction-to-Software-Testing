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
    while(c=fgetc(in)!=EOF) // @@ [Operator precedence error: assignment 'c = fgetc(in)' should be parenthesized as '(c = fgetc(in)) != EOF' to correctly assign the character and compare. Without parentheses, it assigns the result of 'fgetc(in) != EOF' (0 or 1) to c, causing incorrect behavior.]
    {
        if(isalpha(c)!=0)
        {
             str[i++]=tolower(c);
        }
        else
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
                sheet[k].count++; // @@ [Uninitialized count: when a new word is added, its count is never initialized to 1. The array 'sheet' is global so count starts at 0, and this increments it to 1 only on second occurrence. First occurrence leaves it uninitialized (0), leading to wrong counts.]
            }
            else if(k==num)
            {
                num++;
                strcpy(sheet[k].word,str); // @@ [Logic error: 'k' equals 'num' before incrementing 'num', so after 'num++', 'k' is one less than 'num'. But the word is stored at index 'k' which is now beyond the previous valid range. However, more critically, the count field for this new word is never set to 1.]
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