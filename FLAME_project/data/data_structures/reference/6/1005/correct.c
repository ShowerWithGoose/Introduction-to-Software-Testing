#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include <stdlib.h>
int main()
{
    int a[101],flag,n,num;
    n=-1;
    while(1){
    	scanf("%d",&flag);
    	if(flag==-1)
    		break;
    	else if(flag==1){
    		if(n==99)
    			printf("error ");
    		else{
    			scanf("%d",&num);
    			n++;
    			a[n]=num;
			}	
		}
		else if(flag==0){
			if(n==-1)
				printf("error ");
			else{
				printf("%d ",a[n]);
				n--;
			}
		}
	}
	return 0;
}


