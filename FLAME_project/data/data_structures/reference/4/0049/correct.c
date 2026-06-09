#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct tree{
	int n;
	char word[101];
	struct tree *left,*right;
};

void travel(struct tree *root){
	if(root->left!=NULL){
		travel(root->left);
	}
	printf("%s %d\n",root->word,root->n);
	if(root->right!=NULL){
		travel(root->right);
	}
	return;
}

int main(){
	struct tree*root=NULL,*p;
	
	freopen("article.txt","r",stdin);
	char a,word[101];
	int i=0;
	while((a=getchar())!=EOF){
		if(a>='A'&&a<='Z'){
			word[i]=a+' ';
			i++;
		}
		else if(a>='a'&&a<='z'){
			word[i]=a;
			i++;
		}
		else if(i!=0){
			word[i]='\0';
			i=0;
			if(root==NULL){
				root=(struct tree*)malloc(sizeof(struct tree));
				strcpy(root->word,word);
				root->n=1;
				root->left=NULL;
				root->right=NULL;
			}
			else {
				p=root;
				while(1){
					if(strcmp(p->word,word)==0){
						p->n++;
						break;
					}
					else{
						if(strcmp(p->word,word)<0){
							if(p->right==NULL){
								p->right=(struct tree*)malloc(sizeof(struct tree));
								p=p->right;
								strcpy(p->word,word);
								p->n=1;
								p->left=NULL;
								p->right=NULL;
								break;
							}
							else{
								p=p->right;
							}
						}
						else{
							if(p->left==NULL){
								p->left=(struct tree*)malloc(sizeof(struct tree));
								p=p->left;
								strcpy(p->word,word);
								p->n=1;
								p->left=NULL;
								p->right=NULL;
								break;
							}
							else{
								p=p->left;
							}
						}						
					}
				}
			}
		}
	}
	

	travel(root);
	return 0;
}



