#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

typedef struct _wordnode{
    char word[14];
    int cnt;
    struct _wordnode *next;
}Wordnode;


int main()
{
    Wordnode firstNode,*lastNodePtr,*scanPtr,*tempPtr;
    firstNode.next=NULL;
    firstNode.cnt=0;
    strcpy(firstNode.word,"aaaaaaaaaaaa");
    lastNodePtr=&firstNode;
    FILE *fpin;
    fpin=fopen("article.txt","r");
    char temp,currentWord[14],articleBuffer[1024];
    int scan=0,wordCnt=0;
    //fscanf(fpin,"%c",&temp);
    while(fscanf(fpin,"%c",&temp)!=EOF)
    {
        if(temp>=65 && temp<=90)
            temp+=32;
        else if(temp>=97 && temp<=122);
        else
            temp=' ';
        articleBuffer[scan++]=temp;
        //fscanf(fpin,"%c",&temp);
    }
    articleBuffer[scan]=0;
    fclose(fpin);
    fpin=fopen("article.txt","w+");
    fprintf(fpin,"%s",articleBuffer);
    fclose(fpin);
    fpin=fopen("article.txt","r");

    while(fscanf(fpin,"%s",currentWord)!=EOF)
    {
        scanPtr=&firstNode;
        while(scanPtr!=NULL)
        {
            lastNodePtr=scanPtr;
            if(strcmp(scanPtr->word,currentWord)==0)
            {
                scanPtr->cnt++;
                break;
            }
            scanPtr=scanPtr->next;
        }
        if(scanPtr==NULL)
        {
            lastNodePtr=&firstNode;
            scanPtr=firstNode.next;
            tempPtr=(Wordnode*) malloc(sizeof(Wordnode));
            wordCnt++;
            tempPtr->next=NULL;
            tempPtr->cnt=1;
            strcpy(tempPtr->word,currentWord);
            while(scanPtr!=NULL)
            {
                if(strcmp(tempPtr->word,scanPtr->word)<=0)
                    break;
                else
                {
                    lastNodePtr=scanPtr;
                    scanPtr=scanPtr->next;
                }
            }
            lastNodePtr->next=tempPtr;
            tempPtr->next=scanPtr;
        }
    }
    scan=0;
    scanPtr=firstNode.next;
    while(scan<wordCnt)
    {
        printf("%s %d\n\n",scanPtr->word,scanPtr->cnt);
        scanPtr=scanPtr->next;
        scan++;
    }
    fclose(fpin);
    return 0;
}
