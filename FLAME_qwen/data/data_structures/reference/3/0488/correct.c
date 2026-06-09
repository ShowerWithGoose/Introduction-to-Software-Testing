#include<stdio.h>
#include<string.h>
int main(){
	int point,length,n,i;
	char s[105];
	gets(s);
	length=strlen(s);
	for(point=0;s[point]!='.';point++);
	if(point==1){//形如x.xxx
		if(s[0]!='0'){
			printf("%s",s);
			printf("e0");
		}else{
			for(n=1;s[point+n]=='0';n++);
			for(i=point+n;i<length;i++){
				printf("%c",s[i]);
				if(i-point-n==0&&i<length-1)printf(".");
			}
			printf("e-%d",n);
		}
	}else{
		n=point-1;
		for(i=0;i<length;i++){
			if(s[i]!='.')
				printf("%c",s[i]);
			if(i==0&&i<length-1)printf(".");
		}
		printf("e%d",n);
		
	}
	
	
	return 0;
}

