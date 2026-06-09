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
int top=0;
int data[200];
int main()
{
   int op=0,num;
   while(1){
       scanf("%d",&op);
       if(op==-1) break;
       else if(op==1){
           scanf("%d",&num);
           if(top>=100)
           printf("error ");
           else data[top++]=num;
       }
       else if(op==0){
           if(top<1) printf("error ");
           else printf("%d ",data[--top]);
       }
   } 
}
