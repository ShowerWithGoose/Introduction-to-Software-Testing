#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<ctype.h>
#define ll long long
#define For(a, b, c) for (int a = b; a < c;a++)
#define FOR(a, b, c) for (int a = c - 1; a >= b;a--)
#define ull unsigned long long
#define MAXN 1000000
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define swap(a,b)   do{a^=b;b^=a;a^=b;}while(0)
struct node
{
    int factor;
    int index;
    struct node *link;
};
typedef struct node *Nodeptr;
typedef struct node Node;
Nodeptr p,q,r;
/*Nodeptr createList(int n){
    Nodeptr list=NULL;
    for(int i=1;i<=n;i++){
        q=(Nodeptr)malloc(sizeof(Node));
        q->data=i;
        q->link=NULL;
        if(list==NULL)
            list=p=q;
        else p->link=q;
        p=q;132 744 132 731 165 711 506 710 744 47 120 36 744 34 150 16 460 15 2852 13 110 5
    }
    p->link=list;
    return list;
}*/
int main()
{
    char str1[500],str2[500];
    int Factor,Index=1;
    Nodeptr lista=NULL,listb=NULL,listc=NULL,ptr;
    while(1){
        scanf("%s",str1);
        scanf("%s",str2);
        Factor=atoi(str1),Index=atoi(str2);
        q=(Nodeptr)malloc(sizeof(Node));
        q->factor=Factor;
        q->index=Index;
        q->link=NULL;
        if(lista==NULL)
            lista=p=q;
        else p->link=q;
        p=q;       
         char ch=getchar();
        if(ch=='\n') break;
    }
    while(1){
        scanf("%s",str1);
        scanf("%s",str2);
        Factor=atoi(str1),Index=atoi(str2);
        q=(Nodeptr)malloc(sizeof(Node));
        q->factor=Factor;
        q->index=Index;
        q->link=NULL;
        if(listb==NULL)
            listb=p=q;
        else p->link=q;
        p=q;
        char ch=getchar();
        if(ch=='\n') break;
    }
    p=lista;
    /*while(q!=NULL) {
        printf("%d %d ",q->factor,q->index);
        q=q->link;
    }*/
    while (p!=NULL)
    {
        q=listb;
        while(q!=NULL){
            int indexs,factors;
            indexs=(p->index)+(q->index);
            factors=(p->factor)*(q->factor);
            r=(Nodeptr)malloc(sizeof(Node));
            r->link=NULL;
            if(listc==NULL){
                listc=r;
                listc->factor=factors;
                listc->index=indexs;
            }
            else{
                Nodeptr ptr1;
                ptr=listc;
                if(indexs==ptr->index){
                    ptr->factor+=factors;
                }
                else if(indexs>ptr->index){
                    ptr1=(Nodeptr)malloc(sizeof(Node));
                    ptr1->index=indexs;
                    ptr1->factor=factors;
                    ptr1->link=listc;
                    listc=ptr1;
                }/*能否插在首项前*/
                else {
                    while(1){
                        ptr1=ptr->link;
                        if(ptr1==NULL){//末尾项直接插入
                            ptr1=(Nodeptr)malloc(sizeof(Node));
                            ptr1->index=indexs;
                            ptr1->factor=factors;
                            ptr1->link=NULL;
                            ptr->link=ptr1;
                            break;
                        }
                        else {
                            if(indexs>ptr1->index){//大于下一项直接插入
                            ptr1=(Nodeptr)malloc(sizeof(Node));
                            ptr1->index=indexs;
                            ptr1->factor=factors;
                            ptr1->link=ptr->link;
                            ptr->link=ptr1;
                            break;
                        }
                        else if(ptr1->index==indexs){//等于下一项直接做加法
                            ptr1->factor+=factors;
                            break;
                        }
                        else {//进位
                            ptr=ptr->link;
                        }
                        }
                    }
                }
            }
            q=q->link;
        }
        p=p->link;
    }
    p=listc;
    while(p!=NULL)
    {
        printf("%d %d ",p->factor,p->index);
        p=p->link;
    }
}
