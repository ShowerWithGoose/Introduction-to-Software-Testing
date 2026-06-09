#include<stdio.h>
#include<string.h>
int main()
{
	char s[1000],s1[1000]="",s2[1000]="";
	int d[1000]={0},d1[1000]={0},n,i,j=0,k=0;
	int m;
	gets(s);
	for(i=0;i<strlen(s);i++){
		if(s[i]>='0'&&s[i]<='9'){
			n=n*10+s[i]-'0';
		}
		if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='='){
			d[j++]=n;
			s1[k++]=s[i];
			n=0;
		}
	}
	j=0;
	for(i=0;i<strlen(s1);i++){
		if(s1[i]!='*'&&s1[i]!='/'){
			s2[j]=s1[i];
			d1[j]=d[i];
			j++;
		}
		else{
			n=d[i];
			while(s1[i]=='*'||s1[i]=='/'){
				if(s1[i]=='*') n=n*d[i+1];
				if(s1[i]=='/') n=n/d[i+1];
				i++;
			}
			s2[j]=s1[i];
			d1[j++]=n;
		}
	}
	i=0;n=d1[0];
	while(s2[i]!='='){
		if(s2[i]=='+') n=n+d1[i+1];
		if(s2[i]=='-') n=n-d1[i+1];
		i++;
	}
	printf("%d",n);
	return 0;
}



