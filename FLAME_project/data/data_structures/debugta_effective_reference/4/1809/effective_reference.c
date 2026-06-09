#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct  node {//二叉链表结点
	char data[100];
	int times;
	struct  node   *left,  *right;
};
typedef struct node  BTNode;
typedef struct node  *BTNodeptr;

BTNodeptr insertBST(BTNodeptr p,char *item){
	if(p == NULL) {
		p = (BTNodeptr)malloc(sizeof(BTNode));
		strcpy(p->data,item);
		p->left = p->right = NULL;
		p->times = 1;
	} else if(strcmp(item,p->data)<0){
		p->left = insertBST(p->left,item);
	}else if(strcmp(item,p->data)>0){
		p->right = insertBST(p->right,item);
	}
	else if(strcmp(item,p->data)==0){
		p->times++; //树中存在该元素
	}
	return p;
}
void VISIT(BTNodeptr tword){
	printf("%s %d\n",tword->data,tword->times);
}
void  inorder(BTNodeptr tword)
{
      if(tword!=NULL){
             inorder(tword->left);
             VISIT(tword);       /* 访问T指结点  */
             inorder(tword->right);
       }
}
int main() {
	BTNodeptr root=NULL;
	//BTNodeptr temp=NULL; 
	char flagc;
	int j,tmp,k,flag1=0,flag2=0;
	char a[1000];
	char tword[100];
	FILE *fp1=fopen("article.txt", "r");
	flagc=fgetc(fp1);
	for(j=0; flagc!=EOF; j++) {
		a[j]=flagc;
		flagc=fgetc(fp1);
	}
	for(j=0; j<strlen(a); j++) {
		if(isalpha(a[j])!=0) { //找单词 
			for(tmp=j; tmp<strlen(a); tmp++) {
				if(isalpha(a[tmp])==0) {
					break;
				} 
			}
			memset(tword,'\0',sizeof(tword));
			for(k=0;k<tmp-j;k++){
				tword[k]=tolower(a[k+j]);
			}
			root=insertBST(root,tword);
			j=tmp;
		}
	}
	/*if(root!=NULL){
		printf("%s ",root->data);
	}
	if(root->right!=NULL){
		printf("%s ",root->right->data);
	}
	if(root->right->right!=NULL){
		printf("%s",root->right->right->data);
	}
	printf("\n");
	/*while (temp!=NULL)
    {
        printf("%s ", temp->data);
        temp = temp->data;
    }*/
    
    inorder(root);
	fclose(fp1);
	return 0;
}


