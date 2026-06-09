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
            int exp=cur1->exp+cur2->exp; // @@ The sum of exponents can exceed the range of 'int' (e.g., 10^9 + 10^9 = 2*10^9), causing integer overflow. It should be 'long long'.
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
        printf("%d %d ",cur->coef,cur->exp); // @@ The exponent may exceed the range of 'int' due to overflow in multiplication or if stored as long long, requiring '%lld' format specifier. Also, coefficients should be checked for zero before printing if mergeTerms doesn't remove them (though it does here, the format specifier is the primary issue for large numbers).
        cur=cur->next;
    }
    printf("\n");
}
int main() 
{
    Node* poly1 = NULL;
    Node* poly2 = NULL;
    int coef, exp;
    while (scanf("%d %d", &coef, &exp) != EOF) // @@ This loop reads all input into poly1 because scanf doesn't distinguish between the two polynomials. It needs to read the first line for poly1 and the second for poly2, typically by checking for newline or using a different delimiter strategy.
    insertNode(&poly1, coef, exp);
    while (scanf("%d %d", &coef, &exp) != EOF) // @@ This loop will never execute because the previous loop consumed all stdin until EOF.
    insertNode(&poly2, coef, exp);
    Node* result = multiplyPoly(poly1, poly2);
    sortPoly(result);
    printPoly(result);
    return 0;
}