#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int coef;
    int exp;
    struct Node* next;
}Node;
Node* createNode(int coef,int exp) 
{
    Node* node=(Node*)malloc(sizeof(Node));
    node->coef=coef;
    node->exp=exp;
    node->next=NULL;
    return node;
}
void insertNode(Node** poly,int coef,int exp) 
{
    Node* new_node=createNode(coef,exp);
    if(*poly==NULL)
    *poly=new_node;
    else 
    {
        Node* cur=*poly;
        while(cur->next!=NULL)
        cur=cur->next;
        cur->next=new_node;
    }
}
void mergeTerms(Node* poly) 
{
    Node* cur=poly;
    while(cur!=NULL) 
    {
        Node* prev=cur;
        Node* next=cur->next;
        while(next!=NULL) 
        {
            if (cur->exp==next->exp) 
            {
                cur->coef+=next->coef;
                prev->next=next->next;
                free(next);
                next=prev->next;
            } 
            else 
            {
                prev=prev->next;
                next=next->next;
            }
        }
        cur=cur->next;
    }
}
Node* multiplyPoly(Node* poly1,Node* poly2) 
{
    Node* res=NULL;
    Node* cur1=poly1;
    while(cur1!=NULL) 
    {
        Node* cur2=poly2;
        while(cur2!=NULL) 
        {
            int coef=cur1->coef*cur2->coef;
            int exp=cur1->exp+cur2->exp;
            insertNode(&res,coef,exp);
            cur2=cur2->next;
        }
        cur1=cur1->next;
    }
    mergeTerms(res); 
    return res;
}
void swap(Node* a,Node* b) 
{
    int temp_coef=a->coef;
    int temp_exp=a->exp;
    a->coef=b->coef;
    a->exp=b->exp;
    b->coef=temp_coef;
    b->exp=temp_exp;
}
void sortPoly(Node* poly) 
{
    Node* cur=poly;
    while(cur!=NULL) 
    {
        Node* next=cur->next;
        while(next!=NULL) 
        {
            if(cur->exp<next->exp)
            swap(cur,next);
            next=next->next;
        }
        cur=cur->next;
    }
}
void printPoly(Node* poly) 
{
    Node* cur=poly;
    while(cur!=NULL) 
    {
        printf("%d %d ",cur->coef,cur->exp);
        cur=cur->next;
    }
    printf("\n");
}
int main() 
{
    Node* poly1 = NULL;
    Node* poly2 = NULL;
    int coef, exp;
    while (scanf("%d %d", &coef, &exp) != EOF) // @@ Error: This loop reads all input into poly1, leaving nothing for poly2. The input format uses newlines to separate polynomials, but scanf with %d ignores newlines, so both polynomials are read into poly1, and poly2 remains empty.
    insertNode(&poly1, coef, exp);
    while (scanf("%d %d", &coef, &exp) != EOF) // @@ Error: Since the first loop consumed all input, this loop never executes, so poly2 is never populated.
    insertNode(&poly2, coef, exp);
    Node* result = multiplyPoly(poly1, poly2);
    sortPoly(result);
    printPoly(result);
    return 0;
}