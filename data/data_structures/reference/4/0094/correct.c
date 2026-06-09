#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define max 500

struct dictionary{
    char word[30];
    int frequence;
}count[max];

int N;
char empty [max];

void storage(char words[]){
    int i;

    for (i = 0;i < N;i++){
        if (strcmp(count[i].word,words) == 0){
            count[i].frequence++;
            return;
        }
    }

    strcpy(count[N].word,words);
    count[N].frequence = 1;
    N++;
}

void read(char str[]){
    int i = 0 , j ,k,len;
    char tempword[max] = {0} , ch;
    while (i < strlen (str)){
        for (j = 0,ch = str[i]; isalpha(str[i]) ; j++){
            ch = tolower(str[i]);
            tempword[j] = ch;
            i++;
        }
        if (tempword[0] != '\0'){
            storage(tempword);
            len = strlen(tempword);
            for (k = 0;k < len;k++){
                tempword[k] = '\0';
            }
        }
        i++;
    }

}


int cmp (const void *a,const void *b){
    return strcmp( (*(struct dictionary *)a).word , (*(struct dictionary *)b).word );
}

int main()
{
    int i;
    char str[max] = {0};
    FILE *fp;

    fp = fopen ("article.txt","r");

    if (fp == NULL){
        printf ("the file can not be found");
        exit (0);
    }
    else {
        while (fgets(str,max,fp)!=NULL)
            read (str);

        qsort (count,N,sizeof(count[0]),cmp);
    }

    for (i = 0;i < N;i++){
        printf ("%s %d\n",count[i].word,count[i].frequence);

    }
    return 0;
}



