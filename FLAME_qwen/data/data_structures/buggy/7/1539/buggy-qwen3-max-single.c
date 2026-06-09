#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
struct tree{
    int num,high,rea;
    struct tree *dad,*left,*right;
};
void plant(struct tree *wood,int data);
void put(struct tree *wood);

int main()
{   int n,in;
    scanf("%d",&n);
    struct tree *head;
    scanf("%d",&in); 
    head = (struct tree *)malloc(sizeof(struct tree));
      head->high =1,head->num =in,head->dad =NULL,head->left =NULL,head->right =NULL,head->rea =0;
    for(int i=1;i<n;i++)
    { scanf("%d",&in);
      plant(head,in);
    }
    put(head);
    return 0;
    }
    
void plant(struct tree *wood,int data)
{ 
   struct tree *move;
   move = (struct tree *)malloc(sizeof(struct tree));
   move->num =data,move->left = NULL,move->dad =NULL,move->right = NULL,move->rea =0;
   if(data< wood->num  )
   { if(wood->left ==NULL)
     {wood->left = move;
      move->dad  =wood;
      move->high = wood->high +1;
      //printf("%d ",move->num );
     }
     else 
     {free(move);
      plant(wood->left,data);
     }
   }
   else if(data>= wood->num )
   {if(wood->right ==NULL)
     {wood->right = move;
      move->dad  =wood;
      move->high = wood->high +1;
      //printf("%d ",move->num );
     }
     else 
     {free(move);
      plant(wood->right,data);
     }
   }

}

void put(struct tree *wood)
{ wood->rea ++;
  if(wood->left!=NULL)
  { put(wood->left ); 
  }
  else if(wood->left==NULL&&wood->right!=NULL)
  { put(wood->right ); 
  }
  else if(wood->left ==NULL&&wood->right ==NULL)
  {if(wood->rea ==1)
   printf("%d %d\n",wood->num ,wood->high );
   struct tree *up;
   up=wood->dad;
   if(up->left !=NULL)
   {up->left =NULL; 
   }
   else
   {up->right =NULL; 
   }
   if(up !=NULL)
   put(up);
  }
} // @@ [The logic in the `put` function incorrectly modifies the tree structure while traversing it, leading to undefined behavior and incorrect traversal order. Specifically, it sets parent's left/right pointers to NULL during traversal, which destroys the tree before all leaves are visited. Additionally, the traversal is not a proper in-order traversal: it only recurses into one child due to use of `else if`, so some leaf nodes may be missed. Also, when `up` is NULL (i.e., at root), accessing `up->left` causes a segmentation fault.]