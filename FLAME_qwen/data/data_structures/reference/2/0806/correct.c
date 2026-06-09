#include<stdio.h>
#include<string.h>
int main(){
	char s[1024]={'0'},t[1024]={'0'},b[1024]={'0'};
	int i=0,j=0,n=0,m=0,k=0,l=0,a[1024]={0};
	gets(s);
	for(i=0;s[i]!='\0';i++){
		if(s[i]!=' '){
			t[j]=s[i];j++;
		}
	}
	n=strlen(t);
	for(i=0;i<n;i++){
		if(t[i]=='/'||t[i]=='-'||t[i]=='+'||t[i]=='*'){
			m=-1;break;
		}
		else m=1;
	}
	if(m==1){
		for(i=0;i<n-1;i++){
			k=k*10+t[i]-'0';
		}
		printf("%d",k); 
	}
	else if(m==-1){
		j=0;l=0;i=0;
		while(i<n-1){
			if(t[i]!='-'&&t[i]!='/'&&t[i]!='+'&&t[i]!='*'){
				for(k=i;t[k]!='-'&&t[k]!='/'&&t[k]!='+'&&t[k]!='*'&&t[k]!='=';k++){
					a[j]=a[j]*10+t[k]-'0';
				}
				j++;
				i=k;
			}
			else if(t[i]=='-'||t[i]=='/'||t[i]=='+'||t[i]=='*'){
				b[l]=t[i];
				l++;
				i++;
			}
		}
		i=0;
		while(i<l){
			if(b[i]=='*'||b[i]=='/'){
				for(n=i;b[n]=='*'||b[n]=='/';n++){
					if(b[n]=='*'){
						a[n+1]=a[n]*a[n+1];
					}
					else{
						a[n+1]=a[n]/a[n+1];
					}
				}
				a[i]=a[n];i=n;i++;
			}
			else{
				i++;
			}
		}
		k=a[0];
		for(i=0;i<j;i++){
			if(b[i]=='-'){
				k-=a[i+1];
			}
			else if(b[i]=='+'){
				k+=a[i+1];
			}
		} 
		printf("%d",k);
	}
	return 0;
}
	 

