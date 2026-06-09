#include<stdio.h>
#include<string.h>
int main(){
	char str[105];
	int i=0;
	int p;
	int cnt_zero=0;
	int cnt_number=0;
	
	gets(str);
	if(str[1]=='.'){
		if(str[0]=='0'){
			for(i=2;str[i]=='0';i++){
				cnt_zero++;
			}
			printf("%c",str[i]);
			if(i!=strlen(str)-1) printf(".");//如果这个小数除最后一位都是0 不打.  除此之外都要打 
			for(p=i+1;p<strlen(str);p++){
				printf("%c",str[p]);
			}
			printf("e");
			printf("-");
			printf("%d",cnt_zero+1);
		}//应对小数为0.xxxx的情况 
		
		if(str[0]!='0'){
			printf("%s",str);
			printf("e0");
		}
	}//应对小数为x.xxxxx的情况 
	
	else{
		for(i=0;str[i]!='.';i++){
			cnt_number++;
		}
		printf("%c",str[0]);
		printf(".");
		for(p=1;p<i;p++){
			printf("%c",str[p]);
		}
		for(p=i+1;p<strlen(str);p++){
			printf("%c",str[p]);
		}
		printf("e%d",cnt_number-1);
	}
	
	
return 0;
}

