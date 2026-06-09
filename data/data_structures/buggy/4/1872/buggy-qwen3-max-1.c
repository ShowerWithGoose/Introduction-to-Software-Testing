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
    char c=fgetc(rstream); // @@ [If the file does not exist or cannot be opened, rstream will be NULL, and fgetc(NULL) causes undefined behavior.]
    while(c!=EOF) {
        q=(lnode)malloc(sizeof(node)); // @@ [Memory is allocated for every loop iteration even if the character sequence is not a valid word (e.g., punctuation-only).]
        q->n=0;
        for( i=0; c!=' '&&c!='\n'; i++) { // @@ [This condition fails to stop on non-alphabetic characters like punctuation, causing invalid words to be processed. Also, if c==EOF at start, loop condition may not handle it correctly.]
            if(c>='A'&&c<='Z') {
                c=c+32;
                q->s[i]=c;
            } else if(c>='a'&&c<='z') {
                q->s[i]=c;
            } else {
                i=i-1; // @@ [This decrements i for non-letter characters but continues reading, which can lead to incorrect word boundaries and buffer overruns if many non-letters appear.]
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
            for(d1=list; d1!=r; d1=d1->p) { // @@ [Loop condition assumes list and r form a proper linked list with r reachable from list, but insertion logic may break this assumption, leading to infinite loops or missed comparisons.]
                if(strcmp(q->s,d1->s)==0) {
                    d1->n++;
                } else if(strcmp(q->s,d1->s)>0&&strcmp(q->s,d1->p->s)<0) { // @@ [Accessing d1->p without checking if it's NULL leads to segmentation fault when d1 is the last node.]
                    q->p=d1->p;
                    d1->p=q;
                    q->n++;//有待商榷
                    d1=d1->p;
                }
            }
            

        }}}

    c=fgetc(rstream); } // @@ [After inner loop ends due to space/newline, this reads next char but skips processing if it's EOF immediately after whitespace, potentially missing last word. Also, if file ends without newline, last word might not be processed correctly.]
    for(d2=list; d2!=NULL; d2=d2->p) {
        printf("%s %d\n",d2->s,d2->n);
    }
    fclose(rstream);
    return 0;
}