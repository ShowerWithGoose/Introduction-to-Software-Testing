#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
	char a[1000],b[1000];
	char c,d; 
	int len,i,j=0;
	gets (a);
	len = strlen(a);
	for(i=0;i<len;i++){ 
		if(a[i]!='-'){
			b[j++]=a[i];
		}
		else{
			c = a[i-1];
			d = a[i+1];
			if(((c>='0'&&c<='9')&&(d>='0'&&d<='9')&&(d-c>1))||((c>='A'&&c<='Z')&&(d>='A'&&d<='Z')&&(d-c>1))||((c>='a'&&c<='z')&&(d>='a'&&d<='z')&&(d-c>1))){
				while(c!=d){
					b[j++]=c+1;
					c+=1;
				}
			i++;
			} 
			else{
				b[j++]=a[i];
			}
		}
	}
	puts(b);
	return 0;
}




