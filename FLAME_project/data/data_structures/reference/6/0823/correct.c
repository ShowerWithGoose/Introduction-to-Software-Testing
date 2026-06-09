#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	int array[105];
	int m,top=0;
	while(scanf("%d",&m)!=EOF){
		if(m==1){
			if(top==100){
			    printf("error ");
			    continue;
			}
		    scanf("%d",&array[top++]);
		}
		else if(m==0){
			if(top==0){
			    printf("error ");
			    continue;
			}
			printf("%d ",array[top-1]);
			top--;
		}
		else if(m==-1){
			return 0;
		}
	}
	return 0;
}


