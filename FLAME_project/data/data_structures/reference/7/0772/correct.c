#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
//qsort顺序为数组名，元素数量，元素大小，cmp
typedef struct leaf{
		int data;//要存的数据 
		struct leaf *left;//链接下一个节点 
		struct leaf *right;
	}LBTNodeptr,*BTNodeptr;
BTNodeptr Root=NULL; //Root是一个全局变量

void insertBST(int item)
{
    BTNodeptr p, q;
    p=(BTNodeptr)malloc(sizeof(LBTNodeptr));
    p->data=item;
    p->left=NULL;
    p->right=NULL;
    if(Root==NULL)
    Root=p;
	else{
		q=Root;
    	while(1) {
        	// 比较值的大小 
        	// 小于向左，大于向右 
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
				printf("error repeat");
				free(p);
			// 出现重复元素  
			}
   	    }    
	}
}//插入到树中 
void sortTree(int k[],int n) 
{
    int i;
    for(i=0;i<n;i++)
    insertBST(k[i]);
    return ;
 }//建立树 

BTNodeptr searchBST(BTNodeptr t,int depth)
{
    if(t->left!=NULL&&t->right!=NULL){
    	searchBST(t->left,depth+1);
    	searchBST(t->right,depth+1);
	}
    else if(t->left!=NULL)
    searchBST(t->left,depth+1);
    else if(t->right!=NULL)
    searchBST(t->right,depth+1);
    else
    printf("%d %d\n",t->data,depth);
    
}


  //二叉查找树 



int main(){
	int n,num,i,k[1000];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&k[i]);
	sortTree(k,n);
	searchBST(Root,1);
    return 0;
} 

