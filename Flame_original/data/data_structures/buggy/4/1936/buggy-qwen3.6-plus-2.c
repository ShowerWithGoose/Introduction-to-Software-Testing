#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <ctype.h> 
struct link{
    char word[100];   
    int count; 
};
int main()
{
    struct link biao[1000];
    char ch;
    int flag=0,flag1=0,k1=0,k2=0;
    FILE*in;
    in=fopen("article.txt","r");
    while((ch=fgetc(in))!=EOF)
    {
        if((tolower(ch)<='z'&&tolower(ch)>='a'))
        {
            flag1=1;
            biao[k1].word[k2]=tolower(ch); 
            biao[k1].count =1; // @@ Logical error: Resets count to 1 for every character read. Should only initialize when starting a new word.
            flag=0;
            k2++;
        }
        else if(~(tolower(ch)<='z'&&tolower(ch)>='a')&&flag1==1) // @@ Logical error: Uses bitwise NOT (~) instead of logical NOT (!), making the condition always evaluate to true.
        {
            flag++;
            if(flag==1)
            {
                k1++;
            }
            k2=0;
        }
    } // @@ Logical error: Missing null-terminator ('\0') for each word. Also, k1 is not incremented for the last word if the file ends with a letter.
    char str[100];
    for(int i=0;i<k1-1;i++)
    {
        for(int j=0;j<k1-i-1;j++)
        {
            if(strcmp(biao[j].word ,biao[j+1].word )>0) // @@ Runtime error: strcmp requires null-terminated strings, which are missing, causing undefined behavior.
            {
                for(int k=0;k<100;k++)
                {
                    str[k]=biao[j].word[k];
                }
                for(int k=0;k<100;k++)
                {
                    biao[j].word[k]=biao[j+1].word[k];
                }
                for(int k=0;k<100;k++)
                {
                    biao[j+1].word[k]=str[k];
                }
            }
        }
    }
    int s=0;
    for(int i=1;i<k1;i++)
    {
        for(int j=0;j<i;j++)
        {
            for(int k=0;k<100;k++)
            {
                if(biao[i].word[k]==biao[j].word[k]) // @@ Logical error: Compares characters without checking for string end ('\0'), leading to incorrect matches.
                {
                    s++;
                }
            }
            if(s==100) // @@ Logical error: Assumes all words are exactly 100 characters long. Should compare until '\0' or use strcmp.
            {
                biao[j].count++; 
                biao[i].count =0;
                break;
            }
            s=0;
        }
    }
    
    for(int i=0;i<k1;i++)
    {
        if(biao[i].count!=0 )
        {
            printf("%s %d\n",biao[i].word ,biao[i].count ); // @@ Runtime error: Prints non-null-terminated strings, causing garbage output or crash.
        }
    }
    fclose(in);
}