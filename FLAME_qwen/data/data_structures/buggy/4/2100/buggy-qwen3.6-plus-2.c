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
    char ch; // @@ [Error: 'ch' should be declared as 'int' because fgetc() returns an int, and comparing a char with EOF can lead to incorrect loop termination or infinite loops]
    
    int flag=0;
    while((ch=fgetc(in))!=EOF)
    {
        if(isalpha(ch))
        {
            words[i]=tolower(ch);
            i++;
            
        }
        else // @@ [Error: consecutive non-alphabetic characters will repeatedly trigger this block and process empty strings; should add 'if(i > 0)' check before processing]
        {
        
        int len_w=strlen(words); // @@ [Error: 'words' lacks a null terminator ('\0') at index 'i' before calling strlen/strcmp, leading to undefined behavior and incorrect string comparisons]
        for(i=0;i<len_a;i++)
        {
            
            if(strcmp(words,array[i].word)==0)
            {
                array[i].cnt++;
                flag=1;
                break;
            }
        }
        if(flag==0) // @@ [Error: 'flag' is not reset to 0 after processing a word, so subsequent new words will incorrectly be skipped if a previous word was found]
        {
            len_a++;
            
            strcpy(array[len_a-1].word,words);
            array[len_a-1].cnt=1;
        }
        
        for(i=0;i<MAXL;i++)
        {
            words[i]='0'; // @@ [Error: should be '\0' (null character) to properly clear/terminate the string, '0' is the ASCII digit zero which corrupts string termination]
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