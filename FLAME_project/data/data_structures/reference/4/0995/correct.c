#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct words
{
    char word[20];
    int freq;
    struct words *next;
}WORD;

int main()
{
    FILE *in;
    in=fopen("article.txt","r");
    char txt[10000];
    char str[10000]={'\0'};
    while(fgets(txt,10000,in)!=NULL){
        strcat(str,txt);
    }
    //str字符串记下整个文本
    for(int i=0;str[i];i++){
        if(str[i]>=65&&str[i]<=90){
            str[i]+=32;
        }
    }//转小写
    WORD *head=NULL,*tail=NULL,*pos=NULL;
    WORD *p=(WORD *)malloc(sizeof(WORD));
    head=tail=p;
    int N=1;
    p->word[0]='\0';
    for(int i=0;str[i];i++){
        if(str[i]>=97&&str[i]<=122){
            char buf[2]={'\0'};
            buf[0]=str[i];
            strcat(tail->word,buf);
        }else{
            if(!i){
                continue;
            }
            if(str[i+1]>=97&&str[i+1]<=122){
                WORD *p=(WORD *)malloc(sizeof(WORD));
                tail->next=p;
                tail=p;
                p->word[0]='\0';
                N++;
            }
        }
    }
    for(int i=0;i<N;i++){
        pos=head;
        for(int j=0;j<N-1;j++){
            if(strcmp(pos->word,pos->next->word)>0){
                char temp[20];
                strcpy(temp,pos->word);
                strcpy(pos->word,pos->next->word);
                strcpy(pos->next->word,temp);
            }
            pos=pos->next;
        }
    }
    int times=1;
    pos=head;
    WORD *Ntail=(WORD *)malloc(sizeof(WORD));
    tail->next=Ntail;
    Ntail->next=NULL;
    Ntail->word[0]='\0';
    for(int i=0;i<N;i++){
        if(strcmp(pos->word,pos->next->word)==0){
            times++;
            pos=pos->next;
        }else{
            printf("%s %d\n",pos->word,times);
            times=1;
            pos=pos->next;
        }
    }
    for(int i=0;i<N;i++){
        pos=head;
        head=head->next;
        free(pos);
    }
    system("pause");
    return 0;
}
