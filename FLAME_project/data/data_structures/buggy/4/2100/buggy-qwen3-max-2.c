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
char words[MAXL]={0}; // @@ [This initializes only the first element to 0; rest are indeterminate. Should use memset or initialize properly.]

int i=0; // @@ [Global variable 'i' is reused in multiple contexts, leading to confusion and bugs.]
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
        
        int len_w=strlen(words); // @@ [strlen(words) relies on null-termination, but 'words' may not be null-terminated because it's filled with '0' (character zero, not '\0') later. Also, 'words' is never null-terminated after reading a word.]
        for(i=0;i<len_a;i++) // @@ [Reusing global 'i' here destroys its value from the word-reading loop. Should use a local variable.]
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
            
            strcpy(array[len_a-1].word,words); // @@ [strcpy expects a null-terminated string, but 'words' is not null-terminated because it's filled character-by-character without adding '\0'.]
            array[len_a-1].cnt=1;
        }
        
        for(i=0;i<MAXL;i++)
        {
            words[i]='0'; // @@ [Should set to '\0', not '0'. This causes garbage in output as seen in buggy output with trailing '0's.]
        }
        
        i=0;
        flag=0; // @@ [Missing reset of 'flag' after processing a word, causing subsequent non-matching words to be skipped.]
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