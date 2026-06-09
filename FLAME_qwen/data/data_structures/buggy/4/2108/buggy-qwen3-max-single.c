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
    file=fopen("article.txt","r"); // @@ [If "article.txt" does not exist or cannot be opened, file will be NULL, leading to undefined behavior when used in fscanf. The program should check if file is NULL and handle the error.]
    j=0;
    while(fscanf(file,"%s",theword)==1) // @@ [fscanf with %s reads space-delimited tokens, but the problem defines a word as only alphabetic characters. This approach fails to correctly extract words from tokens that contain non-alphabetic characters (e.g., "don't" becomes "don" and "t" incorrectly or not at all). Also, if file is NULL, this causes a crash.]
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
            else if(i>0&&isalpha(theword[i-1])) // @@ [This condition attempts to handle non-alphabetic characters, but the logic is flawed. It sets allword[j][k]='\0' but then uses 'i' instead of 'k' in subsequent checks, and the inner while loop uses 'i-1' which doesn't change, causing potential infinite loops or incorrect segmentation. Also, it may write beyond bounds of allword[j].]
            {
                allword[j][k]='\0';
                k=i+1;
                while(theword[k])
                {
                    if(isalpha(theword[i-1]))  // @@ [This condition always checks the same character (theword[i-1]) repeatedly inside the loop over 'k', which is logically incorrect. It should be checking theword[k] or similar. This leads to incorrect word splitting and possible missed words.]
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
                WN[i].num++; // @@ [The word is incremented here, but later the same word is unconditionally added again to WN[numofwords], leading to duplicate entries and incorrect counts. The logic for checking existing words is applied after adding the word, which is backwards.]
            }
        }
        
        strcpy(WN[numofwords].word,allword[j]); // @@ [This copies the word into WN before checking if it already exists. So even if the word exists, a duplicate entry is created, and then the existence check sets flag=1 but doesn't prevent the duplicate from being counted via numofwords++.]
        WN[numofwords].num=1;
        for(i=0;i<numofwords;i++) 
        {
            if(strcmp(allword[j],WN[i].word)==0) 
            {
                flag=1;
                break;
            }
        }
        if(flag==0) numofwords++; // @@ [Because the word was already copied into WN[numofwords] before this check, when flag==1 (word exists), the duplicate remains in the array but numofwords isn't incremented. However, the earlier loop already incremented the count of the existing word, so now there are two entries: one correct (with incremented count) and one new (with count=1) that shouldn't exist. This corrupts the frequency count and output.]
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