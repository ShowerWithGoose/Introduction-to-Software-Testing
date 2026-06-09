#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int stack[500005];
int main() {
	int judge;
	int point=0;
	while(1) {
		scanf("%d",&judge);
		if(judge==-1) break;
		else {
			if(judge==1) {
				int num;
				scanf("%d",&num);
				if (point==99) printf("error ");
				else 
				{
					stack[point]=num;
					point++;
				}
			}
			else if(judge==0) 
			{
				if (point==0) printf("error ");
				else 
				{
					printf("%d ",stack[point-1]);
					stack[point]=0;
					point--;
				}
			}
		}
	}
	return 0;
}

