#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

typedef struct _node{
    int data;
    struct _node *left,*right,*next;
}Node;

int main()
{
    Node* holder,*root=NULL,*compareP,*comparePParent;
    int dataTemp,LRindicator,nodeNum;
    scanf("%d",&nodeNum);
    while(nodeNum>0)
    {
        scanf("%d",&dataTemp);
        holder=(Node*)malloc(sizeof(Node));
        holder->data=dataTemp;
        holder->left=NULL;
        holder->right=NULL;
        if(root==NULL)
        {
            root=holder;
        }
        else
        {
            compareP=root;
            comparePParent=compareP;
            while(compareP!=NULL)
            {
                if(holder->data>=compareP->data)
                {
                    comparePParent=compareP;
                    compareP=compareP->right;
                    LRindicator=1;
                }
                else
                {
                    comparePParent=compareP;
                    compareP=compareP->left;
                    LRindicator=0;
                }
            }
            if(LRindicator)
                comparePParent->right=holder;
            else
                comparePParent->left=holder;
        }
        nodeNum--;
    }

    Node *scan;
    scan=root;
    int depth=1,isReachedLeaf=0;
    while(root->data!=114514)
    {
        depth=1;
        scan=root;
        while(1)
        {
            if(scan->left==NULL&&scan->right==NULL)
            {
                isReachedLeaf=1;
                break;
            }
            
            if(scan->left!=NULL&&scan->left->data!=114514)
            {
                scan=scan->left;
                depth++;
            }
            else if(scan->right!=NULL&&scan->right->data!=114514)
            {
                scan=scan->right;
                depth++;
            }
            else
            {
                scan->data=114514;
                isReachedLeaf=0;
                break;
            }
        }
        if(isReachedLeaf)
        {
            printf("%d %d\n",scan->data,depth);
            scan->data=114514;
        }
    }
    return 0;
}
