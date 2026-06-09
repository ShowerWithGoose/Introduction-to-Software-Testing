#include <stdio.h>
 
int main() {
	
	int stack[110] = {0};
	int order, num, p = 0;
	while(scanf("%d", &order)) {
		if (order == 1){
			scanf("%d", &num);
			if (p <= 99)
				stack[p++] = num;
			else printf("error ");
	
		}else if (order == 0) {
			if (p > 0)
				printf("%d ", stack[--p]);
			else printf("error ");	
			
		}else	
			break;
	}
	
	return 0;
}

