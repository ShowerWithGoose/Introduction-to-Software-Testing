#include <stdio.h>
#include <stdlib.h>
typedef struct T{
	int value;
	int lc,rc;//初始值-1，标记叶子结点	
}DTNode;
DTNode t[60];//构建树的数组 
int rn=0;//根结点标记，0位空树，否则为1，用数组【1】作为根结点 //填加结点函数，重根结点开始查找lc和rc的value，输入值val小于结点值value，左树查找，否则右树查找，直到结点标记位-1，添加 
int main(){
	int n,val;
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++){
		scanf("%d",&val);
		add_node_f(val,i);			   
	}
	print_node_f(rn,1);	
	return 0;
}
add_node_f(int val,int i){
	int r=rn,flag=1;//flag循环标记，添加结点后退出循环 //初始化结点 
	t[i].value=val;//给结点赋值 
	t[i].lc=t[i].rc=-1;
	if(rn==0){//如果空树，标记根结点 
		rn=i;
	}
	else while(flag){
		if(val<t[r].value){  
		    if(t[r].lc==-1){
				t[r].lc=i;			
				flag=0;			
			}
			else
			r=t[r].lc;		
		}
		else{
			if(t[r].rc==-1){
				t[r].rc=i;		
				flag=0;	
			}
			else
			r=t[r].rc;			
		}			
	}	
}//打印叶子结点函数 
print_node_f(int r,int d){
	if (r==-1){//结点空 
		return;
	} //如果是叶子结点打印 
	if (t[r].lc==-1 && t[r].rc==-1){ 
		printf("%d %d\n", t[r].value, d);
	}// 递归调用遍历子树，高度加1 
	print_node_f(t[r].lc, d + 1);  
	print_node_f(t[r].rc, d + 1);
}
 

