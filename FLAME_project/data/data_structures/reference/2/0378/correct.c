#include <stdio.h>
#include <stdlib.h>
char a[100000];
char s[100000];
int n[100000];
char m[100000];
int main()
{
	gets(a);
	int i=0,j=0;
	for(;a[i]!='=';i++){
		if(a[i]!=' '){
			s[j++]=a[i];
		}
	}
	int p=0,q=0;
 	for(i=0;i<j;i++)
 	{
  		if(s[i]>='0'&&s[i]<='9')
  		{
   			n[p]=s[i]-'0';
   			i++;
   			while(s[i]>='0'&&s[i]<='9')
   			{
    			n[p]=n[p]*10+s[i]-'0';
    			i++;
   			}
   			i--;
   			p++;
  		}
  		else
  		{
    		m[q]=s[i];
    		q++;
    	}
 	}
 	for(i=0;i<q;i++){
 		if(m[i]=='-'){
 			n[i+1]=-n[i+1];
		}
	}
	for(i=0;i<q;i++){
		if(m[i]=='*'){
			n[i+1]=n[i]*n[i+1];
			n[i]=0;
		}else if(m[i]=='/'){
			n[i+1]=n[i]/n[i+1];
			n[i]=0; 
		}	
	}
	int sum=0;
	for(i=0;i<p;i++){
		sum+=n[i];
	}
	printf("%d",sum);
	return 0;
}

