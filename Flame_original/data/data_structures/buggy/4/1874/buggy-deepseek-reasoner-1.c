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
    while(c=fgetc(in)!=EOF) // @@ [Operator precedence: `!=` evaluated before `=`, so `c` gets 0 or 1, not the character; use `(c=fgetc(in))!=EOF`]
    {
        if(isalpha(c)!=0)
        {
             str[i++]=tolower(c);
        }
        else
        {
            str[i]='\0'; // @@ [Should only process if i>0 (a word was built); otherwise empty string is added; also resets i unconditionally]
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
                strcpy(sheet[k].word,str); // @@ [Missing: `sheet[k].count = 1;` - count is not initialized for new word]
            }
        }
    }
    // @@ [After while loop, no handling of the last word if file ends without a non‑alpha character; need to check if i>0 and add it]
    sort(sheet,num);
    int j;
    for(j=0;j<num;j++)
    {
        printf("%s %d\n",sheet[j].word,sheet[j].count);
    }
    fclose(in);
    return 0;
}