#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
struct Word{
    char s[200];
    int n;
    struct Word *next;
};
int main(){
    char ch,str[200];
    int i=0,j;
    FILE *in=fopen("article.txt","r");
    struct Word *head=NULL,*p,*p0,*q;
    p0=(struct Word*)malloc(sizeof(struct Word));
    while(fscanf(in,"%c",&ch)!=EOF){
        if(tolower(ch)>='a'&&tolower(ch)<='z'){
            for(i=0;;ch=fgetc(in)){
                if(tolower(ch)>='a'&&tolower(ch)<='z')
                    str[i++]=tolower(ch);
                else
                    break;
            }
            str[i]='\0'; //important重要重要！！！！！！
        }
        else
            continue;
        if(head==NULL){
            head=p=(struct Word*)malloc(sizeof(struct Word));
            p->n=1;
            strcpy(p->s,str);
            p->next=NULL;
        }
        else{
            q=(struct Word*)malloc(sizeof(struct Word));
            q->n=1;
            strcpy(q->s,str);
            q->next=NULL;
            for(p=head;p!=NULL;p0=p,p=p->next){
                if(strcmp(p->s,q->s)==0){
                    p->n++;
                    break;
                }                    
                else if(strcmp(p->s,q->s)>0){
                    if(p==head){
                        q->next=p;
                        head=q;
                    }
                    else{
                        p0->next=q;
                        q->next=p;
                    }
                    break;
                }
            }
            if(p==NULL)
                p0->next=q;
        }
    }
    
    for(p=head;p!=NULL;p=p->next)
        printf("%s %d\n",p->s,p->n);

    return 0;
}
