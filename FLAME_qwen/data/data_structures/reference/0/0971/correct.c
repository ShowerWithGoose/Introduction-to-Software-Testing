#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	char a[100];
	int b,c,k;b=c=k=0;
	scanf("%s",a);
	for(b=0;b<strlen(a);b++){
		if(a[b+1]!='-'){
			printf("%c",a[b]);
		}
		else{
			if(a[b]-a[b+2]<0&&a[b]-a[b+2]>=-25){
				if((a[b]<58&&a[b+2]<58)||(a[b]>=97&&a[b+2]>=97)||(isupper(a[b])&&isupper(a[b+2]))){
					for(k=0;k<a[b+2]-a[b];k++){
						printf("%c",a[b]+k);
					}
					b++;
				}
				else{
					printf("%c",a[b]);
				}
			}
			else{
				printf("%c",a[b]);
			}
		}
	}
 	return 0;
}



