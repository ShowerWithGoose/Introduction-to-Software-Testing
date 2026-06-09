#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
	char a[1001],b[1001];
	gets(a);
	int i,m=0;
	for(i=0;i<strlen(a);i++){
	if(!isspace(a[i]))
	{
		b[m]=a[i];
		m++;
	}
    }
    int n[1001]={0},j=0,k=0;
    char f[1001]="\0";
    for(i=0;i<strlen(b);i++)
    {
    	if(b[i]>='0'&&b[i]<='9')
    	{
    		for(i;b[i]>='0'&&b[i]<='9';i++)
			n[j]=n[j]*10+b[i]-'0';
			j++;
			i--;
		}
		else {
		f[k]=b[i];
		k++;}
	}
	int flag=-1;
	for(i=0;i<strlen(f);i++)
	{
			if(f[i]=='*'){
				n[i+1]=n[i]*n[i+1];
				n[i]=flag;
			}
			else if(f[i]=='/'){
				n[i+1]=n[i]/n[i+1];
				n[i]=flag;
			}
    }
    j=0;
    k=0;
    int N[1001]={0},sum=0;
    char F[1001]="\0";
	for(i=0;i<strlen(b);i++){
			if(n[i]!=flag)
			N[j++]=n[i];
			if(f[i]=='+'||f[i]=='-') 
			F[k++]=f[i];
		}
		sum=N[0];
	for(i=0;i<strlen(F);i++){
			if(F[i]=='+') 
			sum=sum+N[i+1];
			else 
			sum=sum-N[i+1];
		}
		printf("%d\n",sum);
		return 0;
 } 



