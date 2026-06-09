#include<stdio.h>
#include<string.h>
char a[1000];
int main()
{
	gets(a);
	int i,j,d;
	for(i=0;i<strlen(a);i++){
		if(a[i]!='-'&&a[i+1]!='-'){
			printf("%c",a[i]);
		}
		else if(a[i]!='-'&&a[i+1]=='-'){
					if(a[i]>='a'&&a[i]<='z'){
						if(a[i+2]>a[i]&&a[i+2]<='z'){
							d=a[i+2]-a[i];
							for(j=0;j<d;j++){
							printf("%c",a[i]+j);
							}
						
			       		 }else printf("%c-",a[i]);
					}
					else if(a[i]>='A'&&a[i]<='Z'){
						if(a[i+2]>a[i]&&a[i+2]<='Z'){
							d=a[i+2]-a[i];
							for(j=0;j<d;j++){
								printf("%c",a[i]+j);
							}
						}else printf("%c-",a[i]);
					}
					
					else if(a[i]>='0'&&a[i]<='9'){
						if(a[i+2]>a[i]&&a[i+2]<='9'){
			 				d=a[i+2]-a[i];
							for(j=0;j<d;j++){
								printf("%c",a[i]+j);
							}
						}else printf("%c-",a[i]);
					}
		}

	}
	return 0;
}

