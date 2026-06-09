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
        for( i=0; c!=' '&&c!='\n'; i++) { // @@ [This loop condition incorrectly assumes words are only separated by space or newline, but problem defines word as sequence of letters; non-letter characters (like digits, punctuation) should terminate a word, but this loop continues reading them as part of the word until space/newline, causing incorrect parsing and potentially infinite loops if file ends without space/newline. Also, it doesn't handle EOF inside the loop properly.]
            if(c>='A'&&c<='Z') {
                c=c+32;
                q->s[i]=c;
            } else if(c>='a'&&c<='z') {
                q->s[i]=c;
            } else {
                i=i-1; // @@ [This decrements i to "undo" non-letter, but loop still consumes the character and continues; however, if the next character is also non-letter (e.g., '1972'), it keeps looping without advancing i, potentially causing infinite loop if many non-letters appear before space/newline. Also, after decrementing i, the next fgetc may read EOF, but loop condition doesn't check it until next iteration.]
            }
            c=fgetc(rstream); // @@ [If fgetc returns EOF here, the loop condition (c != ' ' && c != '\n') will treat EOF as a valid non-space/non-newline character and continue looping indefinitely because EOF != ' ' and EOF != '\n', leading to infinite loop and Time Limit Exceeded.]
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
            for(d1=list; d1!=r; d1=d1->p) { // @@ [This loop does not correctly traverse or insert in sorted order; it assumes a linear structure between list and r, but r is only updated in one branch, so in many cases r may not point to the tail, causing incomplete traversal. Also, when a match is found (strcmp==0), it increments count but continues looping, potentially inserting duplicate nodes later. Moreover, after inserting a new node in the middle, the loop variable d1 is modified (d1=d1->p), which interferes with the for-loop increment, possibly causing infinite loop or skipped nodes.]
                if(strcmp(q->s,d1->s)==0) {
                    d1->n++;
                } else if(strcmp(q->s,d1->s)>0&&strcmp(q->s,d1->p->s)<0) {
                    q->p=d1->p;
                    d1->p=q;
                    q->n++;//有待商榷
                    d1=d1->p; // @@ [Modifying loop variable inside loop body breaks the for-loop logic, leading to undefined traversal behavior and potential infinite loops.]
                }
            }
            

        }}}

    c=fgetc(rstream); } // @@ [This reads next character after processing a word, but if the inner for-loop exited due to EOF, this will read again and set c to EOF, then the outer while condition checks c!=EOF and exits. However, the main issue is that the inner loop can get stuck on non-letter, non-space, non-newline characters (like digits or punctuation) and never exit, especially near EOF, causing Time Limit Exceeded.]
    for(d2=list; d2!=NULL; d2=d2->p) {
        printf("%s %d\n",d2->s,d2->n);
    }
    fclose(rstream);
    return 0;
}