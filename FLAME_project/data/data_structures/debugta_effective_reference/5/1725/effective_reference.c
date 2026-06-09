#include <stdio.h>
#include <malloc.h>
typedef struct node{
    int coef;
    int exp;
    struct node*next;
} Node;

Node *read();
Node *mult(Node* poly1,Node* poly2);
void print(Node* result);

int main()
{
    Node *poly1 = read();
    Node *poly2 = read();
    Node *result = mult(poly1,poly2);
    print(result);
    return 0;
}

Node *read()
{     Node *head = (struct node*)malloc(sizeof(Node));
      Node *p = (struct node*)malloc(sizeof(Node));
      int coef,exp;
       char ch;
       scanf("%d%d%c",&coef,&exp,&ch);
       p->next = NULL;
       p->coef = coef;
       p->exp = exp;
      head->next = p;
     while(ch!='\n'){
    Node *temp = (struct node*)malloc(sizeof(Node));
    scanf("%d%d%c",&coef,&exp,&ch);
    temp->coef = coef;
    temp->exp = exp;
    temp->next = NULL;
    p->next = temp;
    p = temp;
     }
return head;

}


Node *mult(Node *poly1,Node *poly2)
{    Node *p1 = poly1;
     Node *p2 = poly2;
     Node *result = (struct node*)malloc(sizeof(Node));
     int coef;
     int exp;
     Node *p = (struct node*)malloc(sizeof(Node));
     //p->next = NULL;
     result->next = NULL;
     for(p1 = poly1;p1->next;p1 = p1->next){
         for(p2 = poly2;p2->next;p2 = p2->next){
           coef = p1->next->coef*p2->next->coef;
           exp = p1->next->exp+p2->next->exp;
           if(result->next==NULL){
               Node *temp = (struct node*)malloc(sizeof(Node));
               temp->coef = coef;
               temp->exp =exp;
               temp->next = NULL;
               result->next = temp;
               }
            else {
                for(p = result;p->next;p = p->next){
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
     return result;
}

void print(Node* result)
{
    Node *p=NULL;
    for(p = result->next;p;p = p->next){
        printf("%d %d ",p->coef,p->exp);
    }
}


