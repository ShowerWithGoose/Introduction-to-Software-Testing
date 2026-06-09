#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
typedef struct lln{
		int item;
		struct lln *pnext;
}llist;

int main()
{
	int stack[101]={0}, op, i=0,j;
	while(1){
		scanf("%d",&op);
		if(op == -1)
			break;
		else if(!op){
			if(!i)
				printf("error ");
			else{
				i--;
				printf("%d ",stack[i]);
				stack[i] = 0;}
		}
		else{
			if(i>=100)
				printf("error ");
			else{
				scanf("%d",&stack[i]);
				i++;}
		}
	}
    return 0;
}


