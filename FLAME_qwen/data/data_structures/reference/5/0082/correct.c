#pragma GCC optimize(3,"Ofast","inline")
#pragma pack (16)
#include <stdio.h>
#include <stdlib.h>
struct Node{
    int c;
    int e;
    struct Node* next;
};
typedef struct Node LNode;
typedef struct Node * LNptr;
LNptr head1,head2,p1,p2,q1,q2,p0;
void getans(){
    int a,b,a1,b1;
    char tmp;
    head1=p1;//p1是当前的链表尾

    while(scanf("%d%d%c",&a,&b,&tmp)){
        q1=(LNptr) malloc(sizeof(LNode));//创造临时新结点q1
        q1->c=a; q1->e=b; q1->next=NULL;
        if(head1) {       //head1非空，让链表尾p1的next赋值为q1，它就能指向q1指向的结点，并将链表尾指针p1向后移动
            p1->next=q1;
            p1=p1->next;
        }
        else head1=p1=q1;  //head1空，那么链表头，链表尾，都赋值为新的结点指针
        if(tmp=='\n') break;
    }
    while(scanf("%d%d%c",&a,&b,&tmp)){
        for(p1=head1;p1!=NULL;p1=p1->next){
            a1=a*p1->c; b1=b+p1->e;
            q2=(LNptr) malloc(sizeof(LNode));
            q2->c=a1; q2->e=b1; q2->next=NULL;
            if(head2){
                for(p2=head2;p2!=NULL;p0=p2,p2=p2->next){
                    if(p2->e>b1) continue;  //指数小就继续往后走
                    else if(p2->e==b1){
                        p2->c+=a1; break; //指数相等，系数相加
                    }
                    else{         //指数大就插入到当前结点的前面
                        if(p2==head2)  //如果插入到头结点的前面
                        {
                            q2->next=p2; head2=q2; break;
                        }
                        else //如果插入在中间
                        {
                            q2->next=p2; p0->next=q2; break;
                        }
                    }
                }
                if(!p2) p0->next=q2;
            }
            else head2=p2=q2;
        }
        if(tmp=='\n') break;
    }
}
void print(){
    for(p2=head2;p2!=NULL;p2=p2->next) printf("%d %d ",p2->c,p2->e);}
int main(){
    for(int j=0;j<100;++j);
    for(int k=0;k<100;++k);
    for(int l=0;l<100;++l);
    for(int a=0;a<100;++a);
    for(int b=0;b<100;++b);
    for(int c=0;c<100;++c);
    for(int d=0;d<100;++d);
    for(int e=0;e<100;++e);
    for(int f=0;f<100;++f);
    for(int g=0;g<100;++g);
     getans();
     print();
    for(int j=0;j<100;++j);
    for(int k=0;k<100;++k);
    for(int l=0;l<100;++l);
    for(int a=0;a<100;++a);
    for(int b=0;b<100;++b);
    for(int c=0;c<100;++c);
    for(int d=0;d<100;++d);
    for(int e=0;e<100;++e);
    for(int f=0;f<100;++f);
    for(int g=0;g<100;++g);
}





