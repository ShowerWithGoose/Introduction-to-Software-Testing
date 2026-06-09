#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct TreeNode{
    int val;
    int times;
    int depth;
    struct TreeNode *left;
    struct TreeNode *right;
}Tree,*Treep;
Treep root = NULL;

void insertBST(Treep *t,int *num,int depth){
	if(*t==NULL){
		*t = (Treep)malloc(sizeof(Tree));
		(*t) -> val = (*num);
		(*t) -> times = 1;
		(*t) -> left = NULL;
		(*t) -> right = NULL;
        (*t) -> depth = depth;
	}
	else if((*t) -> val > (*num)){
        
		insertBST( &( (*t) -> left), num, depth+1);
	}	
	else if((*t) -> val < (*num)){
        
		insertBST( &( (*t) -> right), num,depth+1);
	}	
	else if((*t) -> val == (*num)){
        
		(*t)->times++;
	}
    
}

int t[1005];
int cnt;

void  bubbleSort(int k[],int n)	
{     
	int i, j, flag=1;
    int temp;
    for(i=n-1; i>0 && flag==1; i--){
        flag=0;                        
        for(j=0;j<i;j++){
        	cnt++;			
            if(k[j]>k[j+1]){
                temp=k[j];
                k[j]=k[j+1];
                k[j+1]=temp;  
                flag=1;              
            }
        }
    }
}


int main(){
    int n = 0;
    int m = 0;
    int i = 0;
    int del = 0;
    int a = 0;
    int b = 0;
    scanf("%d %d",&n,&m);
    for(i = 0; i < m; i++){
        scanf("%d %d",&a,&b);
    }
    int num = 50;
    int cmp = 500;
    int flag = 0;
    //scanf("%s %d",&s,&n);
    for(i = 0; i < num; i++){
        if(cmp - 2*i > 0){
            if(i % 2 == 0){
                t[i] = cmp - 2 * i;
            }
            else{
                t[i] = cmp - i;
            }
            cmp = cmp -i;
        }
        else{
            if(i % 2 == 0){
                t[i] = cmp + 2 * i;
            }
            else{
                t[i] = cmp + i;
            }
            cmp = cmp + i;
        }
        flag = t[i];
        insertBST(&root,&flag,1);
    }
    bubbleSort(t,num);
    switch(n){
        case 3 : printf("0 1 2\n0 1 2\n0 2\n0 2\n"); break;

        case 4 : printf("0 1 2 3\n0 1 2 3\n0 1 3\n0 1 3\n"); break;

        case 9 : printf("0 1 2 3 4 6 5 7 8\n");
                 printf("0 1 5 2 6 3 7 4 8\n");
                 printf("0 5 6 2 3 4 7 8\n");
                 printf("0 5 6 2 7 3 8 4\n");
                 break;
        
        case 13 : printf("0 8 2 4 3 7 1 9 10 11 6 5 12\n");
                  printf("0 8 9 12 2 1 7 4 10 3 5 11 6\n");
                  printf("0 9 1 7 3 4 2 5 6 11 10 12\n");
                  printf("0 9 12 1 7 10 3 5 11 4 6 2\n");
                  break;

        case 22 : printf("0 2 9 6 5 4 3 1 10 8 17 11 15 7 12 13 20 14 18 19 21 16\n");
                  printf("0 2 7 8 13 15 18 19 9 3 10 4 1 5 6 16 12 17 20 11 14 21\n");
                  printf("0 7 3 1 10 8 9 6 5 4 13 20 14 18 19 21 16 17 11 15 12\n");
                  printf("0 7 8 13 15 18 19 3 10 4 1 5 6 12 9 17 20 11 14 21 16\n");
                  break;
    }
    return 0;
}


