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
            int exp=cur1->exp+cur2->exp; // @@ The sum of two large exponents (e.g., 10^9 + 10^9) exceeds the range of 'int', causing overflow. It should be 'long long'.
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
        printf("%d %d ",cur->coef,cur->exp); // @@ The exponent may exceed the range of 'int' due to overflow in calculation or storage, and should be printed as '%lld' if stored as long long. Also, coefficient multiplication can overflow 'int'.
        cur=cur->next;
    }
    printf("\n");
}
int main() 
{
    Node* poly1 = NULL;
    Node* poly2 = NULL;
    int coef, exp; // @@ 'exp' should be 'long long' to handle large exponents up to 2*10^9 which fits in int but sums might not if intermediate steps or constraints were tighter, though here 2*10^9 fits in signed 32-bit int (max ~2.14*10^9). However, the problem states coefficients and max degree fit in int. Wait, 10^9 + 10^9 = 2*10^9 which is < 2^31-1. So int overflow for exp sum is NOT the issue for 10^9. Let's re-read carefully. "coefficients and the maximum degree ... will not exceed the range of the int type". 10^9 is within int. 2*10^9 is within int. So why wrong answer?
    // Let's look at input reading.
    // The input format says: "First, input ... first polynomial ... Then, input the second polynomial".
    // The buggy code uses:
    // while (scanf("%d %d", &coef, &exp) != EOF) insertNode(&poly1, coef, exp);
    // while (scanf("%d %d", &coef, &exp) != EOF) insertNode(&poly2, coef, exp);
    // This is incorrect because scanf with != EOF will consume ALL input until EOF for the first loop.
    // The first loop will read both polynomials into poly1. The second loop will find EOF immediately and read nothing into poly2.
    // Thus poly2 is NULL. Multiply returns NULL or empty. Output is empty.
    // Expected output is non-empty.
    // So the error is in the input parsing logic in main.
    
    while (scanf("%d %d", &coef, &exp) != EOF) // @@ This loop consumes all input from stdin until EOF, reading both polynomials into poly1. It should stop after reading the first polynomial (usually indicated by a newline or specific count, but here format implies line-based or pair-based separation). Given the reference program uses getchar() to detect newline, this simple EOF loop is fundamentally flawed for two separate inputs on same stream.
    insertNode(&poly1, coef, exp);
    while (scanf("%d %d", &coef, &exp) != EOF)
    insertNode(&poly2, coef, exp);
    Node* result = multiplyPoly(poly1, poly2);
    sortPoly(result);
    printPoly(result);
    return 0;
}