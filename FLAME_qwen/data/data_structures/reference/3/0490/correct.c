#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char s[101],r[101];
	gets(s);
	int i=0,a=0,b=0;
	int l=strlen(s);
	for(i=0;i<l;i++){
		if(s[i]=='0')
		continue;
		if(s[i]!='0'&&s[i]!='.'){
			if(a!=0)
			continue;
			a=i+1;
			if(s[0]=='0')
			a=i-1;
		}
		if(s[i]=='.')
	    b=i-1;
	}
	if(s[0]=='0'){
		if(a+2>=l-1)
		printf("%c",s[a+1]);
		else
		printf("%c.",s[a+1]);
	for(i=a+2;i<l;i++){
		printf("%c",s[i]);
	}
	printf("e-%d",a-b);
}
    else if(s[0]!=0){
    	printf("%c.",s[0]);
    	for(i=a;i<=l-1;i++){
    		if(s[i]=='.')
    		continue;
    		printf("%c",s[i]);
		}
		printf("e%d",abs(a-b-1));
	}

return 0;	
}

