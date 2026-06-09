#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int n;
int t[100];
struct Node{
struct Node *left;
int item;
int floor;
struct Node *right;
};
typedef struct Node tree;
typedef struct Node *treepr;
treepr root=NULL;


void inserttree(int data);
void perorder(treepr t);

int main()
{
scanf("%d",&n);
for(int i=0;i<n;i++)
    scanf("%d",&t[i]);
for(int i=0;i<n;i++)
    inserttree(t[i]);

perorder(root);
return 0;
}

void perorder(treepr t){
if(t!=NULL){
    if(t->left==NULL&&t->right==NULL)
        printf("%d %d\n",t->item,t->floor);
    perorder(t->left);
    perorder(t->right);
}
}
void inserttree(int data){
treepr p,q;
int h=1;
p=(treepr)malloc(sizeof(tree));
p->left=NULL;
p->right=NULL;
p->floor=1;
p->item=data;

if(root==NULL)
    root=p;
else{
    q=root;
    while(1){
        if(data<q->item){
            if(q->left==NULL){
                q->left=p;
                h++;
                p->floor=h;
                break;
            }
        else{
            q=q->left;
            h++;
        }

        }
        else{
            if(q->right==NULL){
                q->right=p;
                h++;
                p->floor=h;
                break;
            }
            else{
                q=q->right;
                h++;
            }


        }





    }
}
}

