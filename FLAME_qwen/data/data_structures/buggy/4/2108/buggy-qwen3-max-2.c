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
    file=fopen("article.txt","r"); // @@ [If "article.txt" does not exist or cannot be opened, fopen returns NULL, and subsequent fscanf on NULL causes undefined behavior (likely crash). The program does not check if file opening succeeded.]
    j=0;
    while(fscanf(file,"%s",theword)==1) // @@ [fscanf with %s reads space-delimited tokens, but the problem defines a "word" as only alphabetic characters. This approach fails when words contain non-alphabetic characters (e.g., "don't" becomes "don" and "t"), violating the word definition. Also, if file is NULL, this crashes.]
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
            else if(i>0&&isalpha(theword[i-1])) // @@ [This condition attempts to handle non-alphabetic characters inside a token read by fscanf, but logic is flawed. It sets allword[j][k]='\0' but then uses 'i' instead of 'k' in inner loop, and breaks incorrectly. Also, it doesn't properly extract multiple words from one fscanf token (e.g., "abc123def" should yield "abc" and "def", but this code mishandles it).]
            {
                allword[j][k]='\0';
                k=i+1;
                while(theword[k])
                {
                    if(isalpha(theword[i-1]))  // @@ [This condition uses 'i-1' which is fixed, not related to 'k'. It should check theword[k], not theword[i-1]. This is a logical error that prevents correct splitting of mixed tokens.]
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
                WN[i].num++; // @@ [This increments count before checking if the word is truly new. But then later, it unconditionally copies the word into WN[numofwords] and sets num=1, overwriting the incremented value if the word already exists. This leads to incorrect counts.]
            }
        }
        
        strcpy(WN[numofwords].word,allword[j]); // @@ [This copies the word even if it already exists, overwriting the previous entry's word (though same) and resetting its count to 1 in the next line, undoing the increment above.]
        WN[numofwords].num=1; // @@ [This resets the count to 1 even for duplicate words, causing final count to be wrong (always 1 for duplicates processed this way).]
        for(i=0;i<numofwords;i++) 
        {
            if(strcmp(allword[j],WN[i].word)==0) 
            {
                flag=1;
                break;
            }
        }
        if(flag==0) numofwords++; // @@ [Because the word was already added before checking duplicates, this only controls whether numofwords increases, but the array already has a corrupted entry for duplicates.]
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