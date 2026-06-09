#include<stdio.h>
#include<string.h>
char s[100];
int b[100],c[100],a[100];
int main(){
	gets(s);
	int lena=0;
	for(int i=0;i<strlen(s);i++){/*Delete the blank space*/ 
		if(s[i]==' ') continue;
		else{
			if(s[i]>='0'&&s[i]<='9') a[lena++]=s[i]-'0';
			else a[lena++]=s[i];
		}
	}
//	for(int i=0;i<lena;i++) printf("%d\n%d",a[i],lena);
	int j=0;
	for(int i=0;i<lena;i++){
		if(a[i]>=0&&a[i]<=9){
			int k=i,count=0;
			while(a[k]>=0&&a[k]<=9){
				count++;k++;
			}
			for(int p=1;p<=count;p++){
				int m=a[i+p-1];
				for(int l=0;l<count-p;l++) m*=10;
				b[j]+=m;
			}
			i+=(count-1);j++;
		}
		else b[j++]=a[i];
	}
//	printf("\n%d\n",j);
//	for(int i=0;i<j;i++) printf("%d",b[i]);
	for(int i=0;i<j;i++){
		if(b[i]=='*'){
			b[i+1]=b[i-1]*b[i+1];
			b[i-1]=b[i]=' ';
		}
		else if(b[i]=='/'){
			b[i+1]=b[i-1]/b[i+1];
			b[i-1]=b[i]=' ';
		}
	} 
	int l=0;
	/*After the culculation,the extra parts are being deleted to blank space
	so we need to delete the blank space again*/ 
	for(int i=0;i<j;i++){
		if(b[i]==' ') continue;
		else c[l++]=b[i];
	}
	/*The rest part is about simple addition and subtraction*/
	for(int i=0;i<l;i++){
		if(c[i]=='+'){
			c[i+1]=c[i-1]+c[i+1];
		}
		else if(c[i]=='-'){
			c[i+1]=c[i-1]-c[i+1];
		}
		else if(c[i]=='=') printf("%d",c[l-2]);
	} 
}

