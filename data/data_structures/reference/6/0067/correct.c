#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define pf printf
#define sc scanf
#define N 10005
int main()
{
	int stack[105],top = -1;
	int a = 0;
	while(1){
		sc("%d",&a);
		if(a==1){
			if(top==99)	{
				pf("error ");continue;
			}
			int b;
			sc("%d",&b);
			top++;
			stack[top] = b;
		}
		else if(a==0){
			if(top==-1)	{
				pf("error ");continue;
			}
			pf("%d ",stack[top]);
			top--;
		}
		else if(a==-1)	return 0;
	} 

	return 0;
}


