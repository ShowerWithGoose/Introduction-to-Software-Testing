#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>
//int范围：2147483647 (-2^31--2^31-1)
//scanf("%%",&,&);
//printf("%",);
//for(int i=0;i<n;i++){}
//if(){}
int main(){
	int zhan[100],a,b,volume=0;
	memset(zhan,0,sizeof(zhan));
	while(scanf("%d",&a)!=EOF){
		if(a==1){
			scanf("%d",&b);
			if(volume==100){
				printf("error ");
				continue;
			}
			volume++;
			for(int i=volume-1;i>0;i--){
				zhan[i]=zhan[i-1];
			}
			zhan[0]=b;
		}//将一个元素存入栈
		if(a==0){
			if(volume==0){
				printf("error ");
				continue;
			}
			printf("%d ",zhan[0]);
			for(int i=0;i<volume;i++){
				zhan[i]=zhan[i+1];
			}
			volume--;
		}
		if(a==-1) break;
		}
	return 0;	
}

