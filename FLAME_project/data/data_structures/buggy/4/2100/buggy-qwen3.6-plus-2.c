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
        
        int len_w=strlen(words);
        if (len_w > 0) { // @@ The program fails to check if a valid word was accumulated before processing. If consecutive delimiters appear, strlen(words) might be 0 or contain garbage from previous resets if not handled, but more importantly, the logic below runs for every non-alpha character, including cases where no word was formed (e.g., start of file or consecutive spaces). However, the critical error is that `flag` is not reset to 0 at the beginning of each word processing block.
        flag = 0; // @@ The variable 'flag' is used to indicate if a word was found in the existing array. It is set to 1 if found, but never reset to 0 for the next word. This causes subsequent new words to incorrectly skip insertion if a previous word was found.
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
        } // @@ Added closing brace for the len_w > 0 check logically, but since I cannot add lines, I must mark the logical flow error. The original code lacks a check for empty words.
        
        for(i=0;i<MAXL;i++)
        {
            words[i]='0'; // @@ The buffer is reset with '0' characters instead of '\0'. This means strings are not properly null-terminated in the standard C sense if relied upon by strlen immediately after, although strlen stops at '\0'. Since '0' is not '\0', strlen will read past the intended end of the string into uninitialized memory or previous data until it hits a random '\0'. This causes garbage characters in output.
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