#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define f(a) ((a)>='a'&&(a)<='z')
#define g(a) ((a)>='A'&&(a)<='Z')
typedef struct Node{
    char *s;
    int num;
    struct Node *next;
}node;
void create(node **list,char word[]){
    if (!*list){
        node *m=(node *)malloc(sizeof(node));
        m->s=(char *)malloc(sizeof(word));
        m->num=1;
        m->next=NULL;
        strcpy(m->s,word);
        *list=m;
    }else{
        node *q=*list;
        while (strcmp(q->s,word)<0 && q->next!=NULL)
        q=q->next;
        
        int a=strcmp(q->s,word);
        if (a==0) q->num++;
        else if (a>0){
            node *m=(node *)malloc(sizeof(node));
            m->s=(char *)malloc(sizeof(word));
            m->num=1;
            m->next=q;
            strcpy(m->s,word);
            
            if (strcmp((*list)->s,word)>0) *list=m;
            else{
                node *base=*list;
                while (strcmp(base->next->s,word)<0)
                base=base->next;
                base->next=m;
            }
        }else{
            node *m=(node *)malloc(sizeof(node));
            m->s=(char *)malloc(sizeof(word));
            m->num=1;
            m->next=NULL;
            strcpy(m->s,word);
            q->next=m;
        }
    }
    
}
void print(node **list){
    while (*list){
        node *tem=*list;
        printf("%s %d\n",(*list)->s,(*list)->num);
        *list=(*list)->next;
//        free(tem->s);
//        free(tem);
    }
}
char s[100000],word[50];
int main(){
    FILE *in;
    in=fopen("article.txt","r");
    
    node *list=NULL;
    while (fgets(s,100000,in)){
        int i=0,j=0;
        while(s[i]!='\0'){
            if (f(s[i])) word[j++]=s[i];
            else if (g(s[i])) word[j++]=s[i]+32;
            else if (s[i]==' '){ // @@ [Error: Only spaces are handled as word separators. Non‑letter characters (digits, punctuation) are ignored, causing letters from adjacent tokens to be concatenated (e.g., "since" + "c" → "sincec"). Should treat any non‑letter as a word boundary and only create word when j>0.]
                word[j]='\0';
                create(&list,word);
                j=0;
            } 
            i++;
        }
        if (j!=0){
            word[j]='\0';
            create(&list,word);
        }
    }
    
    print(&list);
    fclose(in);
    
    return 0;
}