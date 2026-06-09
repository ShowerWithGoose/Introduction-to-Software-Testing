#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
struct link{
	int num;
	struct link* left;
	struct link* right;
};
int bianli(struct link*,int);
int main(){
	int n;
	scanf("%d",&n);
	struct link* first=NULL,*p,*q;
	int number;
	for(int i=0;i<n;i++){
		scanf("%d",&number);
		q=(struct link*)malloc(sizeof(struct link));
		q->num=number;
		q->left=NULL;
		q->right=NULL;
		if(first==NULL){
			p=first=q;
		}
		else{
			p=first;
			while(p!=NULL){//
				if(q->num>=p->num){
					if(p->right!=NULL){
						p=p->right;
					}
					else{
						p->right=q;
						break;
					}		
				}
				else{
					if(p->left!=NULL){
						p=p->left;
					}
					else{
						p->left=q;
						break;
					}
				}		
		}
	}		
	}
	bianli(first,1); 
	return 0;
}
void nothing(){
} 
int bianli(struct link* search, int h){
	if(search!=NULL){
		(bianli(search->left, h+1) & bianli(search->right, h+1)) ? printf("%d %d\n", search->num, h): 0 ;
		return 0;
	}else return 1;
}


