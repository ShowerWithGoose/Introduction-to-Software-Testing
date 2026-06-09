#include <stdio.h>

int main()
{
	int a[100] = {0}, op = 0, i = -1;
	while(op != -1){
		scanf("%d", &op);
		if(1 == op){
			if(99 == i){
				printf("error ");
			}
			else{
				i++;
				scanf("%d", &a[i]);
			}
		}
		if(0 == op){
			if(-1 == i){
				printf("error ");
			}
			else{
				printf("%d ", a[i]);
				a[i] = 0;
				i--;
			}
		}
	}
	return 0;
}

