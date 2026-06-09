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
    
    int flag=0; // @@ [The flag variable is initialized outside the while loop and never reset after each word; after a match, flag remains 1, causing subsequent new words to be skipped.]
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
        for(i=0;i<len_a;i++)
        {
            
            if(strcmp(words,array[i].word)==0) // @@ [words is not null-terminated; strcmp may read beyond the array or produce incorrect results.]
            {
                array[i].cnt++;
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            len_a++;
            
            strcpy(array[len_a-1].word,words); // @@ [words lacks a null terminator; strcpy copies undefined data until a null byte is encountered, causing junk characters like '0's in the output.]
            array[len_a-1].cnt=1;
        }
        
        for(i=0;i<MAXL;i++)
        {
            words[i]='0'; // @@ [Resetting with ASCII '0' instead of null character '\0' leads to strings filled with '0's, producing "000..." output.]
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