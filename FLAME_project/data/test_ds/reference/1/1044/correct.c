#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char a[100000];
int main()
{
    scanf("%s",a);
    int len=strlen(a);
    for(int i=0;i<len-1;i++){
    	if(a[i]=='-'&&a[i+1]>a[i-1]){
    		if(a[i-1]>='a'&&a[i-1]<='z'&&a[i+1]>='a'&&a[i+1]<='z'){
    			for(int j=1;j<a[i+1]-a[i-1];j++){
    				printf("%c",a[i-1]+j);
				}
			}
		    else if(a[i-1]>='0'&&a[i-1]<='9'&&a[i+1]>='0'&&a[i+1]<='9'){
    			for(int j=1;j<a[i+1]-a[i-1];j++){
    				printf("%c",a[i-1]+j);
				}
			}
			else if(a[i-1]>='A'&&a[i-1]<='Z'&&a[i+1]>='A'&&a[i+1]<='Z'){
    			for(int j=1;j<a[i+1]-a[i-1];j++){
    				printf("%c",a[i-1]+j);
				}
			}
			else printf("%c",a[i]);
		}
		else printf("%c",a[i]); 
	}
	printf("%c",a[len-1]);
	return 0;
}



