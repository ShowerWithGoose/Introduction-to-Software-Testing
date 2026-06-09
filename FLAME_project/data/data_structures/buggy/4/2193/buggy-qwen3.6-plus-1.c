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
    
    while((c=fgetc(fp))!=EOF)
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
            q=creatWord(str);
            if(start==NULL) // @@ The condition `if(start==NULL)` is incorrect because it only handles the very first word. If `str` is empty (e.g., consecutive non-alpha characters), `q` is created with an empty string and added to the list, or if `start` is not NULL but `str` is empty, it proceeds to search/insert logic which might create nodes for empty strings. More critically, if `str` is empty, `q` contains an empty string. The code should check if `str` is not empty before processing. However, the primary logical error causing the wrong order is in `researchWord` and `insertWord`. Let's look closer. Actually, the main issue is that `researchWord` fails to handle the case where the new word should be inserted at the head of the list (lexicographically smaller than the first element).
                start=q;
            else
            {
                location=searchWord(start,str);
                if(location!=NULL)
                    (location->count)++;
                else
                {
                    location=researchWord(start,str);
                    start=insertWord(start,location,q);
                }
            }
        }
    }
    
    fclose(fp);
    
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
            if(strcmp(p2->s,q2)>0) // @@ This condition `strcmp(p2->s,q2)>0` checks if the head of the list is greater than the new word. If so, it returns NULL, signaling that the new word should be inserted at the head. However, the logic inside `insertWord` when `here==NULL` assumes `p3` is the node *after* which we insert, or it tries to insert at head. Let's trace `insertWord`. If `researchWord` returns NULL, `insertWord` is called with `here=NULL`. Inside `insertWord`, if `here==NULL`, it does `p4->link=p3->link; p3->link=p4;`. This inserts `p4` after `p3` (the head). This is wrong. If the new word is lexicographically smaller than the head, it should become the new head. The `researchWord` function is flawed. It should return the node *before* the insertion point. If the new word is smaller than the first node, it should return NULL to indicate head insertion. But `insertWord`'s handling of `here==NULL` is incorrect for head insertion. It inserts after the head instead of replacing the head.
                return NULL;
            else
                return z;
    return z;

}

PWord insertWord(PWord p3,PWord here,PWord p4)
{
    if(here==NULL) // @@ When `here` is NULL, it implies the new word `p4` should be inserted at the beginning of the list (because it's lexicographically smaller than the current head `p3`). The current code `p4->link=p3->link; p3->link=p4;` inserts `p4` after `p3`, which is incorrect. It should set `p4->link = p3` and return `p4` as the new head.
    {
        p4->link=p3->link;
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