#include <stdio.h>
#include <math.h>
#include <string.h> 
#include <ctype.h>

int main()
{
	int num[2]={0,0,0};
	char fh[2]="+";
	
	while(fh[0]!='='){
		scanf("%d %c",&num[1],&fh[1]);
		while(fh[1]=='/'||fh[1]=='*'){
				scanf("%d %c",&num[2],&fh[2]);
				if(fh[1]=='/'){
					num[1]=num[1]/num[2];
				}
				else{
					num[1]=num[1]*num[2];
				}
				fh[1]=fh[2];
		}
		if(fh[0]=='+'){
			num[0]=num[0]+num[1];
		}
		if(fh[0]=='-'){
			num[0]=num[0]-num[1];
		}	
		fh[0]=fh[1];
	}
	printf("%d",num[0]);
	return 0;
 }





