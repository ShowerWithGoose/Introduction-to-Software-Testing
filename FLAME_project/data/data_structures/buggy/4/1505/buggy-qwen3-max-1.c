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
        c=fgetc(fpin);
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
    changeTXT(fpin,fpnew); @@ // The variable 'c' is used uninitialized in the first iteration of the loop; also, the loop condition checks 'c==EOF' before reading, causing the first character to be skipped and potentially missing the EOF check correctly.
    fclose(fpnew);
    fpnew=fopen("new.txt","r");
    rewind(fpnew);
    char str[100];
    struct node *start;
    struct node *p;
    start=p=(struct node*)malloc(sizeof(subject));
    fscanf(fpnew,"%s",str); @@ // If the file is empty or the first read fails, this leads to undefined behavior; also, no check for successful read.
    change(str);
    strcpy(start->word,str);
    start->n=1;
    start->next=NULL;
    while(1){
        fscanf(fpnew,"%s",str); @@ // This reads a word, but then the next fgetc() consumes the next character (possibly part of the next word or whitespace), leading to skipping words or incorrect EOF detection.
        change(str);
        exam(start,str);
        if(fgetc(fpnew)==EOF){ @@ // Using fgetc after fscanf disrupts the input stream; it consumes one extra character after each word, which may skip delimiters or parts of words, and causes the last word to be processed twice or missed.
            break;
        }
    }
    order(start,number(start)); @@ // The bubble sort implementation assumes at least two nodes; if there's only one word, accessing p->next->word leads to dereferencing NULL.
    for(p=start;;p=p->next){
        printf("%s %d\n",p->word,p->n);
        if(p->next==NULL){
            break;
        }
    }
    fclose(fpin);
    fclose(fpnew);
}