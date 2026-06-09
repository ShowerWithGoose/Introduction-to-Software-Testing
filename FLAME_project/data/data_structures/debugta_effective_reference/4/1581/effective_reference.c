#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct word{
    char s[20];
    int count;
    struct word* link;
};
typedef struct word Node;
typedef struct word* Nodeptr;
int getWord(char line[],FILE* in);
Nodeptr insert(char line[],Nodeptr list);
void print(Nodeptr list);
int judge(char c);
int main(){
    FILE *in;
    in = fopen("article.txt","r");
    char line[20]={'\0'};
    Nodeptr list = NULL;
    while(getWord(line,in)!=EOF){
     //   printf("%s ",line);
        list = insert(line,list);
    }
    print(list);
    return 0;
}

void print(Nodeptr list){
        Nodeptr q=list,r=list;
    while(q!=NULL){
        printf("%s %d\n",q->s,q->count);
        r = q;
        q = q->link;
        free(r);
    }
}

int getWord(char line[],FILE* in){
    char c='\0';
    int j = 0;
    while((fscanf(in,"%c",&c)!=EOF)){
        if(judge(c)!=0)
            break;
    }
    while(c!='\0'){
        if(judge(c)==1){
            line[j++] = c - 'A' + 'a';
        }else if(judge(c)==2){
            line[j++] = c;
        }else
            break;
        fscanf(in,"%c",&c);
    }

    line[j] = '\0';
    if(line[0]=='\0')
        return -1;
    else
        return 1;
}

Nodeptr insert(char line[],Nodeptr list){
    Nodeptr q,p = list,r = list;
    q = (Nodeptr)malloc(sizeof(Node));
    strcpy( q->s , line);
    q->count = 1;
    q->link = NULL;

    if(list==NULL)
            list = q;
    else{
        while(p!=NULL){
            if(strcmp(p->s,line)==0){
                p->count ++;
                free(q);
                break;
            }else if(strcmp(p->s,line)>0){
                if(p == list){
                    q->link = list;
                    list = q;
                }else{
                    q->link = p;
                    r->link = q;
                }
                    break;
            }
            p = p->link;
            if(r->link!=p)
                r = r->link;
        }
        if(p == NULL){
            r->link = q;
        }
    }
    return list;
}

int judge(char c){
    if(c>='A'&&c<='Z')
        return 1;
    else if(c>='a'&&c<='z')
        return 2;
    else return 0;
}

