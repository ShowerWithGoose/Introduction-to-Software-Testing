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
        
        int len_w=strlen(words); // @@ This line is unnecessary and len_w is unused; also, the variable i is reused here, corrupting the index used to build words.
        for(i=0;i<len_a;i++) // @@ The loop variable i overwrites the index used to build the words array, causing the next word to start at the wrong position.
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
        
        for(i=0;i<MAXL;i++) // @@ This loop resets i to 0 and then increments it to MAXL, but i is also used as the index for building words; after this loop, i is MAXL, not 0.
        {
            words[i]='0'; // @@ Should set to '\0' (null terminator), not '0' (character zero).
        }
        
        i=0; // @@ This reset is correct, but the previous loop has already corrupted the index.
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