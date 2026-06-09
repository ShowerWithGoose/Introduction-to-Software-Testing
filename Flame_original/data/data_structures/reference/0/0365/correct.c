#include<stdio.h>
#include<string.h>
int main()
{
	char a[1000];
	char b[1000];
	gets(a);
	int l;
	l=strlen(a);
	int i;
	int m=0;
	int p;
	for(i=0;i<l-2;i++){
		if(a[i]>='0'&&a[i]<='9'&&a[i+1]=='-'&&a[i+2]>='0'&&a[i+2]<='9'&&a[i+2]>a[i]){
			if(i>1&&a[i-2]>='0'&&a[i-2]<='9'&&a[i-2]<a[i]&&a[i-1]=='-'){
				for(p=1;p<=a[i+2]-a[i];p++) {
				printf("%c",a[i]+p);
			
				}		i++;	
			}
			else{
				for(p=0;p<=a[i+2]-a[i];p++) {
					printf("%c",a[i]+p);
				
					}		i++;	
				}
			}
		else if(a[i]>='a'&&a[i]<='z'&&a[i+1]=='-'&&a[i+2]>='a'&&a[i+2]<='z'&&a[i+2]>a[i]){
			if(i>1&&a[i-2]>='a'&&a[i-2]<='z'&&a[i-2]<a[i]&&a[i-1]=='-'){
				for(p=1;p<=a[i+2]-a[i];p++) {
				printf("%c",a[i]+p);
			
				}		i++;	
			}
			else{
				for(p=0;p<=a[i+2]-a[i];p++) {
					printf("%c",a[i]+p);
				
					}		i++;	
				}
			}
		else if(a[i]>='A'&&a[i]<='Z'&&a[i+1]=='-'&&a[i+2]>='A'&&a[i+2]<='Z'&&a[i+2]>a[i]){
			if(i>1&&a[i-2]>='A'&&a[i-2]<='Z'&&a[i-2]<a[i]&&a[i-1]=='-'){
				for(p=1;p<=a[i+2]-a[i];p++) {
				printf("%c",a[i]+p);
			
				}		i++;	
			}
			else{
				for(p=0;p<=a[i+2]-a[i];p++) {
					printf("%c",a[i]+p);
				
					}		i++;	
				}
			}
		else {
				if(a[i-1]!='-') printf("%c",a[i]);
				else {
					if(a[i-2]>='A'&&a[i-2]<='Z'&&a[i-2]<a[i]&&a[i]>='A'&&a[i]<='Z') continue;
					else if(a[i-2]>='a'&&a[i-2]<='z'&&a[i-2]<a[i]&&a[i]>='a'&&a[i]<='z') continue;
					else if(a[i-2]>='0'&&a[i-2]<='9'&&a[i-2]<a[i]&&a[i]>='0'&&a[i]<='9') continue;
					else printf("%c",a[i]);
				}
				}
				
			}
			if(i!=l-1) printf("%c%c",a[l-2],a[l-1]);
		
	return 0;
					
	}
	


