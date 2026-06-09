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
            long long xi=(long long)current1->xishu*current2->xishu; // @@ The product of two int coefficients can exceed the range of int (e.g., 8 * 15 is fine, but generally coefficients can be large). More importantly, the problem states coefficients and max degree fit in int, but their product might not if we were summing many, but here it's just one pair. However, the main issue in the failed test case is likely related to how the input is parsed or the logic. Let's look closer. The test case is `8 1000000000` and `15 1000000000`. The result exponent is `2000000000`, which fits in `int` (max ~2.147 billion). The coefficient is `120`, which fits in `int`. So overflow of `int` for coefficient isn't the primary issue here unless intermediate steps do. But wait, `scanf("%d%d%c", ...)` reads two ints and a char. 
            int zhi=current1->zhishu+current2->zhishu; // @@ The sum of two exponents can exceed the range of int. In the test case, 1000000000 + 1000000000 = 2000000000, which is within int range (usually up to 2^31-1 = 2147483647). However, if the inputs were slightly larger, it would overflow. But specifically for this test case, 2000000000 is valid. Let's re-read the input parsing.
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
    }
    Node *result=chengfa(para1,para2);
    print(result);
    return 0;
}