#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
char str[1000000000];
int main()
{
int i=0,a;
char b,c;
scanf("%s",str);
a=strlen(str);
for(i=0;i<a;i++){
	if(str[i]=='-'){
		if((((str[i-1]>='a')&&(str[i-1]<='z'))&&((str[i+1]>='a')&&(str[i+1]<='z')))&&(str[i+1]>str[i-1])){
		for(b=str[i-1]+1;b<str[i+1];b++){
		printf("%c",b);	
		}
		}else if((((str[i-1]>='A')&&(str[i-1]<='Z'))&&((str[i+1]>='A')&&(str[i+1]<='Z')))&&(str[i+1]>str[i-1])){
			for(c=str[i-1]+1;c<str[i+1];c++){
		printf("%c",c);	
		}
		}else if((((str[i-1]>='0')&&(str[i-1]<='9'))&&((str[i+1]>='0')&&(str[i+1]<='9')))&&(str[i+1]>str[i-1])){
			for(c=str[i-1]+1;c<str[i+1];c++){
		printf("%c",c);	
		}
		}else{
			printf("%c",str[i]);
		}
	}else{
		printf("%c",str[i]);
	}
}
return 0;
}

