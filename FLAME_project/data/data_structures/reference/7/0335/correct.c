/*
 * @Author:
 * @Date: 2022-04-28 20:32:25
 * @LastEditors:
 * @LastEditTime: 2022-04-28 21:03:05
 * @Description: 
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef struct treenode{
    int data;
    struct treenode* lkid, *rkid;
    int leaf;       // leaf == 1 是叶子结点
    int high;
} Node;
// int GetHigh(Node* p);
Node* Insert(Node* p, int data, int high);
Node* Create(int data, int high);
void Printleaves(Node* p);
int main()
{
    int n = 0, x = 0;
    scanf("%d",&n);
    scanf("%d",&x);
    n--;
    Node* root = Create(x,1);
    while(n--){
        scanf("%d",&x);
        root = Insert(root, x,1);
    }
    Printleaves(root);
    
    
    return 0;
}
Node* Create(int data, int high)
{
    Node*p = (Node*)malloc(sizeof(Node));
    p->lkid = p->rkid = NULL;
    p->leaf = 1;
    p->data = data;
    p->high = high;
    return p;
}
Node* Insert(Node* p, int data, int high)
{
    if(p == NULL){
        p = Create(data,high);
        return p;
    }
    p->leaf = 0;
    if(data < p->data)      //左边
        p->lkid = Insert(p->lkid, data, high+1);
    else
        p->rkid = Insert(p->rkid, data, high+1);    //右边
    return p;
}
void Printleaves(Node* p)
{
    if(!p) return;
    if(p->leaf == 0)
    {
        Printleaves(p->lkid);
        Printleaves(p->rkid);
    }
    if(p->leaf)
        printf("%d %d\n",p->data, p->high);
}
// int GetHigh(Node* p){
//     int lhigh = GetHigh()   
// }
