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
    char c; // @@ The variable 'c' is used uninitialized in the first iteration of the loop. It should be initialized or the check should happen after reading.
    while(1){
        if(c==EOF){ // @@ This check uses the uninitialized value of 'c' (or the previous character) before reading a new one. More critically, fgetc returns an int, and assigning it to char can lose the EOF value (usually -1) if char is unsigned, causing an infinite loop or incorrect termination.
            break;
        }
        c=fgetc(fpin); // @@ Reading into a char variable is problematic for EOF detection. Should be int. Also, this logic replaces non-letters with spaces, which is fine, but the EOF handling is flawed.
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
        fscanf(fpnew,"%s",str); // @@ If fscanf fails (e.g., at EOF), str remains unchanged or undefined, leading to processing garbage or duplicate data. The return value of fscanf should be checked.
        change(str);
        exam(start,str);
        if(fgetc(fpnew)==EOF){ // @@ This consumes a character from the file to check for EOF. This disrupts the reading flow because fscanf already advanced the file pointer past whitespace. This extra fgetc might skip valid characters or cause premature termination/skipping of words. Specifically, it reads one char after the word. If that char is EOF, it breaks. But if it's a space or next letter, it's consumed and lost, causing the next fscanf to start mid-word or skip content. This is the primary cause of the wrong count for "you" (likely missing the last occurrence or merging words incorrectly).
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