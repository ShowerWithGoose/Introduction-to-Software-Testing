#include<stdio.h>
#include<stdlib.h>
struct node{
	int coe;//系数 
	int pow;//幂
	struct node *link; 
};
struct node num1[10000],num2[10000],num[1000000];
int main(){
	int a,b,c;
	int i,j,k=0;
	int temp; 
    for(i=0;;i++){//输入 
    	scanf("%d%d",&num1[i].coe,&num1[i].pow);
    	a=i+1;
    	if(getchar()=='\n'){
    		break;
		}
	}
	for(i=0;i!=EOF;i++){
    	scanf("%d%d",&num2[i].coe,&num2[i].pow);
    	b=i+1;
    	if(getchar()=='\n'){
    		break;
		}
	}
	for(i=0,k=0;i<a;i++){//计算 
		for(j=0;j<b;j++,k++){
			num[k].coe=num1[i].coe*num2[j].coe;
			num[k].pow=num1[i].pow+num2[j].pow;
		} 
	}
	c=k;
	for(k=0;k<c;k++){//排序 
		for(j=k+1;j<c;j++){
			if(num[k].pow<num[j].pow){
		    	 temp=num[k].coe;
		    	 num[k].coe=num[j].coe;
	     		 num[j].coe=temp;
	    		 temp=num[k].pow;
	    		 num[k].pow=num[j].pow;
	     		 num[j].pow=temp;
	    	}
	    	else if(num[k].pow==num[j].pow){
	    		num[k].coe+=num[j].coe;
	    		num[j].coe=0;
	    		num[j].pow=0;
			}	
		}
	}
	for(k=0;num[k].coe!=0;k++){
			printf("%d %d ",num[k].coe,num[k].pow);
		}
	return 0;
}

