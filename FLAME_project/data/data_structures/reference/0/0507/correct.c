#include<stdio.h>
#include<math.h>
#include<string.h>

char str[100000],j;
int len,i;
int main(){
	scanf("%s",str);
	len=strlen(str);
	for(i=0;i<len;i++){
		if(str[i]=='-'){ 
			if((str[i-1]>='a'&&str[i+1]<='z'&&str[i-1]<str[i+1])||(str[i-1]>='A'&&str[i+1]<='Z'&&str[i-1]<str[i+1])||(str[i-1]>='0'&&str[i+1]<='9'&&str[i-1]<str[i+1])){
				for(j=str[i-1];j<str[i+1];j++)	printf("%c",j+1);
				i++;
			}
			else printf("%c",str[i]);
		}
		else printf("%c",str[i]);
	}
	return 0;
}



