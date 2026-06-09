#include <stdio.h>
#include <malloc.h>
typedef struct node{
    int coef;
    int exp;
    struct node*next;
} Node;

Node *read();
Node *mult(Node* L1,Node* L2);
void print(Node* res);

int main()
{
    Node *L1 = read();
    Node *L2 = read();
    Node *res = mult(L1,L2);
    print(res);
    return 0;
}

Node *read()
{     Node *head = (struct node*)malloc(sizeof(Node));
      Node *p = (struct node*)malloc(sizeof(Node));
      int coef,exp;
       char c;
       scanf("%d%d%c",&coef,&exp,&c);
       p->next = NULL;
       p->coef = coef;
       p->exp = exp;
      head->next = p;
     while(c!='\n'){
    Node *temp = (struct node*)malloc(sizeof(Node));
    scanf("%d%d%c",&coef,&exp,&c);
    temp->coef = coef;
    temp->exp = exp;
    temp->next = NULL;
    p->next = temp;
    p = temp;
     }
return head;

}


Node *mult(Node *L1,Node *L2)
{    Node *p1 = L1;
     Node *p2 = L2;
     Node *res = (struct node*)malloc(sizeof(Node));
     int coef;
     int exp;
     Node *p = (struct node*)malloc(sizeof(Node));
     //p->next = NULL;
     res->next = NULL;
     for(p1 = L1;p1->next;p1 = p1->next){
         for(p2 = L2;p2->next;p2 = p2->next){
           coef = p1->next->coef*p2->next->coef;
           exp = p1->next->exp+p2->next->exp;
           if(res->next==NULL){
               Node *temp = (struct node*)malloc(sizeof(Node));
               temp->coef = coef;
               temp->exp =exp;
               temp->next = NULL;
               res->next = temp;
               }
            else {
                for(p = res;p->next;p = p->next){
                    if(p->next->exp < exp){
                        Node *temp = (struct node*)malloc(sizeof(Node));
                        temp->coef = coef;
                        temp->exp = exp;
                        temp->next = p->next;
                        p->next = temp;
                        break;
                    }
                else  if(p->next->exp==exp){
                        p->next->coef += coef;
                        break;
                    }
                }
                if(p->next==NULL){
                  Node *temp = (struct node*)malloc(sizeof(Node));
                  temp->exp = exp;
                  temp->coef = coef;
                  temp->next = NULL;
                  p->next = temp;
                }
            }
         }
     }
     return res;
}

void print(Node* res)
{
    Node *p=NULL;
    for(p = res->next;p;p = p->next){
        printf("%d %d ",p->coef,p->exp);
    }
}


