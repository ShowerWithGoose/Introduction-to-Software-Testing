#include<stdio.h>
#include<string.h>
int main()
{
	int i=0,j=0,e=0,e_=0,t=0,k;
	char a[100],b[100],c[100];
	gets(a);
	for(i=0;a[i]!='\0';i++){
		if(a[i]=='.')e=i;
		else
		b[j++]=a[i];b[j]='\0';
	}
	for(i=0;b[i]!='\0';i++){
		if(b[0]=='0')
		if(b[i]!='0'){e_=i;break;}
	}
	t=e-e_-1;
	if(b[0]=='0')
	{
		j=0;
		for(i=e_;b[i]!='\0';i++)c[j++]=b[i];c[j]='\0';k=strlen(c);
		if(k==1)printf("%se%d",c,t);
		else {
		      printf("%c.",c[0]);
		      for(i=1;c[i]!='\0';i++)printf("%c",c[i]);
		      printf("e%d",t);
		     }
	}
	else {
	      printf("%c.",b[0]);
	      for(i=1;b[i]!='\0';i++)printf("%c",b[i]);
		  printf("e%d",t);
	     }
}

