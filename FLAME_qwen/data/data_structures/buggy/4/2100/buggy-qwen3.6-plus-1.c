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
    char ch; // @@ fgetc() returns an int, so ch should be declared as int to correctly handle and compare with EOF. Using char may cause EOF to be misinterpreted.
    
    int flag=0; // @@ flag is never reset to 0 after processing a word, so once a match is found, flag remains 1 and subsequent new words will not be added.
    while((ch=fgetc(in))!=EOF)
    {
        if(isalpha(ch))
        {
            words[i]=tolower(ch);
            i++;
            
        }
        else // @@ The code processes the buffer even when i==0 (consecutive non-alphabetic characters), which incorrectly adds empty strings to the array. A check if(i > 0) is needed before processing.
        {
        
        int len_w=strlen(words);
        for(i=0;i<len_a;i++)
        {
            
            if(strcmp(words,array[i].word)==0)
            {
                array[i].cnt++;
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            len_a++;
            
            strcpy(array[len_a-1].word,words);
            array[len_a-1].cnt=1;
        }
        
        for(i=0;i<MAXL;i++)
        {
            words[i]='0'; // @@ '0' is the ASCII character for zero, not the null terminator '\0'. This fails to properly terminate the string, causing strcmp and strlen to behave incorrectly.
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