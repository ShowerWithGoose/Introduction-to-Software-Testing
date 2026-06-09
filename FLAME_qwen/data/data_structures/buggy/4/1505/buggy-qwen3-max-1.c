#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
    char word[100];
    int n;
    struct node *next;
}subject;

void exam(struct node *start,char *str){
    struct node *p,*q;
    int judge=0;
    for(p=start;;p=p->next){
        if(strcmp(p->word,str)==0){
            p->n++;
            judge=1;
        }
        if(p->next==NULL){
            break;
        }
    }
    if(judge==0){
        q=(struct node*)malloc(sizeof(subject));
        strcpy(q->word,str);
        q->n=1;
        q->next=NULL;
        p->next=q;
        p=q;
    }
}

int number(struct node *start){
    struct node *p;
    int num=0;
    for(p=start;;p=p->next){
        num++;
        if(p->next==NULL){
            break;
        }
    }
    return num;
}

void order(struct node *start,int num){
    int i;
    struct node *p;
    int k=0;
    char gapStr[100];
    int gapN;
    for(i=num-1;i>=1;i--){
        k=0;
        for(p=start;;p=p->next){
            if(strcmp(p->word,p->next->word)>0){
                strcpy(gapStr,p->word);
                gapN=p->n;
                strcpy(p->word,p->next->word);
                p->n=p->next->n;
                strcpy(p->next->word,gapStr);
                p->next->n=gapN;
            }
            k++;
            if(k==i){
                break;
            }
        }
    }
}

void change(char *str){
    int i;
    for(i=0;i<=strlen(str)-1;i++){
        if(str[i]>='A'&&str[i]<='Z'){
            str[i]=str[i]+'a'-'A';
        }
    }
}

int range(char c){
    if((c>='a'&&c<='z') || (c>='A'&&c<='Z')){
        return 1;
    }
    else{
        return 0;
    }
}

void changeTXT(FILE *fpin,FILE *fpnew){
    char c;
    while(1){
        if(c==EOF){
            break;
        }
        c=fgetc(fpin); @@ [The variable 'c' is used before being initialized. The first check 'if(c==EOF)' uses an uninitialized value, which leads to undefined behavior.]
        if(range(c)==0){
            fputc(' ',fpnew);
        }
        else{
            fputc(c,fpnew);
        }
    }
}

int main(){
    FILE *fpin;
    fpin=fopen("article.txt","r");
    FILE *fpnew;
    fpnew=fopen("new.txt","w");
    changeTXT(fpin,fpnew);
    fclose(fpnew);
    fpnew=fopen("new.txt","r");
    rewind(fpnew);
    char str[100];
    struct node *start;
    struct node *p;
    start=p=(struct node*)malloc(sizeof(subject));
    fscanf(fpnew,"%s",str);
    change(str);
    strcpy(start->word,str);
    start->n=1;
    start->next=NULL;
    while(1){
        fscanf(fpnew,"%s",str);
        change(str);
        exam(start,str);
        if(fgetc(fpnew)==EOF){
            break;
        }
    }
    order(start,number(start));
    for(p=start;;p=p->next){
        printf("%s %d\n",p->word,p->n);
        if(p->next==NULL){
            break;
        }
    }
    fclose(fpin);
    fclose(fpnew);
}