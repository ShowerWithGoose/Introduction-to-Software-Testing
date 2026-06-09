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
    file=fopen("article.txt","r"); // @@ [If "article.txt" does not exist or cannot be opened, file will be NULL, and subsequent fscanf will cause undefined behavior. The program should check if file is NULL and handle the error.]
    j=0;
    while(fscanf(file,"%s",theword)==1) // @@ [fscanf with %s reads space-delimited tokens, but the problem defines a word as only alphabetic characters. This approach fails when words are adjacent to punctuation (e.g., "hello,world" becomes one token "hello,world", which is not split correctly). Also, if file is NULL, this causes a crash.]
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
            else if(i>0&&isalpha(theword[i-1])) // @@ [This condition attempts to handle non-alphabetic characters, but the logic is flawed. It sets allword[j][k]='\0' but then uses 'i' incorrectly in inner loop. Also, 'k=i+1' is wrong—it should reset k to 0 for next word, not set to i+1. Moreover, the inner while loop checks theword[k] but references theword[i-1] inside, which is a bug.]
            {
                allword[j][k]='\0';
                k=i+1;
                while(theword[k])
                {
                    if(isalpha(theword[i-1]))  // @@ [This condition always checks the same character (i-1), not the current k. It should check theword[k]. This leads to incorrect splitting and potential infinite loops or missed words.]
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
                WN[i].num++; // @@ [This increments the count before checking if the word is actually new. Later, the code unconditionally copies the word into WN[numofwords] and sets num=1, which overwrites or duplicates counts. The logic for counting is inverted: it should only add a new entry if not found, not always add and then check.]
            }
        }
        
        strcpy(WN[numofwords].word,allword[j]); // @@ [This line always adds the current word to WN, even if it already exists. Then, the following loop checks for duplicates and sets flag, but by then the duplicate has already been added. This leads to duplicate entries and incorrect counts.]
        WN[numofwords].num=1;
        for(i=0;i<numofwords;i++) 
        {
            if(strcmp(allword[j],WN[i].word)==0) 
            {
                flag=1;
                break;
            }
        }
        if(flag==0) numofwords++;
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