#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct node{
    int number;
    int zh;
    struct node*link;
};
struct node *list1=NULL,*p=NULL,*q=NULL;
struct node1{
    int number1;
    int zh1;
    struct node*link1;
};
struct node1 *list2=NULL,*t=NULL,*s=NULL;


int main()
{
    int a,b,c,d,e,i,j,flag,total,v,l,k,temp;
    char ca;
    int o[300],u[300];
    int n=0;


   for(i=0;;i++){
      q=(struct node*)malloc(sizeof(struct node));
      scanf("%d%d%c",&q->number,&q->zh,&ca);
      if(i==0){
        list1=q;
        p=q;
      }
      if(i!=0){
        p->link=q;
        p=p->link;

      }
            if(ca=='\n'){
        break;
      }


   }
   for(j=0;;j++){
      s=(struct node1*)malloc(sizeof(struct node1));
      scanf("%d%d%c",&s->number1,&s->zh1,&ca);

      if(j==0){
        list2=s;
        t=s;
      }
      if(j!=0){
        t->link1=s;
        t=t->link1;

      }
            if(ca=='\n'){
        break;
      }
      }
   p->link=list1;
   p=list1;
   s->link1=list2;
   s=list2;
   for(c=0;c<=i;c++){
        for(e=0;e<=j;e++){
        flag=1;
    a=(p->number)*(s->number1);
    b=(p->zh)+(s->zh1);
    for(d=0;d<n;d++){
        if(b==u[d]){
            flag=0;
            o[d]+=a;
        }
    }
   if(flag==1){
    o[n]=a;
    u[n]=b;
    n++;
   }
   s=s->link1;
   }
   p=p->link;
   }
   for(k=0;k<n;k++){
    for(l=k+1;l<n;l++){
        if(u[k]<u[l]){
            temp=u[k];
            u[k]=u[l];
            u[l]=temp;
            temp=o[k];
            o[k]=o[l];
            o[l]=temp;
        }
    }
   }
   for(v=0;v<n;v++){
    printf("%d %d ",o[v],u[v]);
   }






}

