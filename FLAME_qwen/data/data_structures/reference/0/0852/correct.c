#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

#define MAX(a,b) ((a)?(b)? (a): (b))
#define MIN(a,b) ((a)?(b)? (a): (b))
#define pi acos(-1)
#define eps 1e-8
#define ULL unsigned long long
#define LL long long

	char a[6666],b[6666];
int main(){
	gets(a);
	int l=strlen(a);
	int i,j=0,k;
	for(i=0;i<l;i++){
		if(a[i]!='-'){
			b[j]=a[i];
			j++;
		}
		else if(a[i]=='-'){
			if((a[i-1]<='9'&&a[i-1]>='0')&&(a[i+1]<='9'&&a[i+1]>='0')&&(a[i-1]<a[i+1])) {
				k=1;
				for(;b[j-1]!=a[i+1]-1;j++,k++){
					b[j]=a[i-1]+k;
				}
			}
			else if((a[i-1]<='z'&&a[i-1]>='a')&&(a[i+1]<='z'&&a[i+1]>='a')&&(a[i-1]<a[i+1])) {
				k=1;
				for(;b[j-1]!=a[i+1]-1;j++,k++){
					b[j]=a[i-1]+k;
				}
			}	
			else if((a[i-1]<='Z'&&a[i-1]>='A')&&(a[i+1]<='Z'&&a[i+1]>='A')&&(a[i-1]<a[i+1])) {
				k=1;
				for(;b[j-1]!=a[i+1]-1;j++,k++){
					b[j]=a[i-1]+k;
				}								
			}
			else {
				b[j]=a[i]; 
				j++;
		}
	}
}
	printf("%s",b);
}
	

