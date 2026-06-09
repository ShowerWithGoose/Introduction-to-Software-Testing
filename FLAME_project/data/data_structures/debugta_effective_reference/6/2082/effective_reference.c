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
	int j,n1,k,flag=0,min=99999999,max=-99999999;
	int n,m,len,sum,num,x,y;
	j=0;
	gets(b);
	len=strlen(b);
	for(k=0; k<len; k++) {
		if(b[k]==' ') continue;
		else if(b[k]=='-'&&b[k+1]=='1'&&(b[k+2]==' '||b[k+2]=='\0')) break;
		else if(b[k]=='1'&&flag==0) flag=1;
		else if(b[k]=='0') {
			if(j==0) printf("error ");
			else {
				printf("%d ",a[--j]);
			}
		} else if(flag==1) {
			if(j==100) printf("error ");
			else {
				n1=0;
				if(b[k]=='-'){
					k++;
					n1=1;
				}
				a[j]=b[k]-'0';
				while(b[k+1]!=' ') {
					a[j]=10*a[j]+b[++k]-'0';
				}
				if(n1==1) a[j]=-a[j];
				j++;
			}
			flag=0;
		}
	}
	getchar();
	getchar();
	return 0;
}


