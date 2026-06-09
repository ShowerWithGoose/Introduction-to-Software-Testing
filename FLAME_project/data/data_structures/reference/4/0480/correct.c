#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct Node{
    char word[40];
    int num;
    struct Node *next;
}node;

node *head;
char wd[40];

int searchWord();
int getWord(FILE *p);
int isAlp(char ch);
void insertWord();
void printWordList();

FILE *inp;

int main()
{
    char *pwd;
    node *p1;
    inp = fopen("article.txt","r");

    head = (node *)malloc(sizeof(node));
    head -> next = NULL;
    head->word[0] = '\0';
    pwd = wd;
    while(getWord(inp) != EOF)
    {
        //printf("%s\n",wd);
        if(searchWord() == -1)
        {
            //printf(":success:\n");
            insertWord();
        }
    }
    //printf("\n%s %d",head->next->word,head->next->num);
    printWordList();
    p1 = head;
    while(p1->next !=NULL)
    {
        free(p1);
        p1 = p1->next;
    };
    free(p1);
    fclose(inp);
    return 0;
}

int getWord(FILE *inp)
{
    int i = 0;
    char ch;
    while((ch = fgetc(inp)) != EOF)
    {

        if(isAlp(ch) == -1&&(i <= 0))
        {
            continue;
        }
        else if(isAlp(ch) == -1&&(i > 0))
        {
            break;
        }
        if(ch >= 'A'&&ch <= 'Z')
        {
            ch = ch +('a'-'A');
        }
        wd[i++] = ch;
        //printf("%c",ch);

    }
    wd[i] = '\0';
    if(i > 0)
    {
        return 1;
    }
    else
    {
        return EOF;
    }
};

int isAlp(char ch)
{
    if((ch >='A'&&ch <= 'Z')||(ch >= 'a'&&ch <= 'z'))
        return 1;
    else
        return -1;
};

int searchWord()
{
    node *p;
    //int i = 0;
    p = head;
    while(p -> next != NULL)
    {
        //i++;
        //printf("i:%d\n",i);
        if(strcmp(wd,p->word) == 0)
        {
            (p->num)++;
            return 1;
        }
        p = p->next;
    }
    if(strcmp(wd,p->word) == 0)
        {
            (p->num)++;
            return 1;
        }
    else
    return -1;
};
void insertWord()
{
    node *p,*m,*temp;
    p = (node *)malloc(sizeof(node));
    p->next = NULL;
    p->num = 1;
    strcpy(p->word,wd);
    //printf("why?\n");
    m = head;
    while(strcmp(m->word,wd) < 0)
    {
        //printf("awsl\n");
        temp = m;
        m = m->next;
        if(m == NULL)
        {
            break;
        }
    }
    p->next = m;
    temp->next = p;
};

void printWordList()
{
    node *p;
    p = head->next;
    while(p ->next != NULL)
    {
        printf("%s ",p->word);
        printf("%d\n",p->num);
        p = p->next;
    }
    printf("%s ",p->word);
    printf("%d\n",p->num);
};

