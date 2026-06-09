#include<stdio.h>
#include<string.h>
	char a[300];
int main()
{
	gets(a);
	char j;
	int i;
	for(i=0;i<strlen(a);i++){
		if(a[i]=='-'){
			if(a[i-1]>='a'&&a[i-1]<='z'&&a[i+1]>='a'&&a[i+1]<='z'&&a[i+1]>a[i-1]){
				for(j=a[i-1]+1;j<a[i+1];j++)
					printf("%c",j);
			}
			else if(a[i-1]>='A'&&a[i-1]<='Z'&&a[i+1]>='A'&&a[i+1]<='Z'&&a[i+1]>a[i-1]){
				for(j=a[i-1]+1;j<a[i+1];j++)
					printf("%c",j);
			}
			else if(a[i-1]>='0'&&a[i-1]<='9'&&a[i+1]>='0'&&a[i+1]<='9'&&a[i+1]>a[i-1]){
				for(j=a[i-1]+1;j<a[i+1];j++)
					printf("%c",j);
			}
			else printf("%c",a[i]);
		}
		else printf("%c",a[i]);
		
	}
	return 0; 
} 



