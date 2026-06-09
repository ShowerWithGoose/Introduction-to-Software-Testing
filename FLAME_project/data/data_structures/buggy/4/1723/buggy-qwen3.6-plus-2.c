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
        m->s=(char *)malloc(strlen(word)+1); // @@ [Error: sizeof(word) returns the size of the pointer (4 or 8), not the length of the string. This causes buffer overflow when copying the word. Should be strlen(word)+1]
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
            m->s=(char *)malloc(strlen(word)+1); // @@ [Error: sizeof(word) returns the size of the pointer, not the string length. Should be strlen(word)+1]
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
            m->s=(char *)malloc(strlen(word)+1); // @@ [Error: sizeof(word) returns the size of the pointer, not the string length. Should be strlen(word)+1]
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
            else { // @@ [Error: The original code only processed words when encountering a space ' '. It failed to treat other non-letter characters (like digits, punctuation, newlines) as delimiters. This caused "since" and "c" from "since1972.C" to be merged into "sincec". Changing to else ensures any non-letter character terminates the current word.]
                if (j > 0) { // @@ [Error: Only process the word if we have accumulated characters. This prevents creating empty words when multiple delimiters appear consecutively.]
                    word[j]='\0';
                    create(&list,word);
                    j=0;
                }
            } 
            i++;
        }
        if (j!=0){
            word[j]='\0';
            create(&list,word);
            j=0; // @@ [Optional but good practice: reset j, though not strictly causing the WA here as it's end of loop/file context usually, but logically consistent with inner loop reset]
        }
    }
    
    print(&list);
    fclose(in);
    
    return 0;
}