#include<stdio.h> 
#include<string.h>
int main(){
	char c[BUFSIZ],d[BUFSIZ],e[BUFSIZ];
	int i,p,q;
	gets(c);

	while(strcmp(c,d)){
		for(i=0,p=0;c[i]!='\0';i++,p++)
		{
		 if(c[i]>='0'&&c[i]<='9'&&c[i+2]>='0'&&c[i+2]<='9'&&c[i]<c[i+2]&&c[i+1]=='-')
		{
		for(q=0;c[i]+q<c[i+2];p++,q++)
			d[p]=c[i]+q;
			p--,i++; 
		}
		else if(c[i]>='a'&&c[i]<='z'&&c[i+2]>='a'&&c[i+2]<='z'&&c[i]<c[i+2]&&c[i+1]=='-')
		{
		for(q=0;c[i]+q<c[i+2];p++,q++)
			d[p]=c[i]+q;
			p--,i++;
		}
		else if(c[i]>='A'&&c[i]<='Z'&&c[i+2]>='A'&&c[i+2]<='Z'&&c[i]<c[i+2]&&c[i+1]=='-')
		{
		for(q=0;c[i]+q<c[i+2];p++,q++)
			d[p]=c[i]+q;
			p--,i++;
		}
		else
		d[p]=c[i];
		}
		strcpy(e,d);
		strcpy(d,c);
		strcpy(c,e);
	}
	puts(c);
	return 0;
}

