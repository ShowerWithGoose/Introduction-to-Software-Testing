#include <stdio.h>
#include <string.h>
#include <math.h>
char s[11111],ss[11111],f[1111];
int numb[11111];
int a[1111],b[11111];
int main() {
	int i=0,n=0,j=0,k=0,length;
	int m = 1, num = 0, w,l=0;

	gets(s);
	n=strlen(s);
	for(; i<n; i++) {
		if(s[i]!=' ')
			ss[j++]=s[i];
	}
	n=strlen(ss);
	for(i=0; i<n; i++) {
		if(ss[i]=='*'||ss[i]=='/'||ss[i]=='+'||ss[i]=='-'||ss[i]=='=')
			f[k++]=ss[i];
		if (ss[i] >= 48 && ss[i] <= 57) {
			for ( length = 1; length < 11; length++) {
				if (ss[i+length] >= 48 && ss[i+length] <= 57)
					continue;
				for (w = length; w > 0; w--) {
					num += (ss[i + w - 1] - '0') * m;
					m *= 10;
				}
				m=1;
				numb[l++]=num;
				num=0;
				i += length - 1;
				break;
				if (ss[i + length] < 48 || ss[i + length] > 57)
					break;
			}
		}
	}
	n=strlen(f);
	j=0,k=0;

	for(i=0; i<n+1; i++) {
		if(f[i]=='*') {
			numb[i+1]*=numb[i];
			numb[i]=0;
		}
		if(f[i]=='/') {
			numb[i+1]=numb[i]/numb[i+1];
			numb[i]=0;
		}
	}
	for(i=0; i<n+1; i++) {
		if(numb[i]!=0)
			a[j++]=numb[i];
	}
	//or(i=0;i<4;i++)printf("%d ",a[i]);
	j=1;
	int data=a[0];
	for(i=0; i<n+1; i++) {
		if(f[i]=='+')
			data+=a[j++];
		if(f[i]=='-')
			data=data-a[j++];
	}
	printf("%d",data);
	return 0;
}




