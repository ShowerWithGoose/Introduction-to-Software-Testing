#include<stdio.h>


int main(){
	char s[110];
	int i=0,j=0;
	
	gets(s);
	
	if(s[i]=='0'){
		j--;
		i=2;
		while(s[i]=='0'){
			j--;
			i++;
		}	
	}
	
	printf("%c",s[i]);
	if(s[1+i]!='\0'){
		printf(".");
	}
	
	i++;
	if(s[0]!='0'){
		while(s[i]!='.'){	
		printf("%c",s[i]);
		j++;
		i++;
		}
		i++;
		while(s[i]!='\0'){
		printf("%c",s[i]);
		i++;
		}		
	}else{
		while(s[i]!='\0'){
		printf("%c",s[i]);
		i++;
		}
	}
	
	if(j>=0){
		printf("e%d",j);
	}else{
		printf("e-%d",-j);
	}
	
	return 0;
}

