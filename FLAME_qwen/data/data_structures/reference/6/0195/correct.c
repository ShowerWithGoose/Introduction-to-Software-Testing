#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#include<malloc.h>
#define ULL unsigned long long 
#define LL long long
#define fep(i,l,r) for(int i=(l);i<=r;i++)
#define ffep(i,r,l) for(int i=(r);i>=l;i--)
int a[100],re=-1; 
int main(){
	int x;
	while(~scanf("%d",&x)){
		if(x==-1)break;
		else if(!x){
			if(re==-1)printf("error ");
			else {
				printf("%d ",a[re--]);
			}
		}
		else {
			if(re==100){
				printf("error ");
			}
			else {
				scanf("%d",&x);
			    a[++re]=x;
			}
		}
	}
} 

