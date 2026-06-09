#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
struct node{
	int data;
	struct node *left,*right;
};
typedef struct node BTNode, *BTNodeptr;
BTNodeptr Root=NULL;
int T=1;
void insert(int item);
void sortTree(int k[],int n);
void search(BTNodeptr t);

int main(){
	int n,k[100]={0};
	scanf("%d",&n);
    for(int i=0;i<n;i++){ 
        scanf("%d", &k[i]);
    }
    sortTree(k,n);
    search(Root);
    return 0;
}
	 
void insert(int item){
	BTNodeptr p, q;
	p=(BTNodeptr)malloc(sizeof(BTNode));
	p->data=item;
	p->left=NULL;
	p->right=NULL;
	if(Root==NULL)
	    Root=p;
	else{
        q=Root;
        while(1){
        if(item<q->data){
            if(q->left==NULL){
                q->left=p;
                break;
             }
            else
                q=q->left;
        }
        else if(item>=q->data){
            if(q->right==NULL){
                q->right=p;
                break;     
            }
            else
                q=q->right;
        }
        else{
			/* do-something */
		}
        }
    }	
}
void sortTree(int k[],int n){
	int i;
	for(i=0;i<n;i++){
		insert(k[i]);
	}
}
void search(BTNodeptr t){
	if(t==NULL){
		return ;
	}
	else{
		if(t->left==NULL&&t->right==NULL){
			printf("%d %d\n", t->data,T);
		}
		T++;
		search(t->left);
		search(t->right);
		T--;
	}
}
 

