#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<malloc.h> 
#include<string.h>
#define MAXL 105 
struct FOW{//frequency of word
    char word[MAXL];
    int cnt;
};
int cmp(const void *a,const void *b)
{
    return strcmp(((struct FOW *)a)->word,((struct FOW *)b)->word);
}
char words[MAXL]={0};

int i=0;
struct FOW array[100005];
int main()
{
    
    FILE *in=fopen("article.txt","r");
    if(in==NULL)
    {
        printf("error:can not open this file");
        return 0;
     } 
    
    int len_a=0; 
    char ch;
    
    int flag=0;
    while((ch=fgetc(in))!=EOF)
    {
        if(isalpha(ch))
        {
            words[i]=tolower(ch);
            i++;
            
        }
        else
        {
        
        int len_w=strlen(words); // @@ The variable len_w is calculated but never used. More importantly, if the current character is a delimiter but no word has been accumulated (i.e., words is empty or just zeros from previous reset), strlen might be 0 or incorrect depending on initialization, leading to processing empty strings.
        for(i=0;i<len_a;i++)
        {
            
            if(strcmp(words,array[i].word)==0) // @@ Comparing 'words' which may contain garbage or '0's if not properly null-terminated or if empty. Also, logic fails if 'words' is empty (e.g., consecutive delimiters).
            {
                array[i].cnt++;
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            len_a++;
            
            strcpy(array[len_a-1].word,words); // @@ Copies potentially empty or invalid string if no alpha characters were read since last reset.
            array[len_a-1].cnt=1;
        }
        
        for(i=0;i<MAXL;i++)
        {
            words[i]='0'; // @@ Error: The buffer is filled with character '0' instead of null terminator '\0' or zero byte 0. This causes strlen to return incorrect lengths and strcmp to compare against garbage/'0's, leading to wrong output format as seen in the buggy output (long strings of 0s).
        }
        
        i=0;
    }
     } 

    fclose(in);
    
    qsort(array,len_a,sizeof(struct FOW),cmp);
    for(i=0;i<len_a;i++)
    {
        printf("%s %d\n",array[i].word,array[i].cnt);
    }
    
    return 0;
}