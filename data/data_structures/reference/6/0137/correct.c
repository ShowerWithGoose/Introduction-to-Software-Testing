#include<stdio.h>
#include<string.h>
#include<math.h>
    typedef struct  mode{
    	int x;
    	struct mode *link;
	}zha;
	 zha a[105],*p,*top;
int main(){

	 int x,op,sum=0;
	 while(scanf("%d",&op)!=EOF){
	 	if(op==-1){
	 		break;
		 }
		 if(op==0){
		 	if(sum==0){
		 		printf("error ");
			 }
			 else{
			 	printf("%d ",top->x);
				p=top;
				top=top->link; 
			 	free(p);			 
			 	sum--;
			 }
		 }
		 if(op==1){
		 	scanf("%d",&x);
		 	if(sum==100){
		 		printf("error ");
			 }
			 else{
			 	p=(zha*)malloc(sizeof(zha));
			 	p->x=x;
			 	if(sum>0)
			 	p->link=top;
			 	else
			 	p->link=NULL;
				top=p;
				sum++;
			 }
		 }
	 }
	 
	return 0;
} 

