#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int z[100]={0},ope,ptr;ptr=0;
	while(scanf("%d",&ope)){
		if(ope==-1){
			break;
		}
		else if(ope==0){
			if(ptr==0){
				printf("error ");
			}
			else{
				printf("%d ",z[--ptr]);
			}
		}
		else if(ope==1){
			scanf("%d",&z[ptr++]);
		}
	} 
 	return 0;
}

