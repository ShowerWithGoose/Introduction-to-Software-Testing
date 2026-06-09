#include<stdio.h>
#include<string.h>
char ch[100],s[100];
int num[100],a[100];
int main() {
	int i,j,len,result=0,k;
	gets(ch);
	len=strlen(ch);
	for(i=0; i<len; i++) {
		if(ch[i]==' ') {
			for(j=i; j<len-1; j++) {
				ch[j]=ch[j+1];
			}
			len--;
		}
	}
	for(i=0,j=0; i<len; i++) {
		if(ch[i]>='0'&&ch[i]<='9') {
			num[j]=num[j]*10+ch[i]-'0';
		} else {
			s[j]=ch[i];
			j++;
		}
	}
	for(i=0; i<len; i++) {
		if(ch[i]=='+'||ch[i]=='-') {
			k++;
		}
	}
	a[0]=num[0];
	for(i=0,j=1; i<len; i++) {
		if(s[i]=='+'||s[i]=='-') {
			a[j]=num[i+1];
			j++;
		}
	}
	for(i=0,j=0; i<len; i++) {
		if(s[i]=='+'||s[i]=='-') {
			j++;
		} else {
			if(s[i]=='*') {
				a[j]*=num[i+1];
			} else if(s[i]=='/') {
				a[j]/=num[i+1];
			}
		}
	}
	result=a[0];
	for(i=0,j=1; i<len; i++) {
		if(s[i]=='+') {
			result+=a[j];
			j++;
		} else if(s[i]=='-') {
			result-=a[j];
			j++;
		}
	}
	printf("%d",result);
}




