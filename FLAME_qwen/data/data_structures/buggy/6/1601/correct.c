#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
	int s[100];
	int i=0;
	int a,b;
	while(scanf("%d",&a)==1){
		if(a==0&&i==0){
			printf("error ");
		}else if(a==1){
			scanf("%d",&b);
			s[i++]=b;
		}else if(a==0){
			printf("%d ",s[i-1]);
			i--;
		}else if(a==-1){
			break;
		}
	}
	return 0;
 } 

