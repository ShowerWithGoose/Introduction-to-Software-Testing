#include<stdio.h>
#include<string.h>
int main ()
{
	char a[105];
	int len,i,flag,j;
	gets(a);
	len=strlen(a);
	if(a[0]=='0'){
		flag=1;
		for(i=1,j=1;i<len;i++){
			if(a[i]=='0'&&flag==1) j++;
			else if(a[i]!=0&&a[i]!='.'&&flag==1){
				printf("%c",a[i]);
				if(i!=len-1) printf(".");
				flag=0;
			}
			else if(flag==0&&a[i]!='.'){
				
				printf("%c",a[i]);
				
				}
		
			}
		}
	
	
	
	else {
		printf("%c%c",a[0],'.');
		flag=3;
		for(i=1,j=0;i<len;i++){
			if(a[i]!='.'){
				printf("%c",a[i]);
				if(flag==3) j++;
			}
			if(a[i]=='.') flag=4;	
		}
		
	}
	
	printf("e");
	if(a[0]=='0') {
		printf("-");
		
	}
	printf("%d",j);
	return 0;
}
