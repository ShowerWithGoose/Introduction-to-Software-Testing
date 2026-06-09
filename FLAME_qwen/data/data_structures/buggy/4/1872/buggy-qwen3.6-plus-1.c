#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
typedef struct node {
    char s[100];
    int n;
    struct node*p;
} node,*lnode;
int main() {
    FILE*rstream=fopen("article.txt","rb");
    char s1[1005];
    int i;
    lnode q,r,list=NULL,d1,d2; // @@ r is uninitialized, which will cause undefined behavior or segmentation fault when accessed before assignment
    char c=fgetc(rstream); // @@ c should be declared as int to correctly store the EOF value returned by fgetc
    while(c!=EOF) { // @@ comparing a char variable with EOF is unreliable and may fail to detect end of file
        q=(lnode)malloc(sizeof(node));
        q->n=0;
        for( i=0; c!=' '&&c!='\n'; i++) { // @@ loop condition only checks for space and newline, but should terminate on any non-letter character or EOF
            if(c>='A'&&c<='Z') {
                c=c+32;
                q->s[i]=c;
            } else if(c>='a'&&c<='z') {
                q->s[i]=c;
            } else {
                i=i-1; // @@ incorrectly handles non-letter delimiters; does not properly terminate the current word or handle EOF
            }
            c=fgetc(rstream); // @@ reads next character without checking for EOF, potentially causing an infinite loop at the end of the file
        }//记录了一个词
       if(i!=0){
       
       q->s[i]='\0';
        if(list==NULL) {
            q->p=NULL;
            list=q;
            list->n=(list->n)+1;
        } else if(list->p==NULL) {
            if(strcmp(q->s,list->s)<0) {
                q->p=list;
                list=q;
                list->n++;
            } else if(strcmp(q->s,list->s)==0) {
                list->n=(list->n)+1;
            } else if(strcmp(q->s,list->s)>0) {
                q->n++;
                list->p=q;
                r=q;
                r->p=NULL;
            }
        } else {
         if(strcmp(q->s,r->s)==0) { // @@ r may still be uninitialized if the second word was inserted at the head, leading to a crash
                r->n++;
            } else if(strcmp(q->s,r->s)>0) {
                q->n++;
                r->p=q;
                r=q;
                r->p=NULL;
            }else if(strcmp(q->s,list->s)<0) {
                    q->p=list;
                    list=q;
                    list->n++;
                } else {
            for(d1=list; d1!=r; d1=d1->p) { // @@ modifying the loop variable d1 inside the loop body disrupts the linked list traversal
                if(strcmp(q->s,d1->s)==0) {
                    d1->n++;
                } else if(strcmp(q->s,d1->s)>0&&strcmp(q->s,d1->p->s)<0) {
                    q->p=d1->p;
                    d1->p=q;
                    q->n++;//有待商榷 // @@ q is allocated but never freed when a duplicate is found, causing a memory leak; count logic is also flawed
                    d1=d1->p;
                }
            }
            

        }}}

    c=fgetc(rstream); } // @@ extra fgetc call skips valid characters and mishandles EOF detection
    for(d2=list; d2!=NULL; d2=d2->p) {
        printf("%s %d\n",d2->s,d2->n);
    }
    fclose(rstream);
    return 0;
}