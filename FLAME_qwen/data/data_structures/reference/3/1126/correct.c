#include<stdio.h>
#include<string.h>
int main(){
	char a[1000];
	int i=0,m=0,h=1,l=0,k=0;
	while(scanf("%c",&a[i])!=EOF)
	i++;
	if(a[0]=='0'&&a[1]=='.'){
	for(m=0;m<i;m++){
		if(k!=0&&a[m]!='\n')
		printf("%c",a[m]);
		if(a[m]!='.'&&l!=0&&k==0)
		h=h+1;
		if(a[m]=='.')l=1;
		if(a[m]!='0'&&k==0&&a[m]!='.'&&a[m+1]!='\n')
		{
		k=4;
		printf("%c.",a[m]);
	}
		if(a[m]!='0'&&k==0&&a[m]!='.'&&a[m+1]=='\n')
		{
		k=4;
		printf("%c",a[m]);
	}
	
	} 
	printf("e-%d",h-1);
}
    else if(a[0]=='0'&&i==1)
    printf("0");
    else if(a[0]!='0'){
    	for(m=0;m<i;m++){
		if(a[m]!='.'&&l==0&&a[m]!='\n')
		{
		h=h+1;
	}
		if(a[m]=='.')l=1;
	
	} 
	for(m=0;m<i;m++){
		if(a[m]=='\n')
		break;
		if(a[m]!='.')
		{
		if(m==0)
		printf("%c.",a[m]);
		else printf("%c",a[m]);
	}
	}
	printf("e%d",h-2);
	}
	} 



