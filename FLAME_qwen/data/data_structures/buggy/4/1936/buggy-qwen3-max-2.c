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
            biao[k1].count =1; // @@ [This line resets count to 1 for every character of a word, instead of initializing once per word. Should initialize count only when starting a new word.]
            flag=0;
            k2++;
        }
        else if(~(tolower(ch)<='z'&&tolower(ch)>='a')&&flag1==1)
        {
            flag++;
            if(flag==1)
            {
                biao[k1].word[k2]='\0'; // @@ [Missing null-termination of the current word before moving to next word. Without this, strcmp may read garbage beyond the word.]
                k1++;
            }
            k2=0;
        }
    }
    if(flag1==1 && k2>0) // @@ [Missing handling of last word if file doesn't end with non-alphabetic character. The last word may not be null-terminated or counted.]
    {
        biao[k1].word[k2]='\0';
        k1++;
    }
    char str[100];
    for(int i=0;i<k1-1;i++)
    {
        for(int j=0;j<k1-i-1;j++)
        {
            if(strcmp(biao[j].word ,biao[j+1].word )>0)
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
                if(biao[i].word[k]==biao[j].word[k])
                {
                    s++;
                }
            }
            if(s==100) // @@ [Incorrect word comparison: comparing all 100 characters even if words are shorter. Should use strcmp instead of manual char-by-char over fixed length.]
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
            printf("%s %d\n",biao[i].word ,biao[i].count );
        }
    }
    fclose(in);
}