#include <stdio.h>
#include <string.h>

int main(){
	char num[105];
	int flag=0;
	int time=0;
	gets(num);
	int i = 0 ;
	int len = strlen(num);
	if (num[0]=='0'){
		i=2;
		time=1;
		while(num[i]=='0'){
			time++;
			i++;
		}
		if(i==len-1){
			printf("%ce%d",num[i],time*-1);
		}else{
			printf("%c.",num[i]);
			int k=i;
			for(k=i+1;k<len;k++){
				printf("%c",num[k]);
			}
			printf("e-%d",time);
		}
	
		
	}
	else{
		time=0;
		for (i = 1;i<len;i++){
			if(num[i]=='.'){
			flag=1;
			break;
			}
			if(num[i]!='0')
				flag=1;
			time++;
		}
	if(flag==0){
		printf("%ce%d",num[0],time);
	}
	else{
		printf("%c.",num[0]);
		int k=1;
		for(k=1;k<len;k++){
			if(num[k]=='.'){
			}
			else{
				printf("%c",num[k]);
			}
		}
		printf("e%d",time);
		
	}
	}
	
	return 0;
} 

