#include<stdio.h>
int main(){
	int stack[100];
	int flag,x,p=-1;
	while(1){
		scanf("%d",&flag);
		if(flag==-1){
			break;
		}else if(flag==1){
			scanf("%d",&x);
			p++;
			if(p>=100){
				printf("error ");
				p--;
			}else{
				stack[p]=x;
			}
		}else if(flag==0){
			if(p<=-1){
				printf("error ");
			}else{
				printf("%d ",stack[p]);
				p--;
			}
		}
	}
}

