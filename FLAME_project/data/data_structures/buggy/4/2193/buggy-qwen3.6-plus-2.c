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
            if(start==NULL)
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

PWord researchWord(PWord p2,char *q2) // @@ The logic for finding the insertion position is flawed. It fails to correctly handle cases where the new word should be inserted at the head of the list (lexicographically smaller than the first element), leading to unsorted output. Specifically, if strcmp(p2->s, q2) > 0, it returns NULL, but the caller `insertWord` treats NULL as "insert after p2" (which is wrong for head insertion) or relies on specific behavior that doesn't sort the head correctly. Also, the loop condition `z->link!=NULL` misses checking the last element properly for insertion after it if needed, though the main issue is head insertion and sorted order maintenance.
{
    PWord z;
    for(z=p2;z->link!=NULL;z=z->link)
        if(strcmp(z->link->s,q2)>0)
            if(strcmp(p2->s,q2)>0)
                return NULL;
            else
                return z;
    return z;

}

PWord insertWord(PWord p3,PWord here,PWord p4) // @@ When 'here' is NULL, this function assumes insertion happens after p3 or handles head insertion incorrectly. If the new word is lexicographically smaller than the head (p3), it should become the new head. The current logic `p4->link=p3->link; p3->link=p4;` inserts p4 after p3, which is incorrect if p4 < p3. This causes the list to not be sorted correctly, specifically failing to place words like "about" before "i" if "i" was the first word inserted.
{
    if(here==NULL)
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