#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
int main(int argc, char *argv[]) {
	char c[1024],si[1024]="";
	int i=0,j=0,k1=0,k2=0,re=0,p=0,p0=0,p1=0,nu[1024]={0};
	
	gets(c);
	for(i=0;c[i]!='=';i++){
		if(c[i]=='+'||c[i]=='-'||c[i]=='*'||c[i]=='/'){
			si[k2]=c[i];
			k2++;
		}
		else if('0'<=c[i]&&c[i]<='9'){
			for(;'0'<=c[i]&&c[i]<='9';i++){
				nu[k1]=nu[k1]*10+c[i]-'0';	
			}
			k1++,i--;
		}
	}
	
	for(j=0;si[j]!='\0';j++){
		if(si[j]=='*'||si[j]=='/'){
			p0=j;
			p=nu[j];
			for(;si[j]=='*'||si[j]=='/';j++){
				if(si[j]=='*')p*=nu[j+1];
				else if(si[j]=='/')p/=nu[j+1];
				nu[j+1]=0;
			}
			nu[p0]=p; 			
		}
	}
	
	re=nu[0];
	for(j=0;j<=k1-1;j++){
			re+=(si[j]=='-')?nu[j+1]*(-1):nu[j+1];
	}
	
	printf("%d",re);
	
	
	
	
	
	return 0;
}

