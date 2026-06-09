#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

FILE* in;
char w[30];

struct word{
    char s[30];
    int f;
    struct word* link;
};

int getword(){
    int i,res=0,quit=0;
    char c;
    while(c=fgetc(in)){
    	if(c==EOF)
    		break;
        i=0;
        while(isalpha(c)){
        	if(isupper(c)){
        		c=c-'A'+'a';
			}
            w[i++]=c;
            c=fgetc(in);
            quit=1;
        }
        w[i]='\0';
        if(w[0])
            res=1;
        if(quit)
            break;
    }
    return res;
}
int main(){
    in=fopen("article.txt","r");
    int i,get,repeat;
    struct word *list,*p,*q,*r;
    list=(struct word*)malloc(sizeof(struct word));
    get=getword();
    if(get){
        strcpy(list->s,w);
        list->f=1;
        list->link=NULL;
    }
    r=list;
    while(get=getword()){
        repeat=0;
        p=list;
        while(p->link!=NULL){
            if(strcmp(p->s,w)==0){
                repeat=1;
                break;
            }
            p=p->link;
        }
        if(strcmp(p->s,w)==0){
            repeat=1;
        }
        if(repeat){
            p->f++;
        } else{
            p=(struct word*)malloc(sizeof(struct word));
            strcpy(p->s,w);
            p->f=1;
            q=list;
            if(strcmp(list->s,p->s)>0){
                p->link=list;
                list=p;
            } else
            while(q->link!=NULL){
                r=q->link;
                if(strcmp(r->s,p->s)>0){
                    q->link=p;
                    p->link=r;
                    break;                    
                }
                q=q->link;
            }
            if(q->link==NULL){
                q->link=p;
                p->link=NULL;
            }
        }
    }
    p=list;
    while(p->link!=NULL){
        printf("%s %d\n",p->s,p->f);
        r=p;
        p=p->link;
        free(r);
    }
    printf("%s %d\n",p->s,p->f);
    free(p);
    fclose(in);
    return 0;
}



