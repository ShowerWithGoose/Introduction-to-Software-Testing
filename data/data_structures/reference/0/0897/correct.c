#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
	char str[105];
	scanf("%s",str);
	int len=strlen(str);
	int j;
    for(int i=0;i<len;i++){
    	if(str[i]!='-'){
    		printf("%c",str[i]);
		} 
		else{
			if(str[i-1]>='0'&&str[i-1]<='9'&&str[i+1]>='0'&&str[i+1]<='9'&&str[i-1]<str[i+1]){
			for(j=1;str[i+1]>str[i-1]+j;j++){
				printf("%c",str[i-1]+j);
			}	
			i+=1;
			}
			if(str[i-1]>='a'&&str[i-1]<='z'&&str[i+1]>='a'&&str[i+1]<='z'&&str[i-1]<str[i+1]){
				for(j=1;str[i+1]>str[i-1]+j;j++){
				printf("%c",str[i-1]+j);
			}	
			i+=1;
			}
			if(str[i-1]>='A'&&str[i-1]<='Z'&&str[i+1]>='A'&&str[i+1]<='Z'&&str[i-1]<str[i+1]){
				for(j=1;str[i+1]>str[i-1]+j;j++){
				printf("%c",str[i-1]+j);
			}	
			i+=1;
			}
				printf("%c",str[i]);
				
		}
	}
	
	return 0;
}

