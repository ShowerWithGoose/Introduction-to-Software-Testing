#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main(){
	int x,i=0,t=0,cnt=0;
	int line[100];
	while(~scanf("%d",&x)){
		if(x==1){
			scanf("%d",&x);
			line[i]=x;
			i++;
			if(i>100) printf("error ");
		}
		else if(x==0){
			if(i==0) printf("error ");
			
			else{
			    i--;
				printf("%d ",line[i]);
			} 
		}
		else if(x==-1) break;
	}
	return 0;
}


