#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>
#include <math.h>
#include <stdlib.h>
int main()
{
	int i=0,len,k;
char s[105],a;
gets(s);
len=strlen(s);
for(i=0;i<len;){
	if(s[i]!='-'){
				printf("%c",s[i]);
				i++;
				}


	
	else {
		if((s[i+1]-s[i-1]>0)&&((s[i-1]>='0'&&s[i+1]<='9')||(s[i-1]>='a'&&s[i+1]<='z')||(s[i-1]>='A'&&s[i+1]<='Z'))){
			for(a=s[i-1]+1;a-s[i+1]<=0&&((a>='0'&&a<='9')||(a>='a'&&a<='z')||(a>='A'&&a<='Z'));a++){
					printf("%c",a);
					}
			i=i+2;
		}
		else{
		
		printf("%c",s[i]);
		i++;}
	}
}
return 0;
}



