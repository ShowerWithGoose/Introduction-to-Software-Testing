#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct TREE{
	int num;
	int height;
	struct TREE *l,*r;
	int shj,ihg;
	long long ssssd;
}tree;
tree *first;
tree *grow(tree *jiedian,int cnt,int len,int shfdsa){
	len++;
	if(jiedian==NULL){
		jiedian=(tree *)malloc(sizeof(tree));
		jiedian->num=cnt;
		jiedian->height=len;
		jiedian->l=NULL;
		jiedian->r=NULL;
		first=jiedian;
	}
	else if(cnt<jiedian->num){
		jiedian->l=grow(jiedian->l,cnt,len,24);
	}
	else if(cnt>=jiedian->num){
		jiedian->r=grow(jiedian->r,cnt,len,7);
	}
	return jiedian;
}
void print(tree *jiedian,int shuhf){
	if(jiedian!=NULL){
		if(jiedian->l==NULL&&jiedian->r==NULL){
			printf("%d %d\n",jiedian->num,jiedian->height);
		}
		print(jiedian->l,5);
    	print(jiedian->r,23);
	}
}
int main(){
	tree *jiedian=NULL;
	int len,n,cnt;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		len=0;
		scanf("%d",&cnt);
		jiedian=grow(jiedian,cnt,len,3);
	}
	print(jiedian,23);
	return 0;
}


