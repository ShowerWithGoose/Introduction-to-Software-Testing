#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct _Word
{               
    char s[55];
    int count;
    struct _Word *link;
}Word,*PWord;

PWord creatWord(char*);
PWord searchWord(PWord,char*);
PWord researchWord(PWord,char*);
PWord insertWord(PWord,PWord,PWord);
    
int main()   
{
    FILE *fp;
    fp=fopen("article.txt","r");
    
    int c;
    char str[55];
    char *p=str;
    PWord start=NULL;
    
    while((c=fgetc(fp))!=EOF) // @@ If the file ends with an alphabetic character, the last word remains in 'str' and is never processed because the processing logic is only triggered in the 'else' block.
    {
        if(isalpha(c))
        {
            *p=(char)tolower(c);
            p++;
        }
        else
        {
            *p='\0';
            p=str;
            PWord q,location=NULL;
            q=creatWord(str); // @@ Creates a node even when 'str' is empty (e.g., consecutive delimiters), leading to unnecessary memory allocation and potential logical clutter.
            if(start==NULL)
                start=q;
            else
            {
                location=searchWord(start,str);
                if(location!=NULL)
                    (location->count)++;
                else
                {
                    location=researchWord(start,str); // @@ The logic to find the insertion position is flawed. It incorrectly compares the head node 'p2' inside the loop and fails to correctly determine where 'str' should be inserted lexicographically.
                    start=insertWord(start,location,q); // @@ When 'location' is NULL (indicating insertion at the head), 'insertWord' incorrectly inserts 'q' after 'start' instead of making 'q' the new head of the list.
                }
            }
        }
    }
    
    fclose(fp); // @@ Missing logic to process the final word if the file does not end with a non-alphabetic character.
    
    for(PWord ptr=start;ptr!=NULL;ptr=ptr->link)
        if(ptr->s[0]!='\0')
            printf("%s %d\n",ptr->s,ptr->count);
    
    return 0;
}

PWord creatWord(char *q)
{
    PWord here;
    here=(PWord)malloc(sizeof(Word));
    here->count=1;
    strcpy(here->s,q);
    here->link=NULL;
    return here;
}

PWord searchWord(PWord p1,char *q1)
{
    PWord z;
    for(z=p1;z!=NULL;z=z->link)
        if(strcmp(z->s,q1)==0)
            return z;
    return NULL;
}

PWord researchWord(PWord p2,char *q2)
{
    PWord z;
    for(z=p2;z->link!=NULL;z=z->link)
        if(strcmp(z->link->s,q2)>0)
            if(strcmp(p2->s,q2)>0) // @@ Incorrectly compares the head node 'p2' instead of the current node or its predecessor, leading to wrong insertion points for words that should be placed at the beginning.
                return NULL;
            else
                return z;
    return z;

}

PWord insertWord(PWord p3,PWord here,PWord p4)
{
    if(here==NULL)
    {
        p4->link=p3->link; // @@ For head insertion (here==NULL), this incorrectly links p4 after p3. It should set p4->link=p3 and return p4 to update the list head.
        p3->link=p4;
        return p3;
    }
    else
    {
        p4->link=here->link;
        here->link=p4;
        return p3;
    }
}