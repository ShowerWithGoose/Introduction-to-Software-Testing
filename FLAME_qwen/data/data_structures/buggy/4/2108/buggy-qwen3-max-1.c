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
    file=fopen("article.txt","r"); // @@ [If the file "article.txt" does not exist or cannot be opened, fopen returns NULL, and subsequent fscanf will cause undefined behavior. The program should check if file is NULL before proceeding.]
    j=0;
    while(fscanf(file,"%s",theword)==1) // @@ [fscanf with %s reads space-delimited tokens, but the problem defines a word as only alphabetic characters. This approach fails to split tokens like "don't" or "hello!!!" correctly into pure alphabetic words. Non-alphabetic characters within a token are not handled properly.]
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
            else if(i>0&&isalpha(theword[i-1])) // @@ [This condition attempts to handle non-alphabetic characters, but the logic is flawed. It sets k=i+1 (which is unrelated to current word length) and enters a loop that checks thewrong index (i-1 instead of k). Also, it breaks after incrementing j without properly terminating the current word or handling multiple non-alpha segments.]
            {
                allword[j][k]='\0';
                k=i+1;
                while(theword[k])
                {
                    if(isalpha(theword[i-1]))  // @@ [This condition uses i-1 (a fixed index from outer loop) instead of k, making it logically incorrect. It never checks the actual character at position k.]
                    {
                        j++;
                        break;
                    }
                    k++;
                }
                k=0;
            }
            //printf(" & %d\n",j);
            i++;
        }
        if(flag==1) j++; // @@ [The word built in allword[j] may not be null-terminated if the last character in theword is alphabetic, because the else-if block that adds '\0' only triggers on non-alpha after alpha. So if theword ends with letters, allword[j] lacks '\0', causing undefined behavior in later strcmp.]
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
                WN[i].num++; // @@ [The word is counted here, but then immediately overwritten below by reinitializing WN[numofwords].word and .num=1, even if it already exists. This double-counting and overwriting leads to incorrect frequencies.]
            }
        }
        
        strcpy(WN[numofwords].word,allword[j]); // @@ [This copies the word into WN[numofwords] regardless of whether it's a duplicate, overwriting any previous count adjustment above.]
        WN[numofwords].num=1; // @@ [Resets count to 1 even if the word was already found and incremented above, leading to loss of correct count.]
        for(i=0;i<numofwords;i++) 
        {
            if(strcmp(allword[j],WN[i].word)==0) 
            {
                flag=1;
                break;
            }
        }
        if(flag==0) numofwords++; // @@ [Because the word was already added before checking for duplicates, this causes either duplicate entries (if flag==0) or orphaned entries (if flag==1, the extra entry remains unused). The logic order is inverted: should check first, then add only if new.]
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