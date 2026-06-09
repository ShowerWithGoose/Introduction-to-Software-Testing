#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct 
{
    char word[50];
    int count;
} wordcount;

int compare(const void *a, const void *b)
{
    return strcmp(((wordcount*)a)->word, ((wordcount*)b)->word);
}

int main()
{
    wordcount words[1000];
    int wcount=0,i=0,j=0,k=0,m=0;
    char line[1000]={0};
    char ci[50];
    FILE *file=fopen("article.txt","r");
    while(fgets(line,1000,file)!=NULL)
    {
        for(i=0;i<strlen(line);i++)
        {
            if(isalpha(line[i]))
            {
                line[i]=tolower(line[i]);
            }
        }
        for(i=0;i<strlen(line);i++) 
        {
            if(isalpha(line[i]))
            {
                ci[j]=line[i];
                j++;
            }
            else
            {
                ci[j]='\0';
                j=0;
                int key=0;
                for(k=0;k<wcount;k++) 
                {
                    if(strcmp(words[k].word,ci)==0) 
                    {
                        words[k].count++;
                        key=1;
                        break;
                    }
                }
                    if (key==0) 
                    {
                        strcpy(words[wcount].word,ci);
                        words[wcount].count=1;
                        wcount++;
                    }
                    for(m=0;m<50;m++)
                {
                       ci[m]=0;
                }
            }
                
        }
        
    }
        
    qsort(words,wcount,sizeof(wordcount),compare);
    for(i=0;i<wcount;i++) 
    {
        if(words[i].word!=" "&&words[i].word!="\n"&&words[i].word!="\0") // @@ [Comparing string literals with != is invalid in C; should use strcmp or check length instead. Also, after processing, empty strings may be stored due to consecutive non-alpha characters, leading to output of empty words.]
        {
            printf("%s %d\n", words[i].word, words[i].count);
        }
        
    }
    fclose(file);
    return 0;
}