#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
stack[100000]={0};
int main()
{
	int i,j;
	int k=0,tail=0,m;
	for (;1>0;)
	{
	    scanf("%d",&k);
	if (k==-1) break;
	if (k==0) {
	   if (tail==0) printf("error ");
	   else {
	   	printf("%d ",stack[tail]);
	   	tail--;
	   }
	}
	else {
		scanf("%d",&m);
		tail++;
		stack[tail]=m;
	}
	}
	return 0;
}


