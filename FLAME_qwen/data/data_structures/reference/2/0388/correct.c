/*#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
char str[1000];
char s[1000];
int a[1000],b[1000];
int c[1000];
int main()
{
	gets(str);
	int len=strlen(str);
	int j=0,cunt=0;
	for(int i=0;i<len;i++){
		if(str[i]!=' ') s[j++]=str[i];
		else if(str[i]=='+' || str[i]=='-'|| str[i]=='*' || str[i]=='/')
		cunt++;	
	}	
	int kj=0,kkk=0,num=0;
	int sum=0,flag=-10;
	int k=0;
	for(int i=0;i<j;i++){
		if(s[i]!='+' &&s[i]!='-' && s[i]!='*' && s[i]!='/' && s[i]!='=' )
			a[k]=a[k]*10+s[i]-'0';
		else {
			k++;
			c[k]=s[i];
		}
	}
	for(int i=0;i<=j;i++){
		if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' ) num++;
		if(num==1) {
			if(s[i]=='*' || s[i]=='/') flag=0;
			else if(s[i]=='+' || s[i]=='-') flag=1;
			
		}
	}
	
	
	int jk=0;
	
if(flag==0){
	for(int i=0;i<j;i++){
		if(s[i]=='-') {
			a[jk+2]=-a[jk+2];
			jk++;
		}
	}
	
	
if(num==0){
	sum=a[0];
}
else{	
	for(int i=0;i<=j;i++){
		if(s[i]=='+' || s[i]=='-'){
			b[++kj]=a[++kkk];
			
		}
		else if(s[i]=='*'&& b[kj]!=0){
			b[kj]*=a[++kkk];
		}
		else if(s[i]=='*'&& b[kj]==0)
			b[kj]=a[kkk++]*a[kkk];
		else if(s[i]=='/'&& b[kj]!=0){
			b[kj]/=a[++kkk];
		}
		else if(s[i]=='/'&& b[kj]==0)
			b[kj]=a[kkk++]/a[kkk];
		
	}

	}
}



else{
	kj=-1,kkk=-1;
		for(int i=0;i<j;i++){
		if(s[i]=='-') {
			a[jk+1]=-a[jk+1];
			jk++;
		}
	}
	
	
if(num==0){
	sum=a[0];
}
else{	
	for(int i=0;i<=j;i++){
		if(s[i]=='+' || s[i]=='-'){
			b[++kj]=a[++kkk];
			
		}
		else if(s[i]=='*'&& b[kj]!=0){
			b[kj]*=a[++kkk];
		}
		else if(s[i]=='*'&& b[kj]==0)
			b[kj]=a[kkk++]*a[kkk];
		else if(s[i]=='/'&& b[kj]!=0){
			b[kj]/=a[++kkk];
		}
		else if(s[i]=='/'&& b[kj]==0)
			b[kj]=a[kkk++]/a[kkk];
		
	}

	}
}
	for(int i=0;i<=kj;i++){
		sum+=b[i];	
	}
	printf("%d",sum);

	return 0;	
}
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
char str[1000];
char s[1000];
int a[1000],b[1000];
int c[1000];
int main()
{
	gets(str);
	int len=strlen(str);
	int j=0,cunt=0;
	for(int i=0;i<len;i++){
		if(str[i]!=' ') s[j++]=str[i];
		else if(str[i]=='+' || str[i]=='-'|| str[i]=='*' || str[i]=='/')
		cunt++;	
	}	

	int k=0;
	for(int i=0;i<j;i++){
		if(s[i]!='+' &&s[i]!='-' && s[i]!='*' && s[i]!='/' && s[i]!='=' )
			a[k]=a[k]*10+s[i]-'0';
		else {
			k++;
			c[k]=s[i];
		}
	}
	int kk=0;
	for(int i=0;i<j;i++){
		if(s[i]<'0' || s[i]>'9')	kk++;
		if(s[i]=='-')	a[kk]=-a[kk];
	}//已经得出所有的负数	
	
	int kkk=0;
	
	for(int i=0;i<j;i++){
		if(s[i]=='*'){
			a[kkk+1]=a[kkk]*a[kkk+1];
			a[kkk]=0;}
		
		else if(s[i]=='/'){
			a[kkk+1]=a[kkk]/a[kkk+1];
			a[kkk]=0;}
		
		if(s[i]<'0' || s[i]>'9') kkk++;
	}
	int sum=0;
	for(int i=0;i<=kk;i++)
	sum+=a[i];
	printf("%d",sum);
	
	
	


	return 0;	
}




