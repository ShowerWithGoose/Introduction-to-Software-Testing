#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main(){
	int i,j,l;
	char s[105];
	gets(s);
	l=strlen(s);
	if(s[0]=='0'){
		for(i=2;i<l;i++){
			if(s[i]!='0'){
				printf("%c",s[i]);
				if(i!=l-1)
				printf(".");
				for(j=i+1;j<l;j++)
				printf("%c",s[j]);
				break;
			}
		}
		printf("e-%d",i-1);
	}
    else if(s[0]>'0'&&s[1]=='.'){
    	for(i=0;i<l;i++)
    	printf("%c",s[i]);
        printf("e0");
	}
    else{
    	printf("%c.",s[0]);
    	for(i=1;i<l;i++){
    		if(s[i]=='.'){
    			j=i;
    		    continue;
			}
    		printf("%c",s[i]);
		}
		printf("e%d",j-1);
	}
	return 0;
}




