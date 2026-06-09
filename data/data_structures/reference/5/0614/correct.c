// create node_a, node_b, node_c; save data,head 
// compare head_a,head_b  have 4 case
// case 1: head_a->exp == head_b->exp tmp->data = a+b
// tmp = tmp->next; head_a,head_b = head->next
// case 2: head_a->exp > head_b->exp
//tmp->data = head_a  tmp = tmp->next head_a = head->next
// case 4: one head is null link with tmp->next
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define len 1005
struct node{
    int exp,ratio;
    struct node* next;
};
char arr_a[len],arr_b[len];
struct node *head_a = NULL;
struct node *head_b = NULL;
struct node *mid_c = NULL;
struct node *head_c = NULL;
struct node* getnode(int exp,int ratio)
{
    struct node *tmp;
    tmp = (struct node*)malloc(sizeof(struct node));
    tmp->exp = exp;
    tmp->ratio = ratio;
    tmp->next = NULL;
    return tmp;
}
struct node* insert(int exp, int ratio, struct node* head)
{
    if(head == NULL)
    {
        head = getnode(exp,ratio);
        return head;
    }
    head->next = insert(exp,ratio,head->next);
    return head;
}
// void compare()
// {
//     struct node* tmp = head_c;
//     while(head_a != NULL && head_b != NULL)
//     {
//         int a = head_a->ratio;
//         int b = head_b->ratio;
//         int exp = (head_a->exp > head_b->exp) ? head_a->exp : head_b->exp;
//         if(head_a->exp == head_b->exp)
//         {
//             head_c = insert(exp,a+b,head_c);
//             head_a = head_a->next;
//             head_b = head_b->next;
//         }
//         else if(head_a->exp > head_b->exp)
//         {
//             head_c = insert(exp,a,head_c);
//             head_a = head_a->next;
//         }
//         else if(head_a->exp < head_b->exp)
//         {
//             head_c = insert(exp,b,head_c);
//             head_b = head_b->next;
//         }
//     }
//     while(tmp->next != NULL) tmp = tmp->next;
//     if(head_a == NULL) tmp->next = head_b;
//     if(head_b == NULL) tmp->next = head_a;
// }
void plus()
{
    struct node* tmp = mid_c,*tmp1 = head_c;
    if(head_c == NULL)
    {
        tmp1 = insert(tmp->exp,tmp->ratio,tmp1);
        head_c = tmp1;
        tmp = tmp->next;
    }
    struct node* tmp2 = tmp;
    int flag = 0;
    while(tmp1 != NULL)
    {
        
        tmp = tmp2;
        while(flag>0)
        {
            tmp = tmp->next;
            tmp2 = tmp;
            flag--;
        }
        while(tmp != NULL)
        {
            if(tmp->exp == tmp1->exp)
            {
                tmp1->ratio += tmp->ratio;
                flag++;
            }
            else if(tmp1->next != NULL && tmp->exp < tmp1->exp && tmp->exp > tmp1->next->exp)
            {
                struct node* tmp2 = tmp1->next;
                struct node* node1;
                node1 = (struct node*)malloc(sizeof(struct node));
                node1->exp = tmp->exp;
                node1->ratio = tmp->ratio;
                node1->next = tmp2;
                tmp1->next = node1;
                flag++;
            }
            else if(tmp1->next == NULL && tmp1->exp > tmp->exp)
            {
                struct node *node2;
                node2 = (struct node*)malloc(sizeof(struct node));
                node2->exp =tmp->exp;
                node2->ratio = tmp->ratio;
                tmp1->next = node2;
                node2->next = NULL;
                flag++;
            }
            tmp = tmp->next;
        }
        tmp1 = tmp1->next;
    }     
    return;   
}
void multi()
{
    while(head_b != NULL)
    {
        struct node *tmp1 = head_a;
        while(tmp1 != NULL)
        {
            int exp,ratio;
            exp = head_b->exp + tmp1->exp;
            ratio = head_b->ratio * tmp1->ratio;
            mid_c = insert(exp,ratio,mid_c);
            tmp1 = tmp1->next;
        }
        plus();
        while(mid_c != NULL) 
        {
            struct node* tmp = mid_c->next;
            free(mid_c);
            mid_c = tmp;
        }
        head_b = head_b->next;
    }
    return;
}
void print(struct node* head)
{
    if(head == NULL) return;
    printf("%d %d ",head->ratio,head->exp);
    print(head->next);
    return;
}
int main()
{
    gets(arr_a);
    for(int i = 0; arr_a[i] != '\0'; i++)
    {
        if(arr_a[i] <= '9' && arr_a[i] >= '0')
        {
            int exp = 0,ratio = 0;
            for(int j = i; arr_a[j] <= '9' && arr_a[j] >= '0';j++,i++)
            {
                ratio = ratio*10 + arr_a[j] - '0';
            }
            i++;
            for(int j = i; arr_a[j] <= '9' && arr_a[j] >= '0';j++,i++)
            {
                exp = exp*10 + arr_a[j] - '0';
            }
            head_a = insert(exp,ratio,head_a);
        }
    }
    gets(arr_b);
    for(int i = 0; arr_b[i] != '\0'; i++)
    {
        if(arr_b[i] <= '9' && arr_b[i] >= '0')
        {
            int exp = 0, ratio = 0;
            for(int j = i; arr_b[j] <= '9' && arr_b[j] >= '0'; j++, i++)
            {
                ratio = ratio*10 + arr_b[j] - '0';
            }
            i++;
            for(int j = i; arr_b[j] <= '9' && arr_b[j] >= '0'; j++, i++)
            {
                exp = exp*10 + arr_b[j] - '0';
            }
            head_b = insert(exp,ratio,head_b);
        }
    }
    multi();
    print(head_c);
	return 0;
} 


