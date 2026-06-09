#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
int top=0;
int a[100],op;

int main() {

	while(1) {
		scanf("%d",&op);
		if(op==-1) break;
		if(op==0) {
			if(top==0) {
				printf("error ");
				continue;
			}
			printf("%d ",a[top]);
			top--;
			continue;
		}
		if(top==99&&op==1) {
			printf("error ");
			continue;
		}
		top++;
		scanf("%d",&a[top]);


	}



	return 0;
}

