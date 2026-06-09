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
    lnode q,r,list=NULL,d1,d2;
    char c=fgetc(rstream); // @@ [If the file fails to open, rstream will be NULL, and fgetc(NULL) causes undefined behavior (likely crash).]
    while(c!=EOF) {
        q=(lnode)malloc(sizeof(node)); // @@ [Memory is allocated for every loop iteration even if the character sequence isn't a valid word; also, no check for malloc failure.]
        q->n=0;
        for( i=0; c!=' '&&c!='\n'; i++) { // @@ [This condition doesn't account for other non-letter characters like punctuation or tabs, violating the problem's word definition. Also, if c==EOF initially, this loop may still run incorrectly.]
            if(c>='A'&&c<='Z') {
                c=c+32;
                q->s[i]=c;
            } else if(c>='a'&&c<='z') {
                q->s[i]=c;
            } else {
                i=i-1; // @@ [This attempts to "undo" non-letter characters but can cause negative index if first char is non-letter, leading to buffer underflow.]
            }
            c=fgetc(rstream);
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
         if(strcmp(q->s,r->s)==0) {
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
            for(d1=list; d1!=r; d1=d1->p) { // @@ [The loop condition assumes a linear structure from list to r, but insertion logic doesn't maintain consistent forward links; also, d1->p may be NULL inside loop causing strcmp with NULL.]
                if(strcmp(q->s,d1->s)==0) {
                    d1->n++;
                } else if(strcmp(q->s,d1->s)>0&&strcmp(q->s,d1->p->s)<0) { // @@ [d1->p could be NULL here (e.g., at last node), leading to dereferencing NULL in strcmp.]
                    q->p=d1->p;
                    d1->p=q;
                    q->n++;//有待商榷
                    d1=d1->p;
                }
            }
            

        }}}

    c=fgetc(rstream); } // @@ [After inner loop reads until space/newline, this extra fgetc skips the next character, potentially skipping letters or causing misalignment.]
    for(d2=list; d2!=NULL; d2=d2->p) {
        printf("%s %d\n",d2->s,d2->n);
    }
    fclose(rstream);
    return 0;
}