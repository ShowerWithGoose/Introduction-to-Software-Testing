#include<stdio.h>
#include<stdlib.h>
typedef struct linknode
{
      int data;
      struct linknode *next;
      struct linknode *prior;
}linknode,*linklist;
linklist head;
int num_of_node;
void intostack()
{
      int num;
      linklist tmp;
      if(num_of_node==100)
      {
            printf("error ");
            return;
      }
      scanf(" %d ",&num);
      tmp=(linklist)malloc(sizeof(linknode));
      tmp->data=num;
      tmp->next=NULL;
      head->next=tmp;
      tmp->prior=head;
      head=tmp;
      num_of_node++;
}
void outofstack()
{
      linklist tmp;
      if(num_of_node==0)
      {
            printf("error ");
            return;
      }

      printf("%d ",head->data);
      head=head->prior;
      num_of_node--;
}
int main()
{
      int delta,num;

      head=(linklist)malloc(sizeof(linknode));
      while((scanf("%d",&delta))!=-1)
      {
            if(delta==1)
                  intostack();
            else if(delta==0)
                  outofstack();
      }
      return 0;
}

