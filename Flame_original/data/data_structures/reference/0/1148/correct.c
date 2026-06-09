#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
char a[1005],b[1005];
int main(){
	int l,i,j;
	gets(a);
	l=strlen(a);
	for(i=0,j=0;i<l;i++){
		if((a[i]=='-')&&((('a'<=a[i-1])&&(a[i-1]<a[i+1])&&(a[i+1]<='z'))||(('A'<=a[i-1])&&(a[i-1]<a[i+1])&&(a[i+1]<='Z'))||(('0'<=a[i-1])&&(a[i-1]<a[i+1])&&(a[i+1]<='9')))){
			while(b[j-1]<a[i+1]-1){
				b[j++]=(a[i-1]+1);
				a[i-1]+=1;
			}
		}
		else b[j++]=a[i];	
	}
	puts(b);
	return 0;
}



