#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define MAXSIZE 10000

int main() {
	char s[MAXSIZE];
	gets(s);
	int i,j,len=strlen(s),sum=0,a=0,b=0,flag=1,temp;//将字符转换为整数进行运算
	for(i=0,j=0; i<len; i++) { //去空格
		if(s[i]!=' ')
			s[j++]=s[i];
	}
	s[j]='\0';
	len=strlen(s);
	for(i=0; i<len; i++) {
		if(s[i]<='9'&&s[i]>='0') {
			a*=10;
			a+=s[i]-'0';
		} else {
			if(s[i]=='+'||s[i]=='-') {
				if(flag==1)
					sum+=a;
				else
					sum-=a;
				a=0;
				flag=(s[i]=='+')?1:0;
			} else if(s[i]=='*'||s[i]=='/') {
				b=0;
				temp=i;
				for(j=i+1; s[j]>='0'&&s[j]<='9'; j++,i++) {
					b*=10;
					b+=s[j]-'0';
				}
				if(s[temp]=='*')
					a*=b;
				else
					a/=b;
			} else if(s[i]=='=') {
				if(flag==1)
					sum+=a;
				else
					sum-=a;
			}
		}
	}
	printf("%d",sum);
	return 0;
}



