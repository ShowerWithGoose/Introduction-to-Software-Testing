#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

#define FILE_IN "article.txt"

typedef struct nodeDict
{
    int count;
    int childrenNum;
    char charVal;
    struct nodeDict *siblings;
    struct nodeDict *children;
} nodeDict;

struct string
{
    char *head;
    char *tail;
};

FILE *fileRead(char *name);
nodeDict *newNode();
void bulidTree(FILE *in, nodeDict *head);
void countWords(nodeDict *head, FILE *out);
void _countWords(nodeDict *head, FILE *out, struct string *str);

nodeDict *addChild(nodeDict *parent, char ch);

int main()
{
    FILE *fileIn = fileRead(FILE_IN);
    nodeDict *head = newNode();

    bulidTree(fileIn, head);
    countWords(head, stdout);

    fclose(fileIn);
    return 0;
}

FILE *fileRead(char *name)
{
    return fopen(name, "r");
}

nodeDict *newNode()
{
    nodeDict *new = (nodeDict *)malloc(sizeof(nodeDict));
    new->count = 0;
    new->childrenNum = 0;
    new->charVal = 0;
    new->siblings = NULL;
    new->children = NULL;
    return new;
}

void bulidTree(FILE *in, nodeDict *head)
{
    nodeDict *ptCur = head;
    while (!feof(in))
    {
        char ch = fgetc(in);
        if (isalpha(ch))
        {
            ch = tolower(ch);
            ptCur = addChild(ptCur, ch);
        }
        else
        {
            if (ptCur != head)
            {
                ptCur->count++;
            }
            ptCur = head;
        }
    }
}

nodeDict *addChild(nodeDict *parent, char ch)
{
    if (parent->childrenNum == 0)
    {
        nodeDict *child = newNode();
        child->charVal = ch;
        parent->children = child;
        parent->childrenNum++;
        return child;
    }
    else
    {
        if (parent->children->charVal > ch)
        {
            nodeDict *child = newNode();
            child->charVal = ch;
            child->siblings = parent->children;
            parent->children = child;
            parent->childrenNum++;
            return child;
        }
        else if (parent->children->charVal == ch)
        {
            return parent->children;
        }
        else
        {
            nodeDict *ptNode = parent->children;
            while (ptNode->siblings != NULL && ptNode->siblings->charVal < ch)
            {
                ptNode = ptNode->siblings;
            }

            if (ptNode->siblings == NULL)
            {
                nodeDict *child = newNode();
                child->charVal = ch;
                ptNode->siblings = child;
                parent->childrenNum++;
                return child;
            }
            else if (ptNode->siblings->charVal == ch)
            {
                return ptNode->siblings;
            }
            else
            {
                nodeDict *child = newNode();
                child->charVal = ch;
                child->siblings = ptNode->siblings;
                ptNode->siblings = child;
                parent->childrenNum++;
                return child;
            }
        }
    }
}

void countWords(nodeDict *head, FILE *out)
{
    struct string *str = (struct string *)malloc(sizeof(struct string));
    str->head = (char *)malloc(50);
    str->tail = str->head;
    for (int cnt = 0; cnt < 50; cnt++)
    {
        *(str->head + cnt) = '\0';
    }
    _countWords(head->children, out, str);
    //free(str->head);
    free(str);
}

void _countWords(nodeDict *head, FILE *out, struct string *str)
{
    if (head != NULL)
    {
        *(str->tail) = head->charVal;
        str->tail++;
        if (head->count > 0)
        {
            fprintf(out, "%s %d\n", str->head, head->count);
        }
        _countWords(head->children, out, str);
        str->tail--;
        *(str->tail) = '\0';
        _countWords(head->siblings, out, str);

        if (head->children == NULL && head->siblings == NULL)
        {
            //free(head);
        }
    }
}


