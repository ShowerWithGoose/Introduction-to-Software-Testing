#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    int num;
    char c[1024];
    struct node *next;
}Wordlist;
Wordlist wordlist,*head;
FILE *in;
int read(char *word);
void Insert(char *word);
int main()
{
    
    char word[1024];
    head=(Wordlist *)malloc(sizeof(Wordlist));
    head->next=NULL;
    in=fopen("article.txt","r");
    while(read(word)!=EOF)
    {
        Insert(word);
    }
     Wordlist *cur=head->next;
     while(cur!=NULL)
     {
         printf("%s %d\n",cur->c,cur->num);
         cur=cur->next;
     }
    fclose(in);
    return 0;
}
int read(char *word)
{
    char ch;
    while(!isalpha(ch = fgetc(in)))
    if(ch==EOF)return ch;
    if(!isalpha(ch))return -1;
    else *(word++)=tolower(ch);
    while(isalpha(ch=getc(in))){
        *(word++)=tolower(ch);
    }
    *word='\0';
    return 1;
}
void Insert(char *word)
{
    Wordlist *cur=head;
    if(cur->next==NULL){
    	Wordlist *temp=(Wordlist *)malloc(sizeof(Wordlist));
    	cur->next=temp; 
        strcpy(temp->c,word);
        temp->num=1;
        temp->next=NULL;
        return;
    }
    else{
        int judge=strcmp(cur->next->c,word);
        if(judge>0){
            Wordlist *temp=(Wordlist *)malloc(sizeof(Wordlist)),*cur1;
            cur1=head->next;
            head->next=temp;
            temp->next=cur1;
            strcpy(temp->c,word);
            temp->num=1;
            return;
        }
        while(cur->next!=NULL&&(judge=strcmp(cur->next->c,word))<0){
            cur=cur->next;
        }
        if(judge==0)
        {
            cur->next->num++;
            return;
        }
        else{
            Wordlist *temp=(Wordlist *)malloc(sizeof(Wordlist)),*cur1;
            if(cur->next!=NULL){
                cur1=cur->next;
                cur->next=temp;
                temp->next=cur1;
            }
            else{
            cur->next=temp;
            temp->next=NULL;
            }
        strcpy(temp->c,word);
        temp->num=1;
        }
    }
}



