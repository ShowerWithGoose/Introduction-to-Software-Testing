#include<stdio.h>
#include<string.h>
char s[100],s[100];
int a[100],a[100];
int main() {
	int i,j,len,result=0,k;
	gets(s);
	len=strlen(s);
	for(i=0; i<len; i++) {
		if(s[i]==' ') {
			for(j=i; j<len-1; j++) {
				s[j]=s[j+1];
			}
			len--;
		}
	}
	for(i=0,j=0; i<len; i++) {
		if(s[i]>='0'&&s[i]<='9') {
			a[j]=a[j]*10+s[i]-'0';
		} else {
			s[j]=s[i];
			j++;
		}
	}
	for(i=0; i<len; i++) {
		if(s[i]=='+'||s[i]=='-') {
			k++;
		}
	}
	a[0]=a[0];
	for(i=0,j=1; i<len; i++) {
		if(s[i]=='+'||s[i]=='-') {
			a[j]=a[i+1];
			j++;
		}
	}
	for(i=0,j=0; i<len; i++) {
		if(s[i]=='+'||s[i]=='-') {
			j++;
		} else {
			if(s[i]=='*') {
				a[j]*=a[i+1];
			} else if(s[i]=='/') {
				a[j]/=a[i+1];
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




