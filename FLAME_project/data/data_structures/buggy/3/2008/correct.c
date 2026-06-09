#include <stdio.h>
#include <string.h>
int main()
{
	char s[1000],c[1000];
	int n=1,i,j=0;
	gets(s);
	if(s[0]=='0'){
		for(i=2;s[i]=='0';i++){
		}
		n=1-i;
		c[j]=s[i];
		if(i<(strlen(s)-1)){
			c[++j]='.';
			for(j=j+1,i=i+1;i<strlen(s);j++,i++){
			    c[j]=s[i];
		    }
		}
		c[j+1]='\0';
	}
	else{
		c[0]=s[0];
		c[1]='.';
		for(i=1;s[i]!='.';i++){
			c[i+1]=s[i];
		}
		n=i-1;
		for(i=i+1;i<=strlen(s);i++){
			c[i]=s[i];
		}
		
	}
	printf("%se%d",c,n);
		return 0;
}

