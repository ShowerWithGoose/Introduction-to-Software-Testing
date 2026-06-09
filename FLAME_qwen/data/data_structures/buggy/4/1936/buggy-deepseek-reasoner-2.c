#include <stdio.h>
#include <string.h>
#include <malloc.h> // @@ Non-standard header; likely causes compilation error. Use <stdlib.h> or remove.
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
            biao[k1].count =1;
            flag=0;
            k2++;
        }
        else if(~(tolower(ch)<='z'&&tolower(ch)>='a')&&flag1==1) // @@ Use logical NOT (!) instead of bitwise NOT (~).
        {
            flag++;
            if(flag==1)
            {
                k1++; // @@ Missing flag1=0; after word end, flag1 should be reset to 0 to avoid extra word on next non-letter (e.g., EOF).
            }
            k2=0;
        }
    }
    char str[100];
    for(int i=0;i<k1-1;i++)
    {
        for(int j=0;j<k1-i-1;j++)
        {
            if(strcmp(biao[j].word ,biao[j+1].word )>0)
            {
                for(int k=0;k<100;k++) // @@ Sorting swaps only words; counts are not swapped, causing mismatch. Should swap entire struct.
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
            for(int k=0;k<100;k++) // @@ Comparing up to 100 characters includes garbage; use strcmp instead.
            {
                if(biao[i].word[k]==biao[j].word[k])
                {
                    s++;
                }
            }
            if(s==100) // @@ Should use strcmp to compare strings; comparing 100 chars is wrong for shorter words.
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