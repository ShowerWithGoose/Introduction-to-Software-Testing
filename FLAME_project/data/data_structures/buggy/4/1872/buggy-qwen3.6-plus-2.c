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
    char c=fgetc(rstream);
    while(c!=EOF) {
        q=(lnode)malloc(sizeof(node));
        q->n=0;
        for( i=0; c!=' '&&c!='\n'; i++) { // @@ The loop condition only checks for space and newline, but fails to check for EOF. If the file ends without a trailing newline or space, fgetc returns EOF, which is not ' ' or '\n', causing an infinite loop inside this for loop as c remains EOF. Additionally, it doesn't handle other non-letter characters correctly as word delimiters in all cases, potentially leading to logic errors or infinite loops if non-letter, non-space/non-newline chars are present.
            if(c>='A'&&c<='Z') {
                c=c+32;
                q->s[i]=c;
            } else if(c>='a'&&c<='z') {
                q->s[i]=c;
            } else {
                i=i-1;
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
            for(d1=list; d1!=r; d1=d1->p) { // @@ This traversal logic is flawed. It assumes 'r' is always the last node, which might not be true if insertions happen in the middle or beginning after 'r' was set. More critically, if the word is not found and doesn't fit between d1 and d1->p, the loop finishes without inserting or handling the word, leading to memory leaks and incorrect counts. Also, if d1->p is NULL (d1 is last), accessing d1->p->s in the condition below causes a crash.
                if(strcmp(q->s,d1->s)==0) {
                    d1->n++;
                } else if(strcmp(q->s,d1->s)>0&&strcmp(q->s,d1->p->s)<0) { // @@ Accessing d1->p->s when d1->p is NULL (i.e., d1 is the last node 'r') leads to undefined behavior/crash. Even if not NULL, this logic only inserts if it fits strictly between d1 and d1->p, failing to append at the end if it's greater than 'r'.
                    q->p=d1->p;
                    d1->p=q;
                    q->n++;//有待商榷
                    d1=d1->p;
                }
            }
            

        }}}

    c=fgetc(rstream); } // @@ This read is outside the inner processing but inside the main while loop. However, because the inner for loop consumes characters until a delimiter, this line reads the next character after the delimiter. If the previous for loop terminated due to EOF (which it shouldn't have due to the bug mentioned above, but logically), c would be EOF. The main while loop checks c!=EOF. If the file ends with a word followed by EOF (no trailing newline/space), the for loop hangs. If it ends with a delimiter, this reads the next char. This structure is fragile and coupled with the for-loop bug.
    for(d2=list; d2!=NULL; d2=d2->p) {
        printf("%s %d\n",d2->s,d2->n);
    }
    fclose(rstream);
    return 0;
}