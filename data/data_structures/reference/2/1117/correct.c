#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
	char s1[100];
	char s2[100];
	char f[100];
	gets(s1);
	int i;
	int j=0;
	int k=0;
	for(i=0;s1[i]!='\0';i++){
		if(s1[i]!=' '){s2[j]=s1[i]; j+=1;}
	}
	int num[100]={0};
	for(i=0;i<strlen(s2);i++){
		if(s2[i]<'0'||s2[i]>'9'){
		    for(j=1;s2[i-j]>='0'&&s2[i-j]<='9'&&j>=0;j++){
		    	num[k]+=(s2[i-j]-'0')*pow(10,j-1);
			}
		    f[k]=s2[i];
	    	k+=1;
		}
	}
	for(i=0;i<strlen(f);i++){
		if(f[i]=='*'){
			num[i]=num[i]*num[i+1];
			for(j=i;j<strlen(f);j++){
				f[j]=f[j+1];
			}
			for(j=i+1;j<strlen(f);j++){
				num[j]=num[j+1];
			}i--;
		}
		if(f[i]=='/'){
			num[i]=num[i]/num[i+1];
			for(j=i;j<strlen(f);j++){
				f[j]=f[j+1];
			}
			for(j=i+1;j<strlen(f);j++){
				num[j]=num[j+1];
			}i--;
		}
	}
	for(i=0;i<strlen(f);i++){
		if(f[i]=='+'){
			num[i]=num[i]+num[i+1];
			for(j=i;j<strlen(f);j++){
				f[j]=f[j+1];
			}
			for(j=i+1;j<strlen(f);j++){
				num[j]=num[j+1];
			}i--;
		}
		if(f[i]=='-'){
			num[i]=num[i]-num[i+1];
			for(j=i;j<strlen(f);j++){
				f[j]=f[j+1];
			}
			for(j=i+1;j<strlen(f);j++){
				num[j]=num[j+1];
			}i--;
		}
	} printf("%d",num[0]);
	return 0;
}

