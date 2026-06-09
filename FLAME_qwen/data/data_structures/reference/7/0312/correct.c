#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
typedef struct node{
    int data;
    int high; 
    struct node *l,*r;
}BTnode,*BTREE;
BTREE q,t=NULL;
void travel(BTREE t);
BTREE create(BTREE t,int temp,int num);
int main()
{
    int n,i,temp;
    scanf("%d",&n);
    for(i=0;i<n;i++){
    	scanf("%d",&temp);
    	int num=0;
    	t=create(t,temp,num);
	}
    travel(t);
	return 0;
}
void travel(BTREE t){
	if(t!=NULL){
		if(t->l==NULL&&t->r==NULL){
			printf("%d %d\n",t->data,t->high); 
		}
		travel(t->l);
		travel(t->r);
	}
}
BTREE create(BTREE t,int temp,int num){
	num++;
	if(t==NULL){
		t=(BTREE)malloc(sizeof(BTnode));
        t->l=NULL;
        t->r=NULL;
        t->data=temp;
        q=t;
        t->high=num;
	}
	else if(t->data>temp)
		t->l=create(t->l,temp,num);
	else if(t->data<=temp)
	    t->r=create(t->r,temp,num);
	return t;
}


