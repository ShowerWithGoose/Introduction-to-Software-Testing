#include<stdio.h>
#include<string.h>
#include<math.h>

char ch[105];

int main(){
	gets(ch);
	int i=0,j=0,l=strlen(ch);
	while(ch[i]!='.'){
		i++;
	}
	if(ch[0]!='0'){
		printf("%c.",ch[0]);
		for(j=1;j<i;j++){
			printf("%c",ch[j]);
		}
		for(i+=1;i<l;i++){
			printf("%c",ch[i]);
		}
		printf("e%d",j-1);
	}
	else{
		i++;
		j=i;
		while(ch[i]=='0'){
			i++;
		}
		printf("%c",ch[i]);
		if(i+1<l){
			printf(".");
		}
		int w=i-j+1;
		for(i+=1;i<l;i++){
			printf("%c",ch[i]);
		}
		printf("e-%d",w);
	}
	return 0;
} 

