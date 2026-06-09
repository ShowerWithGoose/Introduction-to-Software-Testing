#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node{
    char word[1000];
    int time;
    struct node* next;
    struct node* before;
}wordlist;
    char copy_word[1000]="";
      char str[10000];
int flag=0;
int main()
{
    int pp=1;
    FILE *in;
    in=fopen("article.txt","r");
    wordlist *start=(wordlist *)malloc(sizeof(wordlist));
    start->next=NULL;
    start->before=NULL;
    wordlist *head=(wordlist *)malloc(sizeof(wordlist));
    head->next=NULL;
    head->before=NULL;

    char copy;
    int word_number=0;
    while((copy=fgetc(in))!=EOF)
    {
        copy_word[word_number++]=copy;

    }

    for(int i=0;i<word_number;i++)
    {
        if(!((copy_word[i]>='A'&&copy_word[i]<='Z')||(copy_word[i]>='a'&&copy_word[i]<='z')))
        {
            copy_word[i]='%';
        }
    }
    copy_word[word_number-1]='\0';
    char list_word[5000][50];
    int list_number=1;
    for(int i=0;i<word_number-2;i++)
    {
        int j=0;
        if(copy_word[i]!='%')
        {

            j=0;
            while(copy_word[i+j]!='%')
            {
                list_word[list_number][j]=copy_word[i+j];
                j++;
            }
            list_number++;
            list_word[list_number-1][i+j]='\0';
            i=i+j-1;
        }

    }
    for(int i=1;i<=list_number-1;i++)
    {
        int len_list_word=strlen(list_word[i]);
        for(int k=0;k<len_list_word;k++)
        {
            if(list_word[i][k]>='A'&&list_word[i][k]<='Z')
            {
                list_word[i][k]=list_word[i][k]-'A'+'a';
            }
        }
    }
    int pq=0;
    while(pq<=list_number-1)
    {
        pq++;
        wordlist *temp=(wordlist *)malloc(sizeof(wordlist));
        strcpy(temp->word,list_word[pq]);
        temp->time=1;
        temp->next=NULL;
        temp->before=NULL;
        int j=0;
        if(flag==0)
        {
            start=temp;
            flag=1;
        }
        else
        {

            head=start;
            while(strcmp(head->word,temp->word)<0&&head->next!=NULL)
            {
                head=head->next;
            }

            if(head->before==NULL)
            {
                if(strcmp(head->word,temp->word)==0)
                {
                    head->time++;
                }
                else if(strcmp(head->word,temp->word)>0)
                {
                    start->before=temp;
                    temp->next=start;
                    start=start->before;
                }
                else if(strcmp(head->word,temp->word)<0)
                {
                    start->next=temp;
                    temp->before=start;
                }
            }
            else if(head->next==NULL&&strcmp(head->word,temp->word)>=0)
            {
                if(strcmp(head->word,temp->word)==0)
                {
                    head->time++;
                }
                else
                {
                    head->before->next=temp;
                    temp->before=head->before;
                    temp->next=head;
                    head->before=temp;
                }
            }
            else if(head->next==NULL&&strcmp(head->word,temp->word)<0)
            {
                head->next=temp;
                temp->before=head;
            }
            else
            {
                if(strcmp(head->word,temp->word)==0)
                {
                    head->time++;
                }
                else if(strcmp(head->word,temp->word)>0)
                {
                    head->before->next=temp;
                    temp->before=head->before;
                    temp->next=head;
                    head->before=temp;
                }
                else if(strcmp(head->word,temp->word)<0)
                {
                    temp->next=head->next;
                    head->next->before=temp;
                    head->next=temp;
                    temp->before=head;
                }
            }
        }
    }
    head=start->next;
    while(head!=NULL)
    {
        printf("%s %d\n",head->word,head->time);
        head=head->next;
    }
    fclose(in);
    return 0;
}



