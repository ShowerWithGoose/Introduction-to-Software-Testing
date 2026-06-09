#include<stdio.h>
#include<string.h>
int main(){
	char string[1005];
	scanf("%s",string);
	int i=0,len,cnt,j;
	len=strlen(string);
	for(i=0;i<len;i++){
		int flag=0;
		if(string[i]>='a'&&string[i+1]=='-'&&string[i+2]<='z'){
			cnt=string[i+2]-string[i];
			for(j=0;j<cnt;j++){
				printf("%c",string[i]+j);
			}
			i+=1;flag=1;
		}
		else if(string[i]>='A'&&string[i+1]=='-'&&string[i+2]<='Z'){
			cnt=string[i+2]-string[i];
			for(j=0;j<cnt;j++){
				printf("%c",string[i]+j);
			}
			i+=1;flag=1;
		}
		else if(string[i]>='0'&&string[i+1]=='-'&&string[i+2]<='9'){
			cnt=string[i+2]-string[i];
			for(j=0;j<cnt;j++){
				printf("%c",string[i]+j);
			}
			i+=1;flag=1;
		}
		if(flag==0) printf("%c",string[i]);
	}
	return 0;
} 



