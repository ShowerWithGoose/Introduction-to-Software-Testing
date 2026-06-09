#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int xishu;//系数
    int zhishu;//指数
    struct Node *next;     
}Node;
Node *create(int xi,int zhi)
{
    Node *newnode=(Node *)malloc(sizeof(Node));//申请空间
    newnode->xishu=xi;
    newnode->zhishu=zhi;
    newnode->next=NULL;
    return newnode;
}//创建新的节点
void charu(Node **para,int xi,int zhi)
{
    Node *current=*para;
    if(current==NULL)
    *para=create(xi,zhi);//如果结构体为空，将节点插入到首位
    else
    {
        while(current->next!=NULL)
        current=current->next;
        current->next=create(xi,zhi);//将节点插入到结构体末尾
    }
}//将项节点插入结构体中
Node *chengfa(Node *para1,Node *para2)
{
    Node *result=NULL;//将结果赋为NULL
    Node *current1=para1;//遍历第一个多项式
    while(current1!=NULL)
    {
        Node *current2=para2;//遍历第二个多项式
        while(current2!=NULL)
        {
            int xi=current1->xishu*current2->xishu;
            int zhi=current1->zhishu+current2->zhishu;
            Node *pre=NULL;
            Node *ptr=result;
            while(ptr!=NULL&&zhi<ptr->zhishu)
            {
                pre=ptr;
                ptr=ptr->next;
            }//找到结果的正确位置
            if(ptr!=NULL&&zhi==ptr->zhishu)
            ptr->xishu+=xi;//如果指数相等则系数相加
            else
            {
                Node *newNode=create(xi,zhi);//建立新节点
                newNode->next=ptr;
                if(pre!=NULL)
                pre->next=newNode;//结构体不为空    
                else
                result=newNode;    //结构体为空
            }//将结果存放到新建立的节点
            current2=current2->next;
        }
        current1=current1->next;
    }
    return result;
}//多项式相乘函数
void print(Node *result)
{
    Node *current=result;
    while(current!=NULL)
    {
        printf("%d %d ",current->xishu,current->zhishu);
        current=current->next;
    }
}//打印结果
int main()
{
    Node *para1=NULL;
    Node *para2=NULL;
    int x,z;
    char c;
    while(scanf("%d%d%c",&x,&z,&c)!=EOF)
    {
        if(c=='\n')
        break;
        charu(&para1,x,z);    
    }
    while(scanf("%d%d%c",&x,&z,&c)!=EOF)
    {
        if(c=='\n')
        break;
        charu(&para2,x,z);    
    } @@ [The input reading logic fails when the input has only one term per polynomial because `scanf` with `%c` consumes the newline, but the loop breaks before inserting the last term. Thus, both polynomials remain empty (NULL), leading to no multiplication and empty output.]
    Node *result=chengfa(para1,para2);
    print(result);
    return 0;
}