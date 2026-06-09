#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
int a[101];
int c=0,d=0,e=0,f=0;
int main(){
	
	while(scanf("%d",&c)){
		if(c==1){
			if(d<=99){scanf(" %d",&a[d]);d++;}
			else printf("error ");
		}
		else if(c==0){
			if(d>0){printf("%d ",a[d-1]);d--;}
			else printf("error ");
		}
		else if(c==-1)break;
		getchar();
	}
	return 0;
} 



