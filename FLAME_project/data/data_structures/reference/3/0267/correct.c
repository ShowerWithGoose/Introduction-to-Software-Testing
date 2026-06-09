#include<stdio.h>
#include<string.h>
int main()
{
	char s[105];
	int m=0,n=0,i,j,k,len,sign=0;
	gets(s);
	len=strlen(s);
	if(s[0]=='0'){
		for(i=2;s[i]=='0';i++,m++);
		printf("%c",s[i]);
		for(j=i+1;j<len;j++){
			if(s[j]!='0')
			sign=1;
		}
		if(sign==0)
		printf("e-%d",m+1);
		else{
			printf(".");
			for(k=i+1;k<len;k++)
			printf("%c",s[k]);
			printf("e-%d",m+1);
		}
	}
	else{
		for(i=0;s[i]!='.';i++,n++);
		printf("%c.",s[0]);
		for(j=1;j<len;j++){
			if(s[j]!='.')
			printf("%c",s[j]);
		}
		printf("e%d",n-1);
	}
	
	return 0;
}

