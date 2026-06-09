#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define tolower(c) (c>='A'&&c<='Z' ? 'a'-'A'+c:c)
typedef struct LNode *Link;
struct LNode
{
    char ch[100];
    int num;
    Link next;
};
char Line[1024];
Link CreateLink();
void Check(Link ,char *);
Link InsertSort(Link );
void Print(Link );

int main()
{
    FILE *IN;
    if((IN = fopen("article.txt","r")) == NULL)
    {
        printf("The file do not exist.\n");
        return -1;
    }
    Link L = CreateLink();
    char ch[100];
    while(fgets(Line, 1023, IN) != NULL)
    {
        int len = 0;
        for(int i=0;Line[i];i++)
        {
            if(Line[i] >= 'A' && Line[i] <= 'Z')
                ch[len++] = tolower(Line[i]);
            else if(Line[i] >= 'a' && Line[i] <= 'z')
                ch[len++] = Line[i];
            else
            {
                ch[len] = '\0';
                Check(L, ch);
                len = 0;
                memset(ch, '\0', sizeof(ch));
            }
        }
    }
    L = InsertSort(L);
    Print(L);
    return 0;
}

Link CreateLink()
{
    Link L = (Link)malloc(sizeof(struct LNode));
    L->num = 0;
    L->next = NULL;
    return L;
}

void Check(Link L,char *ch)
{
    Link place = L;
    while(place != NULL)
    {
        if(strcmp(ch, place->ch) == 0)
        {
            place->num++;
            return;
        }
        else
        {
            if(place->next != NULL)
                place = place->next;
            else
                break;          
        }
    }
    Link Tmp = CreateLink();
    strcpy(Tmp->ch, ch);
    Tmp->num = 1;
    place->next = Tmp;
    place = Tmp;
}

Link InsertSort(Link L) 
 {
	 if(L == NULL)
        return L;
    Link head = L->next;
    Link current = head->next;
    head->next = NULL;
    while(current != NULL)
    {
        Link p = L;
        while(p->next != NULL && strcmp(p->next->ch, current->ch) < 0)
            p = p->next;
        Link tmp = current->next;
        current->next = p->next;
        p->next = current;
        current = tmp;
    }
    return L;
}

void Print(Link L)
{
    Link p = L->next;
    while(p != NULL)
    {
        if(p != L)
            printf("%s %d\n", p->ch, p->num);
        p = p->next;
    }
}



