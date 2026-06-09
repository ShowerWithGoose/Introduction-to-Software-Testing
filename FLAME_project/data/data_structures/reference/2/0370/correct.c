#include<stdio.h>
#include<math.h>
#include<string.h>
char a[1000000]={},b[1000000]={},c1[1000000]={},c2[1000000]={};
int num1[1000000]={},num2[1000000]={},s=0;
int main(){
	
	int i,j=-1,k=-1,t=0,m;
	gets(a);
	for(i=0;a[i];i++){
		if(a[i]!=' ')
		b[++j]=a[i];
	}
	j=0;
	for(i=0;b[i];i++){
		t=0;
		if(b[i]>='0'&&b[i]<='9'){
			while(b[i]>='0'&&b[i]<='9'){
				t++;
				i++;
			
		}
		for(m=1;m<=t;m++){
			num1[j]+=(b[i-m]-'0')*pow(10,m-1);
		}
		}
		if(!(b[i]>='0'&&b[i]<='9')){
			c1[j]=b[i];
		}
		j++;
	}
	for(j=0;c1[j];j++){
		if((c1[j]=='+')||(c1[j]=='-')){
			k++;
			num2[k]=num1[j];
			c2[k]=c1[j]; 
		}
		else if(c1[j]=='*'){
			num1[j+1]=num1[j]*num1[j+1];
		}
		else if(c1[j]=='/'){
			num1[j+1]=num1[j]/num1[j+1];
		}
		else if(c1[j]=='=') {
			k++;
			num2[k]=num1[j];
		}
	}
	s=num2[0];
	for(k=0;k<strlen(c2);k++){
		if(c2[k]=='+'){
			s+=num2[k+1];
		}
		else s-=num2[k+1];
	}
	printf("%d",s);
	return 0;
}

