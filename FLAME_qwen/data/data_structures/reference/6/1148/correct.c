#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int a[105];
int main(){
    int n,m,l,i,j,k;
    i=0;
    while(scanf("%d",&n)!=EOF){
    	if(n==-1){
    		return 0;
		} 
		else if(n==1){
			if(i==100)printf("error ");
			else scanf("%d",&a[++i]);
		}
		else if(n==0){
			if(i==0)printf("error ");
			else {
				printf("%d ",a[i--]);
			}
		}
	}
    return 0;
}


