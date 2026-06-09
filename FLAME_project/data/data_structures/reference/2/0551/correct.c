#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
char a[1000];
int b[1000],lena,lenb,lenc;
char c[1000];
int main()
{
	gets(a);lenc=0;
	int i,j,k,temp,flag;lena=strlen(a);
	for(i=0,j=0;i<lena;i++){
		if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/'){
			c[j++]=a[i]; 
			lenc++;
		}
	}
	temp=0;j=0;flag=0;
	for(i=0;i<lena;i++){
		if(isdigit(a[i])){
			temp = a[i] - '0' + temp * 10;
			flag = 1;
		}
		if(!isdigit(a[i]) && flag ){
			b[j++] = temp;
			flag = 0;
			temp = 0;
		}
	}
	lenb=lenc+1;
	for(i=0;i<lenc&&lenc>0;){
		if(c[i]=='*'){
			b[i]=b[i]*b[i+1];
			for(j=i;j<lenc-1;j++){
				c[j]=c[j+1];
			}
			lenc--;
			for(j=i+1;j<lenb-1;j++){
				b[j]=b[j+1];
			}
			lenb--;
		}if(c[i]=='/'){
			b[i]=b[i]/b[i+1];
			for(j=i;j<lenc-1;j++){
				c[j]=c[j+1];
			}
			lenc--;
			for(j=i+1;j<lenb-1;j++){
				b[j]=b[j+1];
			}
			lenb--;
		}
		if(c[i]!='*'&&c[i]!='/') i++;
	}
	for(i=0;i<lenc&&lenc>0;){ 
		if(c[i]=='+'){
			b[i]=b[i]+b[i+1];
			for(j=i;j<lenc-1;j++){
				c[j]=c[j+1];
			}
			lenc--;
			for(j=i+1;j<lenb-1;j++){
				b[j]=b[j+1];
			}
			lenb--;
		}if(c[i]=='-'){
			b[i]=b[i]-b[i+1];
			for(j=i;j<lenc-1;j++){
				c[j]=c[j+1];
			}
			lenc--;
			for(j=i+1;j<lenb-1;j++){
				b[j]=b[j+1];
			}
			lenb--;
		}
		if(c[i]!='+'&&c[i]!='-') i++;
	}printf("%d",b[0]);
}


