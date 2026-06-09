#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>

int main(){
	int j,k,i=0;
	int op[200];
	for(i=0;;){
		scanf("%d",&k);
		if(k==1){
			scanf("%d",&j);
			if(i==100){
				printf("error ");
			}
			else
				op[i]=j;
				i++;
		}
		else if(k==0){
			if(i==0){
				printf("error ");
			}
			else
				printf("%d ",op[--i]);
		}
		else if(k==-1){
			break;
		}
	}
	return 0;
}

