#include <stdio.h>

int main()
{
	int a[150],n,op,top=0;
	while(scanf("%d",&op)!=EOF){
		switch(op){
			case 1:
				scanf("%d",&a[top]);  top++;  break;
			case 0:
				if(top>0){
					printf("%d ",a[top-1]);  top--;
				}
				else printf("error ");
				break;
			case -1:
				return 0;
		}
	}
}

