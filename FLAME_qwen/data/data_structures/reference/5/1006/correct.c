#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
    struct link{
        int m,n;
        struct link *next;
    };
    
    struct link *p=(struct link *)malloc(sizeof(struct link));
    struct link *q=(struct link *)malloc(sizeof(struct link));
    struct link *ans=(struct link *)malloc(sizeof(struct link));
    p->next=NULL;
    q->next=NULL;
    ans->next=NULL;
    struct link *head=p;
    struct link *Head=q;
    struct link *head0=ans;

    char s[10000],t[10000];
    gets(s);
    gets(t);
    int i,tem,time=1,flag=0;

    for(i=0;s[i]!='\0';i++){
        tem=atoi(&s[i]);
        p->m=tem;
        while(tem/10!=0){
            tem/=10;
            i++;
        }
        i+=2;//读系数并移过数字位

        tem=atoi(&s[i]);
        p->n=tem;
        while(tem/10!=0){
            tem/=10;
            i++;
        }
        i++;//读指数移过数字位

        struct link *r=(struct link *)malloc(sizeof(struct link));
        p->next=r;
        p=p->next;
        p->next=NULL;//创建链表
    }

    for(i=0;t[i]!='\0';i++){
        tem=atoi(&t[i]);
        q->m=tem;
        while(tem/10!=0){
            tem/=10;
            i++;
        }
        i+=2;//读系数并移过数字位

        tem=atoi(&t[i]);
        q->n=tem;
        while(tem/10!=0){
            tem/=10;
            i++;
        }
        i++;//读指数移过数字位

        struct link *r=(struct link *)malloc(sizeof(struct link));
        q->next=r;
        q=q->next;
        q->next=NULL;//创建链表
    }

    q=Head;
    while(q->next){
        p=head;
        if(time==1){
            while(p->next){
                ans->m=q->m*p->m;
                ans->n=q->n+p->n;

                struct link *r=(struct link *)malloc(sizeof(struct link));
                ans->next=r;
                ans=ans->next;
                ans->next=NULL;//第一圈循环创建链表

                p=p->next;
            }

            ans=head0;
            while(1){
                if(ans->next->next==NULL){
                    ans->next=ans->next->next;
                    break;
                }
                ans=ans->next;
            }//删去缓冲结点
        }else{
            while(p->next){
                flag=0;
                struct link *r=(struct link *)malloc(sizeof(struct link));
                r->next=NULL;
                r->m=q->m*p->m;
                r->n=q->n+p->n;
                ans=head0;//遍历已有阶数

                while(ans->next){
                    if(ans->n==r->n){
                        ans->m+=r->m;
                        flag=1;
                    }else if(ans->n>r->n&&ans->next->n<r->n){
                        r->next=ans->next;
                        ans->next=r;
                        flag=1;
                    }
                    ans=ans->next;
                    if(flag){
                        break;
                    }
                    // ans=ans->next;
                }//后续循环插入结点

                if(ans->n==r->n&&ans->next==NULL){
                    ans->m+=r->m;
                    flag=1;
                }
                
                if(flag==0){
                    ans->next=r;
                    r->next=NULL;
                    ans=ans->next;
                }//不能插入则尾接

                p=p->next;
            }
        }
        time++;
        q=q->next;  
    }

    while(head0){
        if(head0->m){
            printf("%d %d ",head0->m,head0->n);
        }
        head0=head0->next;
    }//判断并输出

    return 0;
}
