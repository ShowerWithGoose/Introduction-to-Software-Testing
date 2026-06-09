#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define ll long long

typedef struct node{
    int n;
    int t;
    struct node *next;
}pol;
pol zero1, zero2, zero3;
pol *head1 = &zero1, *head2 = &zero2, *ans = &zero3;

void creat(pol *pos, int n, int t){//creat on next of pos
    pol *to = pos->next;
    pol *ne = (pol*)malloc(sizeof(pol));
    ne->n = n;
    ne->t = t;
    ne->next = to;
    pos->next = ne;
    return;
}

pol* rsearch(pol *head, int t){//no more than t, if return null means t is the smallest
    pol *pos = head->next;
    while(pos != NULL && pos->t > t){
        pos = pos->next;
    }
    return pos;
}

pol* lsearch(pol *head, int t){//no less than t(may equal)
    pol *pos = head;
    while(pos->next != NULL && pos->next->t > t){
        pos = pos->next;
    }
    return pos;
}


void mult(pol *a, pol *b){
    for(pol *apos = a->next; apos != NULL; apos = apos->next){
        for(pol *bpos = b->next; bpos != NULL; bpos = bpos->next){
            int n = apos->n * bpos->n;
            int t = apos->t + bpos->t;
            pol *loc = rsearch(ans, t);
            if(loc != NULL){
                //t isn't the smallest
                if(loc->t == t){
                    loc->n += n;
                }else{
                    creat(lsearch(ans, t), n, t);
                }
            }else{
                //t is the smallest
                creat(lsearch(ans, t), n, t);
            }
        }
    }
    return;
}

void print(pol *a){
    for(pol *pos = a->next; pos != NULL; pos = pos->next){
        if(pos->n == 0) continue;
        printf("%d %d ",pos->n,pos->t);
    }
    return;
}

int main(){
//    freopen("r.txt","r",stdin);
//    freopen("w.txt","w",stdout);
    zero1.next = NULL;
    zero2.next = NULL;
    ans->next = NULL;
    int n,t;
    pol *input = head1;
    char c;
    while(scanf("%d%d%c",&n,&t,&c)){
        creat(input,n,t);
        if(c == '\n') break;
    }
    input = head2;
    while(scanf("%d%d%c",&n,&t,&c)){
        creat(input,n,t);
        if(c == '\n') break;
    }
    mult(head1,head2);
    print(ans);
    return 0;
}
