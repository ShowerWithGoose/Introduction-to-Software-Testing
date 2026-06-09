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
    while(c=fgetc(in)!=EOF) // @@ [Operator precedence error: assignment 'c = fgetc(in)' should be parenthesized because '!=' has higher precedence than '=', causing c to be assigned the result of the comparison (0 or 1), not the character read.]
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
                sheet[k].count++; // @@ [Uninitialized count field: when a new word is added, its count is never initialized to 1; it uses garbage value. Also, empty string may be inserted when non-alpha follows another non-alpha.]
            }
            else if(k==num)
            {
                num++;
                strcpy(sheet[k].word,str); // @@ [Logic error: after incrementing num, k == num-1, but here k is still the old value (equal to original num), so writing to sheet[num] which is out of current valid range; also, count is never set to 1.]
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