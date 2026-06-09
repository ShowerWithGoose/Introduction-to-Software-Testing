#include<stdio.h>
#include<string.h>
int main(){
	char s[1000];
	gets(s);
	int i=0;
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]=='.')
		{
			break;	
		}
	}//看小数点在哪 
	int len=strlen(s);
	int flag=1;
	if(i==1)
	{
		if(s[i-1]=='0')	flag=0;
	}//判断小数点前与1大小，继而判断正负flag=1为正
	if((i==1)&&(flag==1)){
		printf("%s",s);
		printf("e0");
//		printf("*");
	}
	else if(i==1&&flag==0){//0.0123    0.1
		int j=2;
		while(s[j]=='0'){	j++;	}
//		printf("%d",j);  0.01对应3 
//		printf("*");  
//printf("%d\n",len);//17
//printf("%d",j);//16
		printf("%c",s[j]);
		if(len-j!=1)printf(".");
		for(int k=j+1;s[k]!='\0';k++){
			printf("%c",s[k]);
		}
		printf("e-%d",j-1);
	}
	else if(i!=1){//123.456  123.01
//		printf("%d",len);
//		printf("%d\n",i);//i-1
		printf("%c.",s[0]);
		for(int j=1;j<i;j++){
			printf("%c",s[j]);
		}
		for(int j=i+1;s[j]!='\0';j++){
			printf("%c",s[j]);
		}
		printf("e%d",i-1);
	}
	return 0;
} 



