#include<stdio.h>
int main(void){
	int i=0,a[110]={0},op;
	while(scanf("%d",&op),op!=-1){
		switch(op){
			case 1:{
				scanf("%d",a+(++i));
				if(i>100)printf("error "),i--;
				break;
			}
			case 0:{
				if(i<1)printf("error ");
				else printf("%d ",a[i--]);
				break;
			}
		}
	}
	return 0;
} 

