#include<stdio.h>
#include<ctype.h>
#include<string.h>
char s[105],op[105],r[105];
int num[105];
int main(){
	int i,j,k,no,nn;
	gets(s);
	for (i=0,j=0;i<strlen(s);i++){
		if (s[i]!=' ') r[j++]=s[i];
	}
	r[j]='\0';
	for (i=0,j=0,k=0;r[i]!='=';i++){
		if (r[i]>='0'&&r[i]<='9') {
			num[j]=num[j]*10+r[i]-'0';
		}
		else {
			j++;
			op[k++]=r[i];
		}
	}
	no=k;nn=j+1;
	for (i=0;i<no;i++){
		if (op[i]=='*') {
			num[i+1]=num[i]*num[i+1];
			num[i]=-1; op[i]='.';
			continue;
		}
		if (op[i]=='/') {
			num[i+1]=num[i]/num[i+1];
			num[i]=-1; op[i]='.';
			continue;
		}
	}
	for (i=0,j=0;i<no;i++){
		if (op[i]!='.') op[j++]=op[i];
	}
	no=j;
	for (i=0,j=0;i<nn;i++){
		if (num[i]!=-1) num[j++]=num[i];
	}
	nn=j;
	for (i=0;i<no;i++){
		if (op[i]=='+') {
			num[i+1]=num[i]+num[i+1];
			continue;
		}
		if (op[i]=='-') {
			num[i+1]=num[i]-num[i+1];
			continue;
		}
	}
	printf("%d",num[nn-1]);
	
	
	
	return 0;
}

