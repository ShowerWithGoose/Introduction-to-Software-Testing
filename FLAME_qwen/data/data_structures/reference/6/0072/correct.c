#include<stdio.h>
#include<string.h>
#include<math.h>

int main(){
int zhai[201];
int panduan,shu;
int i=0;
while(1){
	scanf("%d",&panduan);
	if(panduan==1){
		scanf("%d",&shu);
		if(i==100){
			printf("error");
			printf(" ");
		}
		else{
			zhai[i++]=shu;
		}
	}
	if(panduan==0){
		if(i==0){
			printf ("error");
			printf(" ");
		}
		else{
			printf("%d",zhai[--i]);
			printf(" ");
		}
	}
       if(panduan==-1){
       	break;
	   }

 }
}

