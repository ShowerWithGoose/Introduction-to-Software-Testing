#include <ctype.h>
#include <iso646.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 1024
int main()
{
	int line[102]={0};
	int head=0;
	int op,num;
	while(scanf("%d ",&op)!=-1){
		if(op==1){
			scanf("%d ",&num);
			if(head==99){
				printf("error ");
				continue;
			}
			else{
				line[head]=num;
				head++;
			}
		}
		else if(op==0){
			if(head==0){
				printf("error ");
				continue;
			}
			else{
				printf("%d ",line[head-1]);
				head--;
			}
		}
		else if(op==-1){
			return 0;
			break;
		}
	}
    return 0;
}


