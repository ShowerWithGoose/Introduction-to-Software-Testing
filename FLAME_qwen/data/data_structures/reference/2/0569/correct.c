#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
char s[10000],op[10000];
int num[10000];
int number(int i){
	int n=0;	
	for(;isdigit(s[i]);i++)
		n=n*10+s[i]-'0';
	return n;
}

int main()
{
	gets(s);
	int i,j,n,answer=0,sign=1;
	for(i=j=0;i<strlen(s);i++){
		while(isspace(s[i]))
			i++;
		if(isdigit(s[i]))
			num[j]=number(i);
		while(isdigit(s[i])||isspace(s[i]))
			i++;
		op[j++]=s[i];
	}
	n=num[0];
	for(i=0;i<strlen(op);i++){
		if(op[i]=='*')
			n*=num[i+1];
		else if(op[i]=='/')
			n/=num[i+1];
		else{
			answer+=sign*n;
			n=num[i+1];		
			if(op[i]=='+')
		 		sign=1;
			else sign=-1;
		}
	}
	printf("%d",answer);
	return 0;
}




