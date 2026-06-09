#include<stdio.h>
void squeez(char s[])
{
 int i,j;
 for(i=j=0;s[i]!='\0';i++)
  if(s[i]!=32)
   s[j++]=s[i];
 s[j]='\0';
}
int main(){
	char s[100],c[100];
	int i,j=0,k=0,a[100],n=0,m=0,b;
	gets(s);
	squeez(s);
	for(i=0;s[i]!='\0';i++){
	    while(s[i]<='9'&&s[i]>='0'){
			n=n*10+s[i]-'0';
			i+=1;
		}
		a[k]=n;
		n=0;
		k+=1;
		if(s[i]=='=')break;
		if(s[i]<48){
			c[j]=s[i];
			j+=1;
		}
	}
	c[j]='\0';
	m=a[0];
	i=0;
	for(i=0;c[i]!='\0';i++){
		if(c[i]=='-'){
		b=a[i+1];
			while(c[i+1]!=45&&c[i+1]!=43&&c[i+1]!='\0'){
				if(c[i+1]==42){
					b=b*a[i+2];
					i+=1;
				}
				else{
					b=b/a[i+2];
					i+=1;
				}
			}
			
			m=m-b;
		}
		else if(c[i]=='+'){b=a[i+1];
			while(c[i+1]!=45&&c[i+1]!=43&&c[i+1]!='\0'){
				
				if(c[i+1]==42){
					b=b*a[i+2];
					i+=1;
				}
				else{
					b=b/a[i+2];
					i+=1;
				}
			}
			m=m+b;
		}
		else {
			b=a[i];
			while(c[i]!='-'&&c[i]!='+'&&c[i]!='\0'){
				if(c[i]=='*'){
					b=b*a[i+1];
					i+=1;
				}
				else{
					b=b/a[i+1];
					i+=1;
				}
			}
			m=b;
			i=i-1;
		}
	}
	printf("%d",m);
	return 0;
}

