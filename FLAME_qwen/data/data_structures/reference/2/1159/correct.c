#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
char a[10000],c[10000];
int i,j,k,l,ls,temp,b[10000],flag;
int main()
{
	gets(a);
	ls=strlen(a);
	for(i=0;i<ls;i++){
		if(a[i]==' ')
		continue;
		if(a[i]>='0'&&a[i]<='9')
			temp=temp*10+a[i]-'0';
		else{
			if(b[j]!=0);
			else{
				b[j]=temp;
			}
			
			temp=0;
			j++;
			k=i+1;
			while(a[k]!='+'&&a[k]!='-'&&a[k]!='*'&&a[k]!='/'&&a[k]!='='&&k<ls){
				if(a[k]==' '){
					k++;
					flag++;	
					continue;
				
				}
					
				if(a[k]>='0'&&a[k]<='9'){
					temp=temp*10+a[k]-'0';
					
					k++;
				}
				flag++;	
			}
			if(a[i]=='*'){
				j--;
				b[j]=b[j]*temp;
				i+=flag;

			}
			if(a[i]=='/'){
				
				j--;
				b[j]=b[j]/temp;				
				i+=flag;

			}
			temp=0;
			flag=0;
			if(a[i]=='+'||a[i]=='-'){
				c[l]=a[i];
				l++;
			}
		}
	}
	temp=b[0];
	for(i=0;i<j;i++){
		if(c[i]=='+'){
			temp+=b[i+1];
		
		}
		if(c[i]=='-'){
			temp-=b[i+1];
		}
		
	}
	printf("%d",temp);	
return 0;
}


