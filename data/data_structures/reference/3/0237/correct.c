#include <stdio.h>
int main(){
	
	char num[1000];
	gets(num);
	int i,t;
	if(num[1]=='\0'){
		printf("%d",num[0]);
	}
	if(num[1]=='.'){
		if(num[0]!='0'){
			for(i=0;num[i]!='\0';i++){
				printf("%c",num[i]);
			}
			printf("e0");
		}
		if(num[0]=='0'){
			i=2;
			while(num[i]=='0'){
				i++;
			}
			t=i-1;
			if(num[i+1]=='\0'){
				printf("%c",num[i]);
				
			}
			else{
				printf("%c.",num[i]);
				i++;
				for(;num[i]!='\0';i++){
					printf("%c",num[i]);					
				}
			}
			printf("e-%d",t);
		}
	}
	else{
		i=3;
		while(num[i]!='.'){
			i++;
		}
		t=i-1;
		printf("%c.",num[0]);
		for(i=1;num[i]!='\0';i++){
			if(num[i]!='.'){
				printf("%c",num[i]);
			}
		}
		printf("e%d",t);
		
	}
	
	return 0;
}



