#include <stdio.h>

int zhan[120];

int main(){
	int n,i=-1,flag=0;
while(scanf("%d",&n)!=EOF){
	
if(n==-1){
	break;
}else {
	if(n==1){
		if(i>=100){
			printf("error ");flag=2;
		}
	else{
		flag=1;	
	i++;	
	}

	}else if(n==0){
		if(i==-1){
			printf("error ");flag=2;
		}else{
			flag=0;
			printf("%d ",zhan[i]);
			i--;
		}
	}else{
		if(flag==1){
			zhan[i]=n;
		}
	}
}

}	
	
	
	
	
	
	return 0;
} 

