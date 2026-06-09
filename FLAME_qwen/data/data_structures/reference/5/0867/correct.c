//
// Created by on 2022-03-24.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lnode {
	long long n;
	long long e;
	struct lnode *next;
} *listptr;

int main() {
	listptr anshead = NULL, ahead = NULL, bhead = NULL;
	listptr atail, btail,anstail;
	char c;
	long long ni, ei;
	do {
		fscanf(stdin, "%lld%lld%c", &ni, &ei, &c);
		if (ahead) {
            atail->next = malloc(sizeof(struct lnode));
			atail = atail->next;
		} else {
			ahead = malloc(sizeof(struct lnode));
			atail = ahead;
		}
		atail->e = ei;
		atail->n = ni;
		atail->next = NULL;
	} while (c != '\n');
	do {
		fscanf(stdin, "%d%d%c", &ni, &ei, &c);
		if (!bhead) {
			bhead = malloc(sizeof(struct lnode));
			btail = bhead;
		} else {
            btail->next = malloc(sizeof(struct lnode));
			btail = btail->next;
		}
		btail->next = NULL;
		btail->e = ei;
		btail->n = ni;
	} while (c != '\n');
	listptr aread,bread,ansread = NULL,prev;
    for(aread = ahead;aread;aread = aread->next){
        for(bread = bhead;bread;bread = bread->next){
            long long nn,ne;
            nn = aread->n * bread->n;
            ne = aread->e + bread->e;
            //write into ans
            if(!anshead){
                anshead = malloc(sizeof(struct lnode));
                anshead->n = nn;
                anshead->e = ne;
                anshead->next = NULL;
                ansread = anshead;
            }else{
                ansread = anshead;
                int flagend = 0;
                while(ne<ansread->e){
                    if(ansread->next){
                        prev = ansread;
                        ansread = ansread->next;
                    }else{
                        flagend = 1;
                        break;
                    }
                }
                if(!(anshead->next))//!ansread->next
                    flagend = 1;
                //end
                if(flagend&&ne!=ansread->e){
                    ansread->next = malloc(sizeof(struct lnode));
                    (ansread->next)->next = NULL;
                    (ansread->next)->n = nn;
                    (ansread->next)->e = ne;
                }else{
                    if(ne==ansread->e){
                        ansread->n += nn;
                    }else{
                        listptr tmp = malloc(sizeof(struct lnode));
                        tmp->next = prev->next;
                        tmp->n = nn;
                        tmp->e = ne;
                        prev->next = tmp;
                    }
                }
            }
        }
    }
    for(;anshead;anshead = anshead->next){
        if(anshead->n!=0)
            printf("%lld %lld ",anshead->n,anshead->e);
    }
}
