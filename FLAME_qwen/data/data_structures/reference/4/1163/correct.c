#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define node struct Node
#define nodeptr struct Node*

struct Node 
{
    char word[114];
    int times;
    struct Node* next;
}head;

int IsUpper(char);
int IsLower(char);
void Insert(nodeptr,nodeptr);
nodeptr new();
nodeptr search(nodeptr,nodeptr,char*);
void print(nodeptr);
int main()
{
    FILE *in = fopen("article.txt","r");
    int count = 0,op = 0;
    char tempstr[114] = {};
    nodeptr headptr = &head,*end = new(),*ptr = NULL,*posptr = NULL;
    headptr->next = end,ptr = headptr;

    
    while ((op = getc(in)) != EOF)
    {
        if (IsUpper(op))
        {
            tempstr[count++] = op-'A'+'a';
        }
        else if (IsLower(op))
        {
            tempstr[count++] = op;
        }
        else if(tempstr[0] != 0)
        {
            ptr = new();
            strcpy(ptr->word, tempstr);
            posptr = search(headptr, end, ptr->word);
            if (strcmp(posptr->word,ptr->word) == 0)
            {
                posptr->times++;
                free(ptr),ptr = NULL;
            }
            else
            {
                ptr->times++;
                Insert(ptr, posptr);
            }
            memset(tempstr,0,114);
            count = 0;
        }
    }
    

    ptr = headptr->next;
    while (ptr != end)
    {
        print(ptr);
        ptr = ptr->next;
    }
    
    return 0;
}


void Insert(nodeptr ptr, nodeptr pos)
{
    ptr->next = pos->next;
    pos->next = ptr;
}


nodeptr new()
{
    nodeptr newp = (nodeptr)malloc(sizeof(node));
    memset(newp,0,sizeof(node));
    return newp;
}


nodeptr search(nodeptr begin,nodeptr end,char *words)
{
    nodeptr ptr = begin;
    while (ptr->next != end)
    {
        // int temp = strcmp(words,ptr->next->word);
        if (strcmp(words,ptr->next->word)<0)
        {
            return ptr;
        }
        ptr = ptr->next;
    }
    return ptr;
}


int IsUpper(char achar)
{
    if ((achar>='A')&&(achar<='Z'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int IsLower(char achar)
{
    if ((achar>='a')&&(achar<='z'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void print(nodeptr ptr)
{
    printf("%s %d\n", ptr->word, ptr->times);
}
