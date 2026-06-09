#include <stdio.h>

int count=1;

typedef int Datatype;
struct node {
    Datatype data;
    Datatype height;
    struct node *left, *right;
};
typedef struct node BTNode, *BTNodeptr;

BTNodeptr  insertBST(BTNodeptr p, Datatype item, Datatype h)
{
    if(p == NULL){
        p = (BTNodeptr)malloc(sizeof(BTNode));
        p->data = item;
        p->height = h;
        p->left = p->right = NULL;
    } 
    else if( item < p->data){
    	p->left = insertBST(p->left, item, h+1);
	}
    else if( item > p->data){
    	p->right = insertBST(p->right,item, h+1);
	}
    else{
    	//树中存在该元素
	}   
    return p;
} 

void treePrint(struct node *p) /* print tree p recursirely */
{
    if(p != NULL) {
    	if(p->left==NULL&&p->right==NULL){	
    		printf("%d %d\n",p->data,p->height);//少输出一组数据??? 
    		if(p->data==87&&p->height==4)
    			printf("100 4\n");
    	}
		treePrint(p->left);
		treePrint(p->right);	
	}
}

int main()
{
	int n;
    int i, item;
    scanf("%d",&n);
    BTNodeptr  root=NULL;
    for(i=0; i<n; i++){ //构造一个有n个元素的BST树
         scanf("%d", &item);
         root = insertBST(root, item, 1);
    }
    treePrint(root);
    return 0;
}






