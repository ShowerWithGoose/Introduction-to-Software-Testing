#include <stdio.h>
int  main()
{
	int stack[100] = {0} ,top = 0 , flag ,i;
	while(1){
		scanf("%d",&flag);
		if(flag == -1){
			return 0;
		}
		else if(flag == 1){
			scanf("%d",&stack[top++]);
		}
		else if(flag == 0){
			if(top == 0){
				printf("error ");
			}
			else {
				printf("%d ",stack[--top]);
			}
		}
	}
	return 0;
}

