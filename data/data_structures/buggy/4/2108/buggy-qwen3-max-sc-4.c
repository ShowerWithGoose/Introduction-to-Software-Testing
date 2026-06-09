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
    file=fopen("article.txt","r"); // @@ [If the file "article.txt" does not exist or cannot be opened, fscanf will cause undefined behavior. The program should check if file is NULL before proceeding.]
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
            else if(i>0&&isalpha(theword[i-1])) // @@ [This condition attempts to handle non-alphabetic characters, but the logic is flawed. It sets k=i+1 (which may exceed array bounds) and then enters a loop that checks thewrong index (i-1 instead of k). This can lead to incorrect word splitting or buffer overflows.]
            {
                allword[j][k]='\0';
                k=i+1;
                while(theword[k])
                {
                    if(isalpha(theword[i-1]))  // @@ [This condition uses i-1 (a fixed index) instead of k, making it logically incorrect. It should check theword[k], not theword[i-1].]
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
                WN[i].num++; // @@ [The word is incremented here, but later the same word is added again unconditionally below, leading to double-counting or incorrect counts.]
            }
        }
        
        strcpy(WN[numofwords].word,allword[j]); // @@ [This copies the word into WN even if it already exists, overwriting potentially valid data and causing duplicate entries.]
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