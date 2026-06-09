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
    while(fscanf(file,"%s",theword)==1) // @@ [fscanf with %s reads space-delimited tokens, but the problem defines a "word" as only alphabetic characters. This approach fails when words are adjacent to punctuation (e.g., "hello,world" becomes one token "hello,world", which is not split correctly). Also, if file is NULL, this causes a crash.]
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
            else if(i>0&&isalpha(theword[i-1])) // @@ [This condition attempts to handle non-alphabetic characters, but the logic is flawed. It sets allword[j][k]='\0' but then tries to scan ahead with 'k=i+1' and a nested while loop that references 'theword[i-1]' (fixed index) instead of 'theword[k]', leading to incorrect splitting and potential out-of-bound writes. Also, 'j' may exceed array bounds (allword is [200][200]).]
            {
                allword[j][k]='\0';
                k=i+1;
                while(theword[k])
                {
                    if(isalpha(theword[i-1]))  // @@ [This should be 'theword[k]' not 'theword[i-1]'. Using 'i-1' (a fixed earlier index) makes no sense here and breaks word extraction logic.]
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
                WN[i].num++; // @@ [The logic here is inverted: it increments existing count BEFORE checking if the word is new. Then it unconditionally copies the word into WN[numofwords] and sets count=1, overwriting any prior increment. This leads to double-counting or incorrect counts.]
            }
        }
        
        strcpy(WN[numofwords].word,allword[j]); // @@ [This copies the word even if it already exists, overwriting the correctly incremented entry with a new entry having count=1. The order of operations is wrong: should only add new word if not found.]
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