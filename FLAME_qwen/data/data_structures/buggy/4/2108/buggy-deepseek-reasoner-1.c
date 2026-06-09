#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

typedef struct
{
    char word[200];
    int num;
}wordnum;

int compare(const void *a,const void *b)
{
    return strcmp(((wordnum *)a)->word,((wordnum *)b)->word);
}

int main()
{
    wordnum WN[1000];
    int i,numofwords=0,j,k,flag=0;
    char theword[2000],allword[200][200];
    
    FILE *file;
    file=fopen("article.txt","r");
    j=0;
    while(fscanf(file,"%s",theword)==1)
    {
        //puts(theword);
        i=0;k=0;flag=0;
        while(theword[i])
        {
            //printf("%d %c",k,allword[j][k-1]);
            if(isalpha(theword[i]))
               {
                   flag=1;
                   allword[j][k] = tolower(theword[i]);
                   k++;
            }
            else if(i>0&&isalpha(theword[i-1]))
            {
                allword[j][k]='\0';  // @@ This line may cause overwrite of the same word row because 'j' is not incremented before resetting k. The logic to separate multiple words within a token is flawed.
                k=i+1;  // @@ Incorrectly sets k to skip punctuation, but j remains unchanged, causing subsequent letters to be written into the same row, overwriting the previous word.
                while(theword[k])
                {
                    if(isalpha(theword[i-1]))  // @@ Condition uses i-1 (which is the non-alpha character), so it never becomes true, hence j is never incremented. This prevents proper word separation.
                    {
                        j++;
                        break;
                    }
                    k++;
                }
                k=0;  // @@ Resetting k to 0 without incrementing j causes overwrite of the current row.
            }
            //printf(" & %d\n",j);
            i++;
        }
        if(flag==1) j++;
    }
    int N=j;
//    printf("&&&%d\n",N);
    
    j=0;k=0;
    while(N>0)
    {    
        flag=0;
        for(i=0;i<numofwords;i++)
        {
            if(strcmp(allword[j],WN[i].word)==0)
            {
                WN[i].num++;  // @@ Increments count for duplicate word, but does not break; then the code still adds a new entry for the same word, resulting in duplicate entries.
            }
        }
        
        strcpy(WN[numofwords].word,allword[j]);  // @@ Always copies the word into a new index, even if it already exists in the list. This adds a duplicate entry.
        WN[numofwords].num=1;
        for(i=0;i<numofwords;i++) 
        {
            if(strcmp(allword[j],WN[i].word)==0) 
            {
                flag=1;
                break;
            }
        }
        if(flag==0) numofwords++;  // @@ If the word was a duplicate, flag is set to 1, so numofwords is not incremented, but a new entry was already added at index numofwords, leaving a duplicate entry in the array.
        j++;
        N--;
    }
    fclose(file);

    qsort(WN,numofwords, sizeof(wordnum), compare);

    for (i = 0; i < numofwords; i++) 
    {
        printf("%s %d\n", WN[i].word, WN[i].num);
    }

    return 0;
}