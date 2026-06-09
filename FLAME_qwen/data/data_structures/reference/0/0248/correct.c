#include<stdio.h>
#include<string.h>
int main(){
	char a1[100000],a2[100000];
	int i=1,j=1,m,n;
	gets(a1);
	a2[0]=a1[0];
	for(i=1;i<strlen(a1);i++){
		if (a1[i]=='-'&&a1[i-1]<a1[i+1]&&a1[i-1]>='A'&&a1[i-1]<='Z'&&a1[i+1]>='A'&&a1[i+1]<='Z')
		{
		for (m=a1[i-1]+1;m<a1[i+1];m++)
		{
		a2[j++]=m;
		}
		}
		else if (a1[i]=='-'&&a1[i-1]<a1[i+1]&&a1[i-1]>='a'&&a1[i-1]<='z'&&a1[i+1]>='a'&&a1[i+1]<='z')
		{
		for (n=a1[i-1]+1;n<a1[i+1];n++)
		{
		a2[j++]=n;
		}
		}
		else if (a1[i]=='-'&&a1[i-1]<a1[i+1]&&a1[i-1]>='0'&&a1[i-1]<='9'&&a1[i+1]>='0'&&a1[i+1]<='9')
		{
		for (n=a1[i-1]+1;n<a1[i+1];n++)
		{
		a2[j++]=n;
		}
		}
		else
	    a2[j++]=a1[i];
		}
		a2[j]='\0';
		printf("%s",a2);
		return 0;
}



