#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
struct node 
{
    int data[MAX];
    int top;
    struct node *link;
} s;
typedef struct node *Nodeptr;
typedef struct node Node;
Nodeptr Top;
int isfullstack(Node *s){return s->top==MAX-1;}
int mx=100;
int a[MAX];
int main (){
    int op=-100,top=-1,n=0;
    while(1){
        scanf("%d",&op);
        if(op==-1){break;}
        if(op==1){
            if(n>100){printf("error ");}
          else{n++;
                scanf("%d",&a[n]);
                
            }
        }
        if(op==0){
            if(n<=0){printf("error ");}
           else{ printf("%d ",a[n]);
           n--;
           }
        }
    }
    system("pause");
}
