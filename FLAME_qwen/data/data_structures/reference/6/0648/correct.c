#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
    int item;
    struct Node *link;
}list[100];
struct Node* top=NULL;
int main()
{
    int x,i=0,tp;
    while(1){
     scanf("%d",&x);
     if(x==1){
      if(i>=100) 
      printf("error ");
      scanf("%d",&tp);
      if(i<100)
      {list[i].item=tp;
      i++;
   }
  }
  if(x==0){
   if(i==0)
   printf("error ");
   if(i>0){
    printf("%d ",list[i-1].item);
    i--;
    top=&list[i];
   }
  }
  if(x==-1) break;
 }
    
}

