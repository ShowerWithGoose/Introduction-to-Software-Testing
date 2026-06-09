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
    char c=fgetc(rstream); // @@ [If the file fails to open, rstream is NULL and fgetc(NULL) causes undefined behavior (likely crash).]
    while(c!=EOF) {
        q=(lnode)malloc(sizeof(node)); // @@ [No check for malloc failure; if allocation fails, q is NULL and subsequent accesses cause crashes.]
        q->n=0;
        for( i=0; c!=' '&&c!='\n'; i++) { // @@ [This loop condition does not handle non-alphabetic characters correctly per problem definition; it treats any non-space/non-newline as part of a word, including punctuation and digits. Also, if c is EOF at start, loop condition may still pass incorrectly.]
            if(c>='A'&&c<='Z') {
                c=c+32;
                q->s[i]=c;
            } else if(c>='a'&&c<='z') {
                q->s[i]=c;
            } else {
                i=i-1; // @@ [This decrements i to "undo" non-letter, but doesn't skip the character properly; also, if multiple non-letters occur, this logic breaks. Moreover, buffer overflow possible if too many letters.]
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
            for(d1=list; d1!=r; d1=d1->p) { // @@ [This loop assumes list and r form a proper linked list with r being the tail, but r is only updated in one branch; in other cases, r may be stale or uninitialized, leading to infinite loop or crash. Also, d1->p may be NULL inside loop, causing strcmp(q->s,d1->p->s) to dereference NULL.]
                if(strcmp(q->s,d1->s)==0) {
                    d1->n++;
                } else if(strcmp(q->s,d1->s)>0&&strcmp(q->s,d1->p->s)<0) { // @@ [d1->p could be NULL here, leading to segmentation fault when accessing d1->p->s.]
                    q->p=d1->p;
                    d1->p=q;
                    q->n++;//有待商榷
                    d1=d1->p;
                }
            }
            

        }}}

    c=fgetc(rstream); } // @@ [After inner loop reads until space/newline, this reads next char, but skips processing of words that end at EOF without trailing space/newline. Also, if file ends right after a word, last word might be missed or processed incorrectly.]
    for(d2=list; d2!=NULL; d2=d2->p) {
        printf("%s %d\n",d2->s,d2->n);
    }
    fclose(rstream);
    return 0;
}