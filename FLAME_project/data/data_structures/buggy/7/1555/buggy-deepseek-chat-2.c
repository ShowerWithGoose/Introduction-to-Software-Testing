#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    int N;
    scanf("%d",&N);
    int num[100];
    for(int i=0;i<N;i++){
        scanf("%d",&num[i]);
    } 
    struct tree{
        int high;
        int num;
        struct tree *left;
        struct tree *right;        
    };
    struct tree *root=NULL,*p,*tem,*q;
    struct tree *que[100];
    int top=-1;
    struct tree *frees[100];
    for(int i=0;i<N;i++){
        p=(struct tree*)malloc(sizeof(struct tree));
        p->num=num[i];
        p->left=NULL;
        p->right=NULL;
        frees[i]=p;
        tem=root;
        if(root==NULL){
            root=p;
            root->high = 1; // @@ Missing initialization of root's height. When the root is created, its height should be set to 1, but it is not assigned here, leading to undefined behavior (e.g., 0) when printed.
        }
        else{
            int high=1;
            while(1){
                if(num[i]<tem->num){
                    high++;
                    if(tem->left!=NULL){
                        tem=tem->left;                                                
                    }
                    else{
                        tem->left=p;
                        p->high=high;
                        break;
                    }                    
                }
                else{
                    high++;
                    if(tem->right!=NULL){
                        tem=tem->right;                        
                    }                
                    else{
                        tem->right=p;
                        p->high=high;
                        break;
                    }    
                }
            }
        }
    }
    q=root;
    top++;
    que[top]=root;
    while(top!=-1){
        p=que[top];
        top--;
        if(p->right!=NULL){
            que[++top]=p->right;
        }
        if(p->left!=NULL){
            que[++top]=p->left;
        }
        if(p->right==NULL&&p->left==NULL){
            printf("%d %d\n",p->num,p->high);
        }
    }
    for(int i=0;i<N;i++){
        free(frees[i]);
    }
    return 0;
}