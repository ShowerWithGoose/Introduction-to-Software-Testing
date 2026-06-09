#include<stdio.h>
#include<stdlib.h>
struct tree{
	int num;
	struct tree* left;
	struct tree* right;
};
void output(struct tree* p,int num){
	num++;
	if(p->left==NULL){
		if(p->right==NULL){
			printf("%d %d\n",p->num,num);
		}
		else{
			output(p->right,num);
		}
	}
	else{
		output(p->left,num);
		if(p->right!=NULL){
			output(p->right,num);
		}
	}
}
int main(){
  int cnt,num,i;
  scanf("%d",&cnt);
  struct tree  root;
  root.left=NULL;
  root.right=NULL;
  struct tree* ptr;
  scanf("%d",&num);
  root.num=num;
  for(i=2;i<=cnt;i++){
  	scanf("%d",&num);
  	ptr=&root;
  	while(1){
  		if(num<ptr->num){
  			if(ptr->left==NULL){
  				ptr->left=(struct tree*)malloc(sizeof(root));
  				ptr=ptr->left;
  				ptr->num=num;
  				ptr->left=NULL;
  				ptr->right=NULL;
  				break;
			  }
			  else{
			  	ptr=ptr->left;
			  }
		  }
		  else {
		  	if(ptr->right==NULL){
  				ptr->right=(struct tree*)malloc(sizeof(root));
  				ptr=ptr->right;
  				ptr->num=num;
  				ptr->left=NULL;
  				ptr->right=NULL;
  				break;
			  }
			  else{
			  	ptr=ptr->right;
			  }
		  }
	  }
  }
  ptr=&root;
  output(ptr,0);

;} 

