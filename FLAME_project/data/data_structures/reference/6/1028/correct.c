#include <stdio.h>
#include <string.h>
#include <math.h>
#include<stdlib.h>
#define ll long long
int main ()
{
    int n,num,l=0,flag=0;
    int zhan[101]={0};
    
    do{
		scanf("%d",&n);
		switch (n) {
			case 1:
				scanf("%d",&zhan[l]);
				l++;
				break;
			case 0:
				if(l>0){
					l--;
					printf("%d ",zhan[l]);
				}
				else printf("error ");
				break;
			default:
				flag=1;
				break;
		}
		if(flag){
			break;
		}
	}while(1);
    
    return 0;
}

