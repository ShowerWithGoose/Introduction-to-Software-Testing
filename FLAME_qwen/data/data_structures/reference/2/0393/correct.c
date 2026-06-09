#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h> 
void sq(char s[],char c){
	int i,j;
	for(i=0,j=0;s[i]!='\0';i++){
		if(s[i]!=c)
			s[j++]=s[i];
	}
	s[j]='\0';
}
int main(){
	char a[10000]={0};
	gets(a); 
	sq(a,' ');
	
	int len=strlen(a)-1,i=0,j=0,count1=0,count=0,top=0; 
	char sym[5000]={0};
	long long num[5000]={0};
	long long sum=0;

	for(i=0;i<len;i++){
		long long x=0;
		if(a[i]>='0'&&a[i]<='9'){
			while(a[i]>='0'&&a[i]<='9'){
				x=x*10+a[i]-'0';
				i++;
	
			}
			num[count]=x;
			count++;
			i--;
		}else{
			sym[count1]=a[i];
			count1++;
		}
	}

	for(i=0;i<count1;i++){
		if(sym[i]=='*'){
			num[top]=num[top]*num[top+1];
			for(j=top+1;j<count;j++){
				num[j]=num[j+1];
			}
		}else if(sym[i]=='/'){
			num[top]=num[top]/num[top+1];
			for(j=top+1;j<count;j++){
				num[j]=num[j+1];
			}
	
		}else{
			top++;
		}
	}


	for(i=0;i<count1;i++){

		if(sym[i]=='+'){
			num[0]=num[0]+num[1];
			for(j=1;j<count;j++){
				num[j]=num[j+1];
			}

		}else if(sym[i]=='-'){
			num[0]=num[0]-num[1];
			for(j=1;j<count;j++){
				num[j]=num[j+1];
			}
		}
	}
	
	printf("%lld",num[0]);
	return 0; 
} 

