#include <stdio.h>

int stack[102];


int order[102];

int main ()
{
	int count = 0;
	int index = 0;
	while(scanf("%d", &order[count]), order[count] != -1){
		count ++;
	}
	//printf("%d", count);
	/*for(int j = 0 ; j < count ; j ++)
	{
		printf("%d ", order[j]);
	}*/
	int i = 0;
	while(i < count){
		if(order[i] == 1){
			stack[index] = order[i + 1];
			index ++;
			i += 2;
			//printf("%d", index);
		}
		else if(order[i] == 0){
			if(index > 0){
				printf("%d ", stack[index - 1]);
				index --;
			}
			else printf("error ");
			i ++;
		}
		//printf("%d\n", i);
	}
	return 0;
}

