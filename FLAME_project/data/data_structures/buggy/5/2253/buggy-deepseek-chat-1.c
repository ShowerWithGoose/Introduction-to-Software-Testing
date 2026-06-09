#include<stdio.h>
#include<stdlib.h>

struct node{
    int xi;
    int zhi;
    struct node *next;
};
typedef struct node *Nodeptr;
typedef struct node Node;

int cmp(const void *a,const void *b)
{
    Node x=*(Node *)a;
    Node y=*(Node *)b;
    if(x.zhi>y.zhi)
    {
        return -1;
    }
    else if(x.zhi<y.zhi)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

Node h[10001];
Nodeptr list1=NULL,p1=NULL,list2=NULL,p2=NULL,list3=NULL,p3=NULL,q;
int main()
{
    int a,b,m=0,n,i;
    char c;
    FILE *in = fopen("a.in", "r"); // @@ [Error: Opens a file "a.in" for reading but never uses it; the program reads from stdin via scanf, so this line is unnecessary and may cause confusion or resource issues]
    while(scanf("%d%d",&a,&b)!=EOF)//将第一行数据存入list1;
    {
        scanf("%c",&c);

        if(list1==NULL)
        {
            p1=list1=(Nodeptr)malloc(sizeof(Node));
            p1->xi=a;
            p1->zhi=b;
        }
        else
        {
            p1->next=(Nodeptr)malloc(sizeof(Node));
            p1=p1->next;
            p1->xi=a;
            p1->zhi=b;
        }

        if(c=='\n')//判断结束条件
        {
            break;
        }
    }


    while(scanf("%d%d",&a,&b)!=EOF)//将第二行数据存入list2
    {

        scanf("%c",&c);

        if(list2==NULL)
        {
            p2=list2=(Nodeptr)malloc(sizeof(Node));
            p2->xi=a;
            p2->zhi=b;
        }
        else
        {
            p2->next=(Nodeptr)malloc(sizeof(Node));
            p2=p2->next;
            p2->xi=a;
            p2->zhi=b;
        }

        if(c=='\n')//判断结束条件 
        {
            break;
        }

    }

    p1=list1;
    p2=list2;
//从头开始遍历 
    while(p1!=NULL)
    {
        p2=list2;
        while(p2!=NULL)
        {//相乘之后数据存入p3 
            p3 = list3; // @@ [Error: This resets p3 to the head of list3 at the start of each inner loop iteration, causing the subsequent while loop to always start from the beginning, which leads to incorrect merging of terms with the same exponent]
            int now_xi = p1->xi * p2->xi;
            int now_zhi = p1->zhi + p2->zhi;
            if(list3==NULL)
            {
                p3=list3=(Nodeptr)malloc(sizeof(Node));
                p3->xi=now_xi;
                p3->zhi=now_zhi;
                m+=1;
            }
            else
            {
                while(1)
                {
                    if(p3->zhi == now_zhi)
                    {
                        p3->xi += now_xi;
                        break;
                    }
                    if(p3->next == NULL)
                    {
                        p3->next = (Nodeptr) malloc(sizeof(Node));
                        p3 = p3->next;
                        p3->xi = now_xi;
                        p3->zhi = now_zhi;
                        m += 1;
                        break;
                    }
                    p3 = p3->next;
                }

            }
            p2=p2->next;
        }
        p1=p1->next;
    }
    p3=list3;
    for(i=0;i<m;i++)//p3数据存入数组h 
    {
        h[i].xi=p3->xi;
        h[i].zhi=p3->zhi;
        p3=p3->next;
    }
    qsort(h,m,sizeof(Node),cmp);//排序 
//    for(i=0;i<m;i++)
//    {
//        if(h[i].zhi==h[i+1].zhi)
//        {
//            h[i+1].xi=h[i].xi+h[i+1].xi;
//            h[i].xi=0;
//        }
//    }
    for(i=0;i<m;i++)
    {
        printf("%d %d ",h[i].xi,h[i].zhi);//输出
//        if(h[i].xi!=0)
//        {
//
//        }

    }
    return 0;
}