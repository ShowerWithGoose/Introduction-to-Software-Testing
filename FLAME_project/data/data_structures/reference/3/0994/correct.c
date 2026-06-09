#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_N 105

char tmp[MAX_N];

void Clear(char s[]);//用于清除前置0 

void Re_Clear(char s[]);//用于清除后置0 

void SciCount_int(char s[]);//整形计数 

void SciCount_float(char s[]);//浮点型计数

int main(){
	
	char num[MAX_N];
	gets(num);
	int flag=0;
	for(int i=0;num[i]!='\0';++i){
		if(num[i]=='.'){
			flag=1;
			break;
		}
	}
	if(!flag)
		SciCount_int(num);
	else 
		SciCount_float(num);
	
	return 0;
}

void Clear(char s[]){
	
	strcpy(tmp,s);
	int i=0,j=0,len;
	len=strlen(s);
	for(;tmp[i]=='0';i++)
	;
	for(;j<len;j++,i++)
		s[j]=tmp[i];
	s[j]='\0';
	return ;
}

void Re_Clear(char s[]){
	
	int len =strlen(s);
	for(int i=len-1;s[i]=='0'||s[i]=='.';--i){
		s[i]='\0';
	}
	return ;
}

void SciCount_int(char s[]){
	
	Clear(s);//清除前置0 
	if(s[0]=='\0'){//判断原数据是否为0 
		putchar('0');
		return ;
	}
	putchar(s[0]);
	if(s[1]=='\0')//判断是否需要科学计数 
		return ;
	int i=1,flag;
	flag=strlen(s)-1;//指数 
	Re_Clear(s);
	if(s[1]!='\0')	//判断底数是否需要'.' 
		putchar('.');
	for(;s[i]!='\0';++i)//输出 
		putchar(s[i]);
	printf("e%d",flag);
	putchar('\n');
					
	return ;
}

void SciCount_float(char s[]){
	
	Clear(s);
	
	if(s[0]!='.'){//整数非0
		if(s[1]=='.'){//整数为个位 	
			Re_Clear(s);
			for(int j=0;s[j]!='\0';j++){
				putchar(s[j]);
			}
			printf("e0");
		}
		else{//整数超过十位
			int i=0;
			for(;s[i]!='\0'&&s[i]!='.';i++)
				;
			int index=i-1;
			Re_Clear(s);
			if(s[1]=='\0'){
				putchar(s[0]);
				printf("e%d",index);
			}
			else{
				putchar(s[0]);
				putchar('.');
				for(i=1;s[i]!='\0';i++){
					if(s[i]=='.'){
						continue;
					}
					putchar(s[i]);
				}
				printf("e%d",index);
			}
		} 
		
		return ;
	}
	//整数为0 
	Re_Clear(s);
	if(s[0]=='\0'){//判断为0 
		putchar('0');
		return ;
	}
	int i=1,index=1;
	for(;s[i]!='\0';i++){
		if(s[i]!='0'){
			break;
		}
		index++;
	}
	putchar(s[i++]);
	if(s[i]!='\0'){
		putchar('.');
		for(;s[i]!='\0';i++){
			putchar(s[i]);
		}
	}
	printf("e-%d",index);
	
	return ;
}



