#include <stdio.h>
#include <string.h>
char s[200];
int main(){
	int fstnum=0,lstnum=0,i=0,j=0,dotnum=0;
	gets(s);
	if(s[0]=='0'){
		for(j=0;j<strlen(s);j++){
			if(s[j]-'0'>0){
				fstnum=j;//第一个有效数字在s中的位置
				break; 
			}	
		}
		lstnum=strlen(s)-1;
	    printf("%c",s[fstnum]);
	    if(fstnum==lstnum){
		for(j=(fstnum+1);j<lstnum;j++){
			printf("%c",s[j]);
		}
		}
		else{
			printf(".");
			for(j=(fstnum+1);j<=lstnum;j++){
			printf("%c",s[j]);
		}
		}
		printf("e-%d",fstnum-1);	
	}
	
	
	
	else{	//第一个不是0 
	printf("%c",s[0]);
	for(i=0;s[i]!='.';i++){

	}
	dotnum=i;
	if(dotnum==1){
		for(i=1;i<strlen(s);i++){
			printf("%c",s[i]);
		}
		printf("e0");
	}
	else{
		printf(".");
		for(i=1;i<strlen(s);i++){
			if(s[i]=='.'){
				continue;
			}
			else{
				printf("%c",s[i]);
			}
			
		}
		printf("e%d",dotnum-1);
	}
	
	
	
	
	
	
	
	}
		
return 0;
}

