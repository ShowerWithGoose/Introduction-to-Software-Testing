#include<stdio.h>
#include<string.h>
int main(){
	int len,k,i,j;
	char s[105];
	scanf("%s",s); 
	len=strlen(s)-1;
	if(s[0]=='0'){
		for(i=0;i<=len-1;i++){
			if(s[i]!='0'&&s[i]!='.'){
				break;
			}
		}
		k=i;
		if(s[i+1]!='\0'){
			printf("%c.",s[i]);
			i++;
			for(;i<=len;i++){
				printf("%c",s[i]);
			}
			printf("e-%d",k-1);
		}else{
			printf("%c",s[i]);
			printf("e-%d",k-1);
		}	
	}else{
		printf("%c.",s[0]);
		for(i=0;i<=len-1;i++){
			if(s[i]=='.'){
				break;
			}	
		}
		k=i;
		for(j=1;j<=len;j++){
			if(s[j]!='.'){
				printf("%c",s[j]);
			}
		}
		printf("e%d",i-1);
	}
	return 0;	
}

