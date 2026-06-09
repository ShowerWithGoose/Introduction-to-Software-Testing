#include<stdio.h>
#include<string.h>
int main()
{
	char s[105],x[105]="";
	int i;
	gets(s);
	if(s[0]=='0'){
		for(i=2;s[i]=='0';i++);
		if(i+1==strlen(s)) printf("%ce%d",s[i],1-i);
		else printf("%c.%se%d",s[i],s+i+1,1-i);
	}
	else{
		for(i=0;s[i]!='.';i++);
		strncpy(x,s,i);
		printf("%c.%s%se%d",s[0],x+1,s+i+1,i-1);
	}
	return 0;
}



