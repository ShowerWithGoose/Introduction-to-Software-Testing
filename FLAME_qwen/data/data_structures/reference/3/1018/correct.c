#include<stdio.h>

int main(){
char s[101] = {'\0'};
int counter_point = 0, counter_num = 0, counter;
for(int i=0;i<100;i++){
	scanf("%c",&s[i]);
	if(s[i] == '.')counter_point = i;
	else if(s[i] == '\n'){
		counter = i-1;
		break;
	}
}
if(s[0] > '0'){
	for(int i=0;i<=counter;i++){
		if(i==counter_point)continue;
		printf("%c",s[i]);
		if(i==0)printf(".");
	}
	printf("e%d",counter_point-1);
}
else{
	for(int i=0;i<counter;i++){
		if(s[i]=='0'||s[i]=='.')counter_num++;
		else break;
	}
	if(counter_num==counter)printf("%ce%d",s[counter],counter_point-counter_num);
	else{
		for(int i=counter_num;i<=counter;i++){
			printf("%c",s[i]);
			if(i==counter_num)printf(".");
		}
		printf("e%d",counter_point-counter_num);
	}
}
return 0;
} 

