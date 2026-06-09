#include<stdio.h>
#include<string.h>
void f(char s[]){
	int i,j;
	for(i=0;s[i]!='\0';){
		if(s[i]==' '){
			for(j=i;s[j+1]!='\0';j++)
				s[j]=s[j+1];
			s[j]='\0';
		}
		if(s[i]!=' ') i++;
	}
}
int z(char s[]){
	int i,j,k;
	int a=0;
	int l=strlen(s);
	int t[10000]={};
	for(i=0;i<l;i++){
		t[i]=s[l-i-1]-'0';
		for(j=i;j>0;j--){
			t[i]*=10;
		}
		a+=t[i];
	}
	return a;
}
int main(){
	int i,j,k;
	int cont=0;
	int cont2=0;
	char s[10000];
	char t[10000];
	int a[10000]={};
	gets(s);
	f(s);
	for(i=0;i<=strlen(s);i++){
		if(s[i]>='0'&&s[i]<='9'){
			t[cont++]=s[i];
			s[i]=' ';
		}
		else{
			t[cont]='\0';
			cont=0;
			a[cont2++]=z(t);
		}
		if(s[i]=='=')
			s[i]=' ';
	}
	f(s);
	for(i=0;s[i]!='\0';i++){
		if(s[i]=='*'){
			a[i]=a[i]*a[i+1];
			for(j=i+1;j<cont2-1;j++)
				a[j]=a[j+1];
			s[i]=' '; f(s);
			i--;
		}
		if(s[i]=='/'){
			a[i]=a[i]/a[i+1];
			for(j=i+1;j<cont2-1;j++)
				a[j]=a[j+1];
			s[i]=' '; f(s);
			i--;
		}
	}
	for(i=0;s[i]!='\0';i++){
		if(s[i]=='+')
			a[i+1]+=a[i];
		if(s[i]=='-')
			a[i+1]=a[i]-a[i+1];
	}		
	printf("%d",a[i]);
	return 0;
}

