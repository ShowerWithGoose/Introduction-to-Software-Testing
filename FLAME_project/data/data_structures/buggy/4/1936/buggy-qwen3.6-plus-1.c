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
            biao[k1].count =1; // @@ This line incorrectly resets the count to 1 for every character added to the current word, instead of initializing it only once when a new word starts. It should be guarded by a check if k2 == 0.
            flag=0;
            k2++;
        }
        else if(~(tolower(ch)<='z'&&tolower(ch)>='a')&&flag1==1)
        {
            flag++;
            if(flag==1)
            {
                biao[k1].word[k2] = '\0'; // @@ Missing null-termination of the word string before moving to the next word index. Without this, strcmp and other string functions will read garbage data.
                k1++;
            }
            k2=0;
        }
    }
    // @@ If the file ends with a letter, the last word is not null-terminated or counted properly because the loop exits without processing the "else if" block for the final word.
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
            if(s==100) // @@ Comparing all 100 characters is incorrect because words are shorter and padded with undefined/garbage values or zeros depending on initialization. It should use strcmp or compare up to the null terminator.
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