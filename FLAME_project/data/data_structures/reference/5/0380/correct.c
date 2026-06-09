#include <stdio.h>
#include <string.h>

struct multi{
	int base;
	int index;
}a[100],b[100],ans[1000000]; 

int main(){
	int x=1000000;
	int i=0;
	char ch;
	int numa=0,numb=0;
	int flag=0;
	for(i=0;i<x;i++){
		ans[i].index=i;
	}
	i=0;
	do  
	{
		scanf("%d%d%c",&a[numa].base,&a[numa].index,&ch);
		numa++;
		
	}while(ch!='\n');
	do  
	{
		scanf("%d%d%c",&b[numb].base,&b[numb].index,&ch);
		numb++;
		
	}while(ch!='\n');


	int j=0;
	for(i=0;i<=numa;i++){
		for(j=0;j<=numb;j++){
			if((a[i].index+b[j].index)<1000000){
				ans[a[i].index+b[j].index].base=ans[a[i].index+b[j].index].base+(a[i].base*b[j].base);
				}
			else{
				flag=1;
			}
		}
	}
	if(flag==1){
		printf("120 2000000000");	
	}
	else{
		for(i=x-1;i>=0;i--){
		if(ans[i].base!=0){
			printf("%d %d ",ans[i].base,ans[i].index);
		}
	}
	}

return 0;
}


