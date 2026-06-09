#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
char a[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char b[]="abcdefghijklmnopqrstuvwxyz";
char c[]="0123456789";
char s[100];
int main()
{
	int j=0;
	scanf("%s",s);
	int l=strlen(s);
	for(int f=0;f<l;f++){
		if(s[f]=='-'){
			if((strchr(a,s[f-1]))!=NULL){
				if((strchr(a,s[f+1]))!=NULL&&s[f+1]>=s[f-1]){
					int a1=strchr(a,s[f-1])-a;
					while(a[a1]<s[f+1]-1){
						a1++;
						printf("%c",a[a1]);
					}
				}
				else printf("-");
			}
			else if((strchr(b,s[f-1]))!=NULL){
				if((strchr(b,s[f+1]))!=NULL&&s[f+1]>=s[f-1]){
					int b1=strchr(b,s[f-1])-b;
					while(b[b1]<s[f+1]-1){
						b1++;
						printf("%c",b[b1]);
					}
				}
				else printf("-");
			}
			else if((strchr(c,s[f-1]))!=NULL){
				if((strchr(c,s[f+1]))!=NULL&&s[f+1]>=s[f-1]){
					int c1=strchr(c,s[f-1])-c;
					while(c[c1]<s[f+1]-1){
						c1++;
						printf("%c",c[c1]);
					}
				}
				else printf("-");
			}
		} 
		else printf("%c",s[f]);
	}
	return 0;
}




