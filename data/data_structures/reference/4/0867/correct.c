//
// Created by  on 2022-03-24.
//

#include<stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
int getWord(FILE *IN,char dest[]){
    char c = fgetc(IN);
    int pos = 0;
    while(c!=EOF){
        if(isalpha(c)!=0){
            dest[pos++] = tolower(c);
        }else if(pos>0){
            dest[pos] = '\0';
            return 1;
        }
        c = fgetc(IN);
    }
    return -1;
}

typedef struct wordnode{
    char* word;
    int appear;
    struct wordnode* next;
}*nodeptr;

int recWord(nodeptr head,char* dest){
    for(head;head;head = head->next){
        if(strcmp(head->word,dest)==0){
            head->appear++;
            return 1;
        }
    }
    return 0;
}

int main(){
    FILE *IN;
    if((IN = fopen("article.txt","r"))==NULL){
        printf("in error");
        exit(0);
    }
    char* wd = malloc(sizeof(char)*50);
    nodeptr head = NULL,tail = NULL;
    while(getWord(IN,wd)!=-1){
        if(!head){
            head = malloc(sizeof(struct wordnode));
            head->next = NULL;
            head->appear = 1;
            head->word = wd;
            tail = head;
        }else if(!recWord(head,wd)){
            tail->next = malloc(sizeof(struct wordnode));
            tail = tail->next;
            tail->next = NULL;
            tail->appear = 1;
            tail->word = wd;
        }
        wd = malloc(sizeof(char)*50);
    }
    //swap linked-list node
    int swapflag = 1;
    while(swapflag){
        swapflag = 0;
        nodeptr fast = head->next;
        nodeptr slow = head;
        for(;fast;fast = fast->next,slow = slow->next){
            if(strcmp(slow->word,fast->word)>0){
                //swap it!
                char* tmp;
                tmp = slow->word;
                slow->word = fast->word;
                fast->word = tmp;
                swapflag = 1;
                int tmp2;
                tmp2 = slow->appear;
                slow->appear = fast->appear;
                fast->appear = tmp2;
            }
        }
    }
    for(;head;head = head->next){
        printf("%s %d\n",head->word,head->appear);
    }
}



