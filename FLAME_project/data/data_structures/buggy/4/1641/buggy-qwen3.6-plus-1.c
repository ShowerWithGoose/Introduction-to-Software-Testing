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
        if(words[i].word!=" "&&words[i].word!="\n"&&words[i].word!="\0") // @@ [Error: Comparing string arrays with pointers using != does not check content. It checks memory addresses, which will always be true for array names. This condition fails to filter out empty strings effectively if they were inserted, but more importantly, the logic for filtering is flawed. However, the primary issue causing the Wrong Answer (extra space/empty line at start) is likely an empty word being stored or printed. The condition `words[i].word!=""` is syntactically valid C (comparing address of array to address of string literal) but logically useless for content comparison. If an empty word "" was added to the list, it would pass this check because the address of `words[i].word` is not equal to the address of the string literal `""`. To fix the output format which has a leading blank line or space, we must ensure empty words are not printed. The correct check is `strlen(words[i].word) > 0` or `words[i].word[0] != '\0'`.]
        {
            printf("%s %d\n", words[i].word, words[i].count);
        }
        
    }
    fclose(file);
    return 0;
}