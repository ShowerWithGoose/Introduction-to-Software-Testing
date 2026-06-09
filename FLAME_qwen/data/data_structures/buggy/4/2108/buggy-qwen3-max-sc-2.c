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
    while(fscanf(file,"%s",theword)==1) // @@ [fscanf with %s reads space-delimited tokens, but the problem defines a "word" as only alphabetic characters. Non-alphabetic characters within a token (e.g., "don't") will be included in theword, violating the word definition. Also, if file is NULL, this causes undefined behavior.]
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
            else if(i>0&&isalpha(theword[i-1])) // @@ [This condition attempts to handle non-alpha characters, but the logic is flawed. It sets allword[j][k]='\0' but then uses 'i' instead of 'k' in the inner while loop, leading to incorrect parsing and potential out-of-bounds access. Also, 'j' may exceed array bounds (allword is [200][200]).]
            {
                allword[j][k]='\0';
                k=i+1;
                while(theword[k])
                {
                    if(isalpha(theword[i-1]))  // @@ [This condition uses 'i-1' which is fixed, not related to 'k'. It should check theword[k], not theword[i-1]. This makes the inner loop logic nonsensical and ineffective.]
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
                WN[i].num++; // @@ [The word is added to WN[numofwords] before checking for duplicates, so duplicate words get added multiple times. The increment happens, but then a new entry is still created below, leading to double-counting and incorrect frequencies.]
            }
        }
        
        strcpy(WN[numofwords].word,allword[j]); // @@ [This copies the word into WN before checking if it's a duplicate. So even if the word already exists, a new entry is created, causing duplicates in the final list.]
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