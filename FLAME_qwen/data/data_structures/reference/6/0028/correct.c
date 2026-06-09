#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#define N 102
struct ost
   {int data[N];
    int top;
   } s;

int a, i;
typedef struct ost st;

void inst(st *s) {s->top=-1;}

int iest(st *s) {return s->top==-1;}

int ifst(st *s) {return s->top==N-1;}

int pst(st *s,int a)
   {if (ifst(s)!=0)
       {printf("error ");
        return 0;
       }
    s->data[++s->top]=a;
    return 1;
   }

int post(st *s,int a)
   {if (s->top==-1)
       {printf("error ");
        return 0;
       }
    a=s->data[s->top--];
    printf("%d ",a);
    return 1;
   }

int main(void)
   {inst(&s);
    int type=-1;
    while (1)
       {scanf("%d",&type);
        if (type==-1)
            break;
        else if (type==0)
            post(&s,a);
        else if (type==1)
           {scanf("%d",&i);
            pst(&s,i);
           }
       }
   }



