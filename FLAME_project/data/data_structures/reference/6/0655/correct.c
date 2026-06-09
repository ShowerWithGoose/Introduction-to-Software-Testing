#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#define Arraynum(x) (sizeof(x)/sizeof(x[0]))
int a[100];
char b[100000];
int main() {
	int i,j,k,flag=0,min=99999999,max=-99999999;
	int n,m,len,sum,num,x,y;
	i=0;
	gets(b);
	len=strlen(b);
	for(k=0; k<len; k++) {
		if(b[k]==' ') continue;
		else if(b[k]=='-'&&b[k+1]=='1'&&(b[k+2]==' '||b[k+2]=='\0')) break;
		else if(b[k]=='1'&&flag==0) flag=1;
		else if(b[k]=='0') {
			if(i==0) printf("error ");
			else {
				printf("%d ",a[--i]);
			}
		} else if(flag==1) {
			if(i==100) printf("error ");
			else {
				j=0;
				if(b[k]=='-'){
					k++;
					j=1;
				}
				a[i]=b[k]-'0';
				while(b[k+1]!=' ') {
					a[i]=10*a[i]+b[++k]-'0';
				}
				if(j==1) a[i]=-a[i];
				i++;
			}
			flag=0;
		}
	}
	getchar();
	getchar();
	return 0;
}


