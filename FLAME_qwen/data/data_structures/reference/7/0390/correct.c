#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tree{
    int data;
    int layer;
    struct tree* l,*r;
}*stack[100];

void postdel(struct tree* t){
	if(t!=NULL){
		postdel(t->l);
		postdel(t->r);
		free(t);
	}
}

int main(){
    int i,n,num;
    scanf("%d",&num);
    struct tree* root=NULL,*p,*q;
    for(i=0;i<num;i++){
        scanf("%d",&n);
        int d=2;
        if(root==NULL){
            p=(struct tree*)malloc(sizeof(struct tree));
            root=p;
            root->data=n;
            root->l=NULL;
            root->r=NULL;
            root->layer=1;
        } else{
            q=root;
            p=(struct tree*)malloc(sizeof(struct tree));
            p->data=n;
            p->l=NULL;
            p->r=NULL;
            int end=0;
            while (!end)
            {
            	end=0;
                while(n>=q->data){
                    if(q->r==NULL){
                        q->r=p;
                        p->layer=d;
                        end=1;
                        break;
                    }
                    q=q->r;
                    d++;
                } 
				while(n<q->data){
                    if(q->l==NULL){
                        q->l=p;
                        p->layer=d;
                        end=1;
                        break;
                    }
                    q=q->l;
                    d++;
                }
            }
        }
    }
    int top=-1;
    q=root;
    while(!(q==NULL&&top==-1)){
        while(q!=NULL){
            stack[++top]=q;
            q=q->l; 
        }
		q=stack[top--];
		if(q->l==NULL&&q->r==NULL)
        	printf("%d %d\n",q->data,q->layer);
        q=q->r;
    }
    postdel(root);
    return 0;
}

