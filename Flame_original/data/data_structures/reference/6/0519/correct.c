#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
int main (){
	int zhan[1000];
	int i=0;
	int op;
	for(i=0;;){
	scanf("%d ",&op);
	{
	if(op==-1)
		break;
	if(op==1){
		scanf("%d ",&zhan[i]);
		i++;
	}
	if(op==0){
		i--;
		if(i<0){
			printf("error ");
			i=0;
		}
		else 
			printf("%d ",zhan[i]);
		
		}
    }
}
	return 0; 
} 



