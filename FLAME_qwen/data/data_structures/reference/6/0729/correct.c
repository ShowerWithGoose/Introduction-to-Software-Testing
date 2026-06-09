#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define ll long long

int main()
{
	int stack[100];
	int i=0;
	int judge;
	while(scanf("%d",&judge)){
		if(judge==1){
			if(i==99){
				printf("error ");
			}
			else{
				scanf("%d",&stack[i]);
				i++;
			}
		}
		else if(judge==0){
			if(i==0){
				printf("error ");
			}
			else {
				printf("%d ",stack[i-1]);
				i--;
			}
		}
		else if(judge==-1) break;
	} 
	return 0;
}


