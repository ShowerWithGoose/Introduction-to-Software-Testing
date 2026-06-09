#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 32 //max size of word

typedef struct Node
{
    char word[SIZE];
    int num;
    struct Node *next;
} Node;
typedef Node *NodeP;
NodeP list = NULL;

int read(FILE *input, char word[]);
void search(char word[]);
void add(NodeP pre, char word[]);

int main()
{
    FILE *input = fopen("article.txt", "r");
    NodeP p;
    char word[SIZE];
    while (read(input, word) != 0)
    {
        search(word);
    }
    for (p = list; p != NULL; p = p->next)
    {
        printf("%s %d\n", p->word, p->num);
    }
    return 0;
}
//read word & tolower, return 0 not found, 1 found
int read(FILE *input, char word[])
{
    int i = 0;
    char c;
    //if char not alpha then skip, if EOF then return
    while (isalpha(c = fgetc(input)) == 0)
    {
        if (c == EOF)
        {
            return 0;
        }
    }
    word[0] = c; //first char of word = c
    i++;
    while ((c = fgetc(input)) != EOF)
    {
        if (isalpha(c) == 0) //last char of word found
        {
            break;
        }
        word[i] = c;
        i++;
    }
    word[i] = '\0';
    //upper char to lower
    for (i = 0; word[i] != '\0'; i++)
    {
        word[i] = tolower(word[i]);
    }
    return 1;
}
//search word in lis
void search(char word[])
{
    int compare;
    NodeP cur = NULL, pre = NULL;
    for (cur = list; cur != NULL; pre = cur, cur = cur->next)
    {
        compare = strcmp(word, cur->word);
        if (compare < 0) //add word before cur after pre
        {
            break;
        }
        else if (compare == 0) //word found
        {
            cur->num++;
            return;
        }
    }
    //search completed, not found, add new word after pre
    add(pre, word);
}
//add new word after pre
void add(NodeP pre, char word[])
{
    NodeP new;
    new = (NodeP)malloc(sizeof(Node));
    strcpy(new->word, word);
    new->num = 1;
    new->next = NULL;
    if (list == NULL) //no node in list
        list = new;
    else if (pre == NULL) //add to tail
    {
        new->next = list;
        list = new;
    }
    else //add between nodes
    {
        new->next = pre->next;
        pre->next = new;
    }
}


