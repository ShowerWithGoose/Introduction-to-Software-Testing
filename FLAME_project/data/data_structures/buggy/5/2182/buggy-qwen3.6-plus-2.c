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
            long long xi=(long long)current1->xishu*current2->xishu; // @@ The product of two integers can exceed the range of int, causing overflow. The problem states coefficients are within int range, but their product might not be. However, the output format expects int. Let's look closer. The problem says "coefficients ... will not exceed the range of the int type". It doesn't explicitly say the product fits in int. But usually in these problems, if the result fits in int, it's fine. Wait, the test case is 8 * 15 = 120, which fits in int. The exponents are 10^9 + 10^9 = 2*10^9, which fits in int (max int is ~2.14*10^9). So overflow of int for coefficient isn't the issue here. 
            int zhi=current1->zhishu+current2->zhishu; // @@ The sum of two exponents can exceed the range of int. The problem states exponents are non-negative integers and max degree won't exceed int range. However, when multiplying, exponents are added. If both exponents are close to INT_MAX/2 or larger, their sum can overflow int. In the test case, 1000000000 + 1000000000 = 2000000000, which is less than INT_MAX (2147483647). So this specific case doesn't overflow. But generally, this is a risk. Let's look at the actual error.
            
            // Let's re-read the input parsing logic.
            // while(scanf("%d%d%c",&x,&z,&c)!=EOF)
            // The input format is: a_n n a_{n-1} n-1 ...
            // The scanf reads two integers and then a character.
            // If the input is "8 1000000000\n", scanf reads 8, 1000000000, and '\n'.
            // Then c=='\n', so it breaks. This seems correct for a single term.
            
            // What if there are multiple terms? "1 2 3 0\n"
            // 1st iter: reads 1, 2, ' '. c!='\n', charu(1,2).
            // 2nd iter: reads 3, 0, '\n'. c=='\n', break. charu is NOT called for (3,0).
            // This is the bug! The last term of the polynomial is read into x and z, but if the character following it is '\n', the loop breaks BEFORE calling charu.
            
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
        charu(&para1,x,z); // @@ The original code checked if(c=='\n') break; BEFORE calling charu. This meant the last term of the input line was ignored. We must call charu for every term read. The loop condition should handle the termination correctly or we should process the term before checking for newline. A common pattern is to read until newline. 
        if(c=='\n')
        break;
    }
    while(scanf("%d%d%c",&x,&z,&c)!=EOF)
    {
        charu(&para2,x,z); // @@ Same error as above. The last term was being skipped.
        if(c=='\n')
        break;
    }
    Node *result=chengfa(para1,para2);
    print(result);
    return 0;
}