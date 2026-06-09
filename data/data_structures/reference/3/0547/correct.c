#include<stdio.h>
#include<string.h>

int panduan(int len,char a[]){ //判断一个整数是不是只有最高位有数字 
	int i;
	for(i=1;i<len;i++){
		if(a[i]!='0'){
			return 0;
		}
	}
	return 1;
}

void chuli(int len,char a[]){
	if((len==1)||panduan(len,a)==1){
		printf("%c",a[0]);
		return;
	}
	int i=len-1,j=0;
	while(a[i]=='0') i--;
	printf("%c.",a[0]);
	for(j=1;j<=i;j++){
		printf("%c",a[j]);
	}
}

int main() {
	char a[350];
	scanf("%s",a);
	int len=strlen(a);
	int i,x,y,z;
	for(i=0;i<len;i++){ //找小数点，找到则i为数组中小数点位置，否则i==len 
		if(a[i]=='.') break;
	} 
	if(a[0]>='1'){ //讨论>=1的数
		if(i==len){
			chuli(len,a);
			printf("e%d",len-1);
		}
		else{
			printf("%c.",a[0]);
			for(z=1;z<len;z++){
				if(a[z]!='.')printf("%c",a[z]);
			}
			printf("e%d",i-1);
		}
	}
	else{ // 讨论<1的数
		for(x=0;a[x]=='0'||a[x]=='.';x++);
		if(x==len-1) printf("%ce-%d",a[x],x-1);
		else{
			printf("%c.",a[x]);
			for(y=x+1;y<len;y++){
				printf("%c",a[y]);
			}
			printf("e-%d",x-1);
		}
	}
	return 0;
}

