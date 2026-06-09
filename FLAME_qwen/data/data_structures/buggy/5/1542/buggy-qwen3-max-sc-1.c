#include<stdio.h>
#include<stdlib.h>

typedef struct xiang{ //多项式的项定义
    int xishu;  //系数
    int zhishu; //指数
    struct xiang *next;
}xiang;    

typedef struct{  //多项式定义
    xiang *first; //首项指针
    xiang *last;  //末项指针
}duoxiangshi;

void printfDXS(duoxiangshi *s) //打印多项式
{
    xiang *cur=s->first;
    while(cur!=NULL)
    {
        printf("%d %d ",cur->xishu,cur->zhishu);
        cur=cur->next;
    }
    printf("\n");
}

void freeDXS(duoxiangshi *s) //释放多项式内存
{
    xiang *cur = s->first;
    while(cur != NULL)
    {
        xiang *temp = cur;
        cur = cur->next;
        free(temp);
    }
}

void mutiDXS(duoxiangshi *s1,duoxiangshi *s2,duoxiangshi *result) //计算s1*s2,输出到result中
{
    xiang *cur1=s1->first;
    xiang *cur2=s2->first;
    xiang *temp;

    while(cur1!=NULL)
    {
        while(cur2!=NULL)
        {
            //计算出一个项
            int muti_xishu=cur1->xishu * cur2->xishu;
            int muti_zhishu=cur1->zhishu + cur2->zhishu;
            temp=(xiang *)malloc(sizeof(xiang));
            temp->xishu=muti_xishu;
            temp->zhishu=muti_zhishu;
            temp->next=NULL;

            if(result->first==NULL) //首项不存在，直接插入temp
            {
                result->first=temp;
                result->last=temp;
            }
            else if( temp->zhishu > result->first->zhishu ) //插入项指数比首项指数大，则添加该项到表头
            {
                temp->next=result->first;
                result->first=temp;
            }
            else if( temp->zhishu < result->last->zhishu ) //插入指数项比末项指数小，则添加到表尾
            {
                result->last->next=temp;
                result->last=temp;
            }
            else //需要插入表中，分类讨论指数的情况
            {
                xiang *cur_result=result->first;
                //遍历result，看看temp应该插在哪
                while(1)
                {
                    if( temp->zhishu < cur_result->zhishu && temp->zhishu > cur_result->next->zhishu) 
                    {   //若temp比 目前项 小，且比 目前项的下一项 大
                        //则插入在目前项后面   
                        temp->next=cur_result->next;
                        cur_result->next=temp;
                        break;
                    }
                    else if( temp->zhishu == cur_result->zhishu)
                    {   //若temp等于目前项
                        //则合并同类项
                        cur_result->xishu += temp->xishu;
                        free(temp);
                        break;
                    }
                    else
                    {
                        cur_result = cur_result->next;
                    }
                }           
            }

            cur2=cur2->next;
        }

        cur1=cur1->next;
    }
}

int main()
{
    duoxiangshi s1,s2;
    s1.first=NULL,s1.last=NULL;
    s2.first=NULL,s2.last=NULL;

    int a,e;
    char ch;
    xiang *x=NULL; 

    //输入第一个多项式，存储到链表s1
    scanf("%d%d%c",&a,&e,&ch);
    while(1)
    {
        x=(xiang *)malloc(sizeof(xiang));
        x->xishu=a;
        x->zhishu=e;
        x->next=NULL;
        if(s1.first==NULL)
        {
            s1.first=x;
            s1.last=x;
        }
        else
        {
            s1.last->next=x;
            s1.last=x;
        }

        if(ch=='\n')
        {
            break;
        }
        scanf("%d%d%c",&a,&e,&ch);
    }

    //输入第二个多项式，存储到链表s2
    scanf("%d%d%c",&a,&e,&ch);    
    while(1)
    {
        x=(xiang *)malloc(sizeof(xiang));
        x->xishu=a;
        x->zhishu=e;
        x->next=NULL;
        if(s2.first==NULL)
        {
            s2.first=x;
            s2.last=x;
        }
        else
        {
            s2.last->next=x;
            s2.last=x;
        }

        if(ch=='\n')
        {
            break;
        }
        scanf("%d%d%c",&a,&e,&ch);
    }

    //进行多项式乘法
    duoxiangshi result;
    result.first=NULL;
    result.last=NULL;
    mutiDXS(&s1,&s2,&result); // @@ [The multiplication function does not handle the case where intermediate terms cancel out (coefficient becomes zero), leading to zero-coefficient terms in the result, which should be removed according to the problem statement that only non-zero terms are included.]

    //输出结果
    printfDXS(&result);
    freeDXS(&s1);
    freeDXS(&s2);
    freeDXS(&result);
    return 0; 
}