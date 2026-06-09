#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
typedef struct wordInfoLinkNode
{
    char word[64];
    int times;
    struct wordInfoLinkNode *link;
}*nodePtr,node;
void insert(nodePtr prevNode,char* newWord);
int main()
{
    char letter,word[64];
    int i=0,flag=0;
    nodePtr wordList=(nodePtr)malloc(sizeof(node)),ptr;
    wordList->link=NULL;
    FILE *in=fopen("article.txt","r");
    if(in==NULL)
    {
        printf("File doesn`t exist!");
        return 1;
    }
    while((letter=fgetc(in))!=EOF)
    {
        if(isalpha(letter))
        {
            word[i++]=tolower(letter);
            flag=1;
        }
        if(!isalpha(letter)&&flag)
        {
            word[i]=0;
            ptr=wordList;
            while(1)
            {
                if(ptr->link==NULL)
                {
                    insert(ptr,word);
                    break;
                }
                if(strcmp(word,ptr->link->word)<0)
                {
                    insert(ptr,word);
                    break;
                }
                if(strcmp(ptr->link->word,word)==0)
                {
                    ptr->link->times++;
                    break;
                }
                ptr=ptr->link;
            }
            flag=0;
            i=0;
        }
    }
    ptr=wordList->link;
    while(ptr!=NULL)
    {
        printf("%s %d\n",ptr->word,ptr->times);
        ptr=ptr->link;
    }
    while(wordList->link!=NULL)
    {
        ptr=wordList;
        wordList=wordList->link;
        free(ptr);
    }
    return 0;
}
void insert(nodePtr prevNode,char* newWord)
{
    nodePtr newNode=(nodePtr)malloc(sizeof(node));
    strcpy(newNode->word,newWord);
    newNode->times=1;
    newNode->link=prevNode->link;
    prevNode->link=newNode;
    return;
}
