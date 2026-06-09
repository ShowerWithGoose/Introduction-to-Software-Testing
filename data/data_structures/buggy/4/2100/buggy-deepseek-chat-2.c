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
        
        int len_w=strlen(words); // @@ This line is unnecessary and len_w is unused, but not an error per se. The main error is below.
        for(i=0;i<len_a;i++) // @@ Error: The loop variable i overwrites the global i used for words index, causing words index to be corrupted after the loop.
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
        
        for(i=0;i<MAXL;i++) // @@ Error: This loop resets words to '0' (character zero) instead of '\0' (null terminator), which will cause strcmp to fail on subsequent words.
        {
            words[i]='0';
        }
        
        i=0; // @@ Error: This resets i to 0, but the previous for loop already set i to MAXL, so this is correct, but the global i is corrupted by the earlier for loop.
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