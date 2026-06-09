#include <stdio.h>
#include <string.h>
int tell(char,char);
int main(){
	char ch[5000],sh[5000];
	int i,j;
	gets(ch);
	for(i=0,j=0;i<strlen(ch);){
		if(ch[i]!='-'){
			sh[j++]=ch[i++];
		}else{
			if(tell(ch[i-1],ch[i+1])){
				char temp;
				for(temp=ch[i-1]+1;temp<=ch[i+1];temp++){
					sh[j++]=temp;
				}
				i+=2;
			}else{
				sh[j++]=ch[i++];
			}
		}
		
	}
	sh[j]='\0';
	if(memcmp(sh,ch,strlen(sh))>0){
		printf("%s",sh);
	}else{
		printf("%s",ch);
	}
	return 0;
}
int tell(char a,char b){
	if(a>='a'&&a<='z'){
		if(b<='z'&&b>='a'){
			return 1;
		}else{
			return 0;
		}
	}else if(a>='A'&&a<='Z'){
		if(b<='Z'&&b>='A'){
			return 1;
		}else{
			return 0;
		}
	}else if(a>='0'&&a<='9'){
		if(b<='9'&&b>='0'){
			return 1;
		}else{
			return 0;
		}
	}else{
		return 0;
	}
	
	
}

