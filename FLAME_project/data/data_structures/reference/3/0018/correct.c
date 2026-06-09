#include<stdio.h>
#include<string.h>
//将字符串100位大数转化为科学记数法 
char str[102],*p;
int dif,i,count;
int main(){
	scanf("%s",str);
	if(strchr(str,'.')==NULL){//全整数情况 
		count=strlen(str)-1;
		for(i=strlen(str)-1;str[i]=='0';i--){//把0都扔掉 
			str[i]='\0';
		}
		if(strlen(str)==0){//为0情况 
		//printf("%d",strlen(str));
		str[0]='0';
		}
		
		if(strlen(str)==1){//除去0只有一位情况 
			printf("%ce%d",str[0],count);
		}
		else{//多位情况 
			printf("%c.",str[0]);
			for(i=1;i<strlen(str);i++){
				printf("%c",str[i]);
			} 
			printf("e%d",count);
			
		}
	}
	else{
		if(str[0]=='0'){//首位是0，'.'必在第二位，次数为负 
			for(i=2,count=1;str[i]=='0';i++)
			count++;
			printf("%c",str[i]);
			if(str[i+1]!='\0')
			printf("%c",'.');
			for(i++;str[i]!='\0';i++)
				printf("%c",str[i]);
			printf("e-%d",count);	
		}
		else{//首位不是0，次数>=0
			count=strchr(str,'.')-str-1;
			printf("%c.",str[0]);
			for(i=1;str[i]!='\0';i++){
				if(str[i]!='.')
				printf("%c",str[i]);
			}
			printf("e%d",count);
		 
			
		}
		
		
		
		
		
		p=strchr(str,'.');
		count=p-str-1;

		//printf("%d",count);

		
	} 
		
	


	return 0;
	
} 

