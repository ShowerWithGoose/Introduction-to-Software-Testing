#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define  PR printf
typedef long long LL;
#define MAXSIZE 100
int s[MAXSIZE];

//1 3 1 5 1 7 0 0 1 8 0 1 12 1 13 0 0 0 0 1 90 1 89 0 -1

//7 5 8 13 12 3 error 89  
int main()
{
	int op,b,TOP=-1;
	while(scanf("%d",&op))
	{
		if(op==-1){
			break;
		}
		else if(op==1){
			scanf("%d",&b);
			if(TOP==MAXSIZE-1){
				printf("error ");
			}
			else{
				s[++TOP]=b;
				//printf("\n----%d\n",s[TOP]);
			}
		}
		else if(op==0){
			if(TOP==-1){
				printf("error ");
			}
			else{
				printf("%d ",s[TOP--]);
			}
		}
	}
	return 0;
}

