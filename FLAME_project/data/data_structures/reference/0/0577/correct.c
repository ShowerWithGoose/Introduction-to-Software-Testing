#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	char a[100],b;
	int i;
	gets(a);
	for(i=0;i<=strlen(a);i++){
		if((a[i+1]=='-')&&(a[i]<=a[i+2])&&((a[i]>='0'&&a[i+2]<='9')||(a[i]>='a'&&a[i+2]<='z')||(a[i]>='A'&&a[i+2]<='Z'))){
			for(b=a[i];b<a[i+2];b++){
				printf("%c",b);
			}
			i++;
			}
		else{
			printf("%c",a[i]);
		}
	}
 	return 0;
}




