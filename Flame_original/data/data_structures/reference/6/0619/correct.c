#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int a,stack[100],k = 0;
	while(1){
		scanf("%d",&a);
		if(a == -1){
			break;
		}
		else if(a == 0){
			if(k == 0){
				printf("error ");
			}
			else if(k > 0){
				printf("%d ",stack[k-1]);
				stack[k-1] = 0;
				k--;
			}
		}
		else if(a == 1){
			if(k > 99){
				printf("error ");
			}
			else if(k <= 99){
				scanf("%d",&stack[k]);
				k++;
			}
		}
	}
	return 0;
}


