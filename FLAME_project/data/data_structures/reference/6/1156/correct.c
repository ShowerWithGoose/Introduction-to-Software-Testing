#include<stdio.h>
#include<string.h>
#include<math.h>
int i,j,k,m,n,fl;
int pos;
int a[1005];
int main(){
	pos=0;
	while(scanf("%d",&n)!=-1){
		if(fl==1){
			pos++;
			if(pos>100){
				printf("error ");
				pos--;
				continue;
			}
			a[pos]=n;
			fl=0;
		}
		else if(n==1) fl=1;
		else if(n==0){
			if(pos==0){
				printf("error ");
				continue;
			}
			printf("%d ",a[pos]);
			pos--;
		}
	}
	return 0;
}


