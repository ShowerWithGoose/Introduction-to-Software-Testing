#include <stdio.h>  
#include <stdlib.h>  
typedef struct asketla {  
    int num;  
    struct asketla *left;  
    struct asketla *right;  
} asketla;  
asketla *root = NULL;  
   
asketla* insert(asketla*node, int num) {  
	if (node==NULL) {  
        asketla* p = (asketla*)malloc(sizeof(asketla));  
        p->num = num;  
        p->left=NULL;  
        p->right=NULL;
        return p;  
    }    
    else if (num<node->num) {  
        node->left=insert(node->left,num);  
    } else if(num>=node->num){  
        node->right=insert(node->right,num);  
    }   
    return node;  
}  
  
void output(asketla* node,int height) {  
    if (node == NULL) return;  
    if (node->left == NULL && node->right == NULL) {  
        printf("%d %d\n", node->num,height);  
        return; 
    }
    output(node->left,height+1);  
    output(node->right,height+1);  
}  
int main(){  
    int n,m; 
	scanf("%d",&n); 
    while (n--){
    scanf("%d",&m);
	root=insert(root,m);}   
    output(root,1);  
    return 0;  
}

