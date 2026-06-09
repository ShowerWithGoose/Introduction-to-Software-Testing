#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
	int flag,n,st[100+10],topstack=0;
	while(1){
		scanf("%d",&flag)!=EOF;
		if(flag==1){
			scanf("%d",&n);
			if(topstack>100){
				printf("error ");
				continue;
			}else{
				st[topstack++]=n;
			}
		}else if(flag==0){
			if(topstack<=0){
				printf("error ");
				continue;
			}else{
				printf("%d ",st[--topstack]);
				continue;
			}
		}else if(flag==-1){
			break;
		}
	}
	return 0;
}

