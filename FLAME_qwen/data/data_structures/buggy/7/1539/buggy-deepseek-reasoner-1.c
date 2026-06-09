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
{ wood->rea ++; // @@ [The 'rea' field is used incorrectly; it introduces a flawed visited mechanism and is not needed for correct traversal.]
  if(wood->left!=NULL)
  { put(wood->left ); 
  }
  else if(wood->left==NULL&&wood->right!=NULL) // @@ [This condition only visits the right subtree when the left is NULL. For nodes with both children, the right subtree is never traversed, causing missing leaves.]
  { put(wood->right ); 
  }
  else if(wood->left ==NULL&&wood->right ==NULL)
  {if(wood->rea ==1) // @@ [This condition incorrectly restricts printing to only the first visit; due to the destructive algorithm, a leaf may be printed only once, but overall logic is broken.]
   printf("%d %d\n",wood->num ,wood->high );
   struct tree *up;
   up=wood->dad;
   if(up->left !=NULL) // @@ [Dereferencing up without checking for NULL; if wood is the root (up==NULL), this causes a segmentation fault. Also, the logic incorrectly assumes the leaf is always the left child.]
   {up->left =NULL; 
   }
   else // @@ [This else branch is reached when up->left is NULL, but the leaf could be the right child; setting up->right to NULL is wrong if the leaf was actually the left child.]
   {up->right =NULL; 
   }
   if(up !=NULL) // @@ [This check for NULL should occur before accessing up->left/up->right to avoid segmentation fault. Moreover, recursively calling put(up) after destroying child pointers leads to an unpredictable traversal and destroys the tree structure.
   put(up);
  }
}