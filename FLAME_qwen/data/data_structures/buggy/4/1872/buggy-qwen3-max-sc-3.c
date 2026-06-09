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
    char c=fgetc(rstream); // @@ [If the file does not exist or cannot be opened, rstream will be NULL, and fgetc(NULL) causes undefined behavior (likely crash).]
    while(c!=EOF) {
        q=(lnode)malloc(sizeof(node)); // @@ [Memory is allocated for every loop iteration even if the character sequence is not a valid word (e.g., punctuation-only), leading to memory leaks and incorrect word parsing.]
        q->n=0;
        for( i=0; c!=' '&&c!='\n'; i++) { // @@ [This condition assumes words are only separated by space or newline, but problem defines word as alphabetic sequence; non-alphabetic characters like commas, periods should also terminate words. Also, if c is EOF at start, loop condition fails but allocation already happened.]
            if(c>='A'&&c<='Z') {
                c=c+32;
                q->s[i]=c;
            } else if(c>='a'&&c<='z') {
                q->s[i]=c;
            } else {
                i=i-1; // @@ [This attempts to skip non-letter characters but doesn't consume them properly; it may cause infinite loops or incorrect indexing because c is not updated inside the else block before next iteration.]
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
            for(d1=list; d1!=r; d1=d1->p) { // @@ [The loop condition d1 != r assumes r is always the last node, but r is only updated in specific branches; if insertion happens in middle, r becomes stale, causing incorrect traversal or infinite loop.]
                if(strcmp(q->s,d1->s)==0) {
                    d1->n++;
                } else if(strcmp(q->s,d1->s)>0&&strcmp(q->s,d1->p->s)<0) { // @@ [d1->p may be NULL when d1 is the last node, leading to dereferencing NULL pointer and crash.]
                    q->p=d1->p;
                    d1->p=q;
                    q->n++;//有待商榷
                    d1=d1->p;
                }
            }
            

        }}}

    c=fgetc(rstream); } // @@ [After inner loop consumes up to space/newline, this reads next char, but if file ends with non-space/non-newline, last word may be missed or extra EOF read causes issues. Also, no check for rstream == NULL before fgetc.]
    for(d2=list; d2!=NULL; d2=d2->p) {
        printf("%s %d\n",d2->s,d2->n);
    }
    fclose(rstream); // @@ [If rstream was NULL (file open failed), fclose(NULL) is safe, but prior fgetc(NULL) already caused undefined behavior.]
    return 0;
}