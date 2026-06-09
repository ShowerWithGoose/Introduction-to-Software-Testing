#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main (){
	char s[105];
	int len,i,j,m,n;
	scanf("%s",s);
	len=strlen(s);
	
	if(s[0]!='0'){
		printf("%c.",s[0]);
		for(j=1;j<len;j++){
			if(s[j]!='.') printf("%c",s[j]);
			else m=j;
		}
		printf("e%d",m-1);
	}
	else{
		n=1;
		for(i=2;i<len;i++){
		if(s[i]!='0'){
			m=i;
			break;
			}	
		
		}
		if(m<len-1){
		
		printf("%c.",s[m]);
		for(i=m+1;i<len;i++){
			printf("%c",s[i]);
		}
		printf("e");
		}
		else printf("%ce",s[m]);
		
		printf("%d",n-m);
	}
	return 0;
} 

