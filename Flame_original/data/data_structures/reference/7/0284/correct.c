#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	int height;
	struct node *left;
	struct node *right;
}NODE;
NODE *find(int num,NODE *shou){
	while(1){
		if(num<shou->data){
			if(shou->left==NULL)return shou;
			shou=shou->left;
		}else{
			if(shou->right==NULL)return shou;
			shou=shou->right;
		}
	}
}
NODE *stack[1000];
int istack=-1;
int main(){
	int input[1000],iinput=-1;
	int tempint,num;
	char tempc;
	NODE *shou=NULL,*temppNODE,*temppNODE_find=NULL;
	scanf("%d",&num);
	while(num--){
		if(shou==NULL){
			shou=(NODE*)malloc(sizeof(NODE));
			shou->height=1;
			shou->left=shou->right=NULL;
			scanf("%d%c",&(shou->data),&tempc);
			//if(tempc=='\n')break;
		}else{
			scanf("%d%c",&tempint,&tempc);
			temppNODE=(NODE*)malloc(sizeof(NODE));
			temppNODE->left=temppNODE->right=NULL;
			temppNODE->data=tempint;
			temppNODE_find=find(tempint,shou);
			if(tempint<temppNODE_find->data){
				temppNODE_find->left=temppNODE;
			}else{
				temppNODE_find->right=temppNODE;
			}
			temppNODE->height=(temppNODE_find->height)+1;
		}
	}
	temppNODE=shou;
	while(temppNODE||istack>-1){
		while(temppNODE){
			stack[++istack]=temppNODE;
			temppNODE=temppNODE->left;
		}
		//æ ˆ--
		temppNODE=stack[istack];
		istack--;
		if(temppNODE->left==NULL&&temppNODE->right==NULL){
			printf("%d %d\n",temppNODE->data,temppNODE->height);
		}
		temppNODE=temppNODE->right;
	}
}
