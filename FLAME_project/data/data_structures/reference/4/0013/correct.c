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
void VISIT(BTNodeptr t){
	printf("%s %d\n",t->data,t->times);
}
void  inorder(BTNodeptr t)
{
      if(t!=NULL){
             inorder(t->left);
             VISIT(t);       /* 访问T指结点  */
             inorder(t->right);
       }
}
int main() {
	BTNodeptr root=NULL;
	//BTNodeptr temp=NULL; 
	char flagc;
	int i,j,k,flag1=0,flag2=0;
	char c[1000];
	char t[100];
	FILE *fp1=fopen("article.txt", "r");
	flagc=fgetc(fp1);
	for(i=0; flagc!=EOF; i++) {
		c[i]=flagc;
		flagc=fgetc(fp1);
	}
	for(i=0; i<strlen(c); i++) {
		if(isalpha(c[i])!=0) { //找单词 
			for(j=i; j<strlen(c); j++) {
				if(isalpha(c[j])==0) {
					break;
				} 
			}
			memset(t,'\0',sizeof(t));
			for(k=0;k<j-i;k++){
				t[k]=tolower(c[k+i]);
			}
			root=insertBST(root,t);
			i=j;
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


