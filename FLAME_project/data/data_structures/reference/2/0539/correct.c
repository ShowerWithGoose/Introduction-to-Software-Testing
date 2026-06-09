#include<stdio.h>
#include<string.h>
#include<math.h>
int main() {
	int count[1000]= {};
	char a[1000]= {},str[1000]= {};
	gets(a);
	int i=0,j=0,k=0,m=0;
	while(a[i]!=0) {
		if('0'<=a[i]&&a[i]<='9') {
			count[j]=a[i]-'0';
			m=i+1;
			while('0'<=a[m]&&a[m]<='9') {
				count[j]*=10;
				count[j]=count[j]+a[m]-'0';
				m++;
			}
			i=m-1;
			j++;
		}
		if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/') {
			str[k]=a[i];
			k++;
		}
		i++;
	}
	if(str[0]==0) {
		printf("%d",count[0]);
	} else {
		i=0;
		while(str[i]!=0) {
			if(str[i]=='*'||str[i]=='/') {
				if(str[i]=='*') {
					count[i+1]=count[i]*count[i+1];
					count[i]=0;
				} else {
					count[i+1]=count[i]/count[i+1];
					count[i]=0;
				}
			}
			i++;
		}
		i=0;
		while(1) {
			if(count[i]!=0) {
				break;
			}
			i++;
		}
			j=i;
		while(1) {
			if(str[i]==0) {
				break;
			}
			j=i+1;
			while(1) {
				if(count[j]!=0) {
					break;
				}
				j++;
			}
			if(str[i]=='+') {
				count[j]+=count[i];
			}
			if(str[i]=='-') {
				count[j]=count[i]-count[j];
			}
			if(str[j]==0) {
				break;
			}
			i=j;
		}
		printf("%d",count[j]);
	}
	return 0;
}



